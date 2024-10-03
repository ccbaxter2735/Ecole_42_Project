#include "../Server.hpp"

void Server::ircUSER(int client_fd, const std::vector<std::string>& params) {
    if (params.size() >= 5) {
        if (_clients.find(client_fd) != _clients.end()) {

            bool isNewUser = (_clients[client_fd].getUsername().length() < 1);

            _clients[client_fd].setUsername(params[1]);
            _clients[client_fd].setHostname(params[3]);
            _clients[client_fd].setServername("EpicIRC");
            _clients[client_fd].setRealName(params[4].substr(1));

            SendBuffer = "\033[1;1;32mRegistration successful.\r\n";
            sendToClient(client_fd,SendBuffer);

            if (isNewUser) {
                SendBuffer = RPL_001(_clients[client_fd].getNickname(), _clients[client_fd].getUsername());
                sendToClient(client_fd, SendBuffer);
                SendBuffer = RPL_002(_clients[client_fd].getNickname(), _clients[client_fd].getHostname(), " 1.0");
                sendToClient(client_fd, SendBuffer);
                SendBuffer = RPL_003(_clients[client_fd].getNickname(), asctime(TimeInfo));
                sendToClient(client_fd, SendBuffer);
                SendBuffer = RPL_004(_clients[client_fd].getNickname(), "localhost ", " 1.0 ", "User_mod+o ", "Chan_mod+itkol ", "chan_param_mod");
                sendToClient(client_fd, SendBuffer);
                SendBuffer = RPL_005(_clients[client_fd].getNickname(), " NETWORK=EpicIRC MODES=5");
                sendToClient(client_fd, SendBuffer);
            }

            std::cout << "Registered " << params[1] << " at FD " << client_fd << std::endl;
            std::cout << "==Client info==" << std::endl;
            printClientStatus(client_fd);
        } else {
            SendBuffer = "Error: Client not found.\r\n";
            sendToClient(client_fd,SendBuffer);
        }
    } else {
        SendBuffer = "Error: USER command requires username, hostname, servername, and realname.\r\n";
        sendToClient(client_fd,SendBuffer);
    }
}