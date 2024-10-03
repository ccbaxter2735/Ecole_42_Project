#include "../Server.hpp"

void Server::ircQUIT(int client_fd, const std::vector<std::string> &params) {
        if (params.size() == 1){
                std::string reason = ":leaving";
                SendBuffer = RPL_QUIT(reason);
                sendToClient(client_fd,SendBuffer);
        } else { 
                SendBuffer = RPL_QUIT(params[1]);
                sendToClient(client_fd,SendBuffer);
        }
        /*Close client socket*/
        close(client_fd);
        /*clear client_fd from server*/
        std::cout << "Erase FD" << client_fd << "...";
        _clients.erase(client_fd);
        std::cout << " Done." << std::endl;
}