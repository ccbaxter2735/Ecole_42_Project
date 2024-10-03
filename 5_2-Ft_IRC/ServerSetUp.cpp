#include "Server.hpp"

volatile std::sig_atomic_t g_terminate = 0;

// constrctors
Server::Server(int port, const std::string& pass) : password(pass), oper_password("Magic"), SendBuffer("") {
    time(&RawTime);
	TimeInfo = localtime(&RawTime);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        throw std::runtime_error("Error opening socket");
    }

    setupSocketOptions(server_fd);

    if (set_non_blocking(server_fd) == -1) {
        throw std::runtime_error("Failed to set server socket to non-blocking");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        throw std::runtime_error("Error on binding");
    }

    listen(server_fd, 5);

    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
       throw std::runtime_error("Error creating epoll instance");
    }

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev) == -1) {
        throw std::runtime_error("Error adding fd to epoll");
    }
}

Server::~Server()
{
	close(server_fd);
	close(epoll_fd);
}

int Server::set_non_blocking(int fd) {
    return fcntl(fd, F_SETFL, O_NONBLOCK);
}

void Server::setupSocketOptions(int sockfd) {
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        std::perror("setsockopt(SO_REUSEADDR) failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void Server::run() {
    struct epoll_event events[MAX_EVENTS];
    while (true) {
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            std::cerr << "Epoll wait error" << std::endl;
            if(g_terminate)
                break;
            else
                continue;
        }
        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == server_fd) {
                socklen_t client_len = sizeof(struct sockaddr_in);
                struct sockaddr_in client_addr;
                int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
                if (client_fd < 0) {
                    std::cerr << "Error on accept" << std::endl;
                    continue;
                }

                set_non_blocking(client_fd);
                struct epoll_event ev;
                ev.events = EPOLLIN;
                ev.data.fd = client_fd;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev);
                client_buffers[client_fd] = "";

                _clients[client_fd] = Client(client_fd);

                sendMsg("* :Welcome! You have connect to the EPIC IRC server.\r\n", client_fd);
                sendMsg("* :This server is private, so we are expecting the password before entering...\r\n", client_fd);
                sendMsg(":\r\n", client_fd);
                sendMsg(": *** Please use the PASS command to enter the server password.\r\n", client_fd);
                sendMsg(": *** After that, use the NICK and USER commands to complete your registration.\r\n", client_fd);
                sendMsg(": *** Example:\r\n", client_fd);
                sendMsg(": ***   PASS yourpassword\r\n", client_fd);
                sendMsg(": ***   NICK yournickname\r\n", client_fd);
                sendMsg(": ***   USER username 0 * :Real Name\r\n", client_fd);

                std::cout << "Client connected: FD " << client_fd << std::endl;
            } else {
                int current_fd = events[n].data.fd;
                char buffer[BUFFER_SIZE];
                memset(buffer, 0, BUFFER_SIZE);
                ssize_t count = read(current_fd, buffer, BUFFER_SIZE - 1);

                if (count < 0) {
                    std::cerr << "Read error on FD " << current_fd << std::endl;
                    close(current_fd);
                    client_buffers.erase(current_fd);
                    _clients.erase(current_fd);
                } else if (count == 0) {
                    std::cout << "Client disconnected: FD " << current_fd << std::endl;
                    close(current_fd);
                    client_buffers.erase(current_fd);
                    _clients.erase(current_fd);
                } else {
                    buffer[count] = '\0';
                    client_buffers[current_fd].append(buffer);

                    size_t pos;
                    while ((pos = client_buffers[current_fd].find("\r\n")) != std::string::npos) {
                        if (pos > client_buffers[current_fd].size()) {
                            break;
                        }
                        std::string command = client_buffers[current_fd].substr(0, pos);
                        std::cout << "\033[1;34m[Client]\033[0m FD " << current_fd << " command: " << command << std::endl;
                        std::vector<std::string> cmdVector = parseCommand(command);

                        if (cmdVector.empty()) {
                            std::cout << "Invalid command from FD " << current_fd << std::endl;
                            processInvalidCommand(current_fd, "");
                        } else {
                            processCommand(current_fd, cmdVector);
                            //std::cout << "line: 304 :Processed command from FD " << current_fd << ": " << cmdVector[0] << std::endl;
                        }

                        if (pos + 2 > client_buffers[current_fd].size()) {
                            client_buffers[current_fd] = "";
                        } else {
                            client_buffers[current_fd] = client_buffers[current_fd].substr(pos + 2);
                        }
                    }

                    while ((pos = client_buffers[current_fd].find("\n")) != std::string::npos) {
                        if (pos > client_buffers[current_fd].size()) {
                            break;
                        }
                        std::string command = client_buffers[current_fd].substr(0, pos);
                        std::cout << "\033[1;34m[Client]\033[0m FD " << current_fd << " command: " << command << std::endl;
                        std::vector<std::string> cmdVector = parseCommand(command);

                        if (cmdVector.empty()) {
                            std::cout << "Invalid command from FD " << current_fd << std::endl;
                            processInvalidCommand(current_fd, "");
                        } else {
                            processCommand(current_fd, cmdVector);
                            //std::cout << "line: 304 :Processed command from FD " << current_fd << ": " << cmdVector[0] << std::endl;
                        }

                        if (pos + 1 > client_buffers[current_fd].size()) {
                            client_buffers[current_fd] = "";
                        } else {
                            client_buffers[current_fd] = client_buffers[current_fd].substr(pos + 1);
                        }
                    }
                }
            }
        }
    }
}

void	signal_handler(int signal)
{
	std::cout << "\nInterrupt signal (" << signal << ") received.\n" << std::endl;
	g_terminate = 1;
}