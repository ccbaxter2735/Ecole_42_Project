#include "Server.hpp"
#include "Channel.hpp"
#include "Client.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
        return 1;
    }
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    int port = atoi(argv[1]);
    std::string pw = argv[2];
    try {
        Server server(port, pw);
        while (!g_terminate)
            server.run();
        std::cout << "Server shutting down..." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}