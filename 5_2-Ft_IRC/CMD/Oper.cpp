#include "../Server.hpp"

void Server::ircOPER(int client_fd, const std::vector<std::string> &params){
    if (params.size() < 3){
        sendError(client_fd, "461", "OPER :Not enough parameters");
                return;
    } else {
        std::string target = params[1];
        if (_clients[client_fd].isGlobalOp() == true){
            SendBuffer = ERR_491(_clients[client_fd].getNickname());
            sendToClient(client_fd, SendBuffer);
        } else if (_clients[client_fd].getNickname() == target && params[2] == oper_password){
            _clients[client_fd].setGlobalOp(true);
            SendBuffer = RPL_OPER(_clients[client_fd].getNickname());
            sendToClient(client_fd, SendBuffer);
        } else if (_clients[client_fd].getNickname() != target && params[2] == oper_password){
            SendBuffer = ":localhost OPER :Cannot set operator privilege for other users\r\n";
            sendToClient(client_fd, SendBuffer);
        } else {
            SendBuffer = ERR_464(_clients[client_fd].getNickname());
            sendToClient(client_fd, SendBuffer);
        }
    }
}