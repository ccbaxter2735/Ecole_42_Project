#include "../Server.hpp"

void Server::ircPONG(int client_fd, const std::vector<std::string> &params) {
        SendBuffer = RPL_PONG(params[1], _clients[client_fd].getNickname());
        sendToClient(client_fd,SendBuffer);
}