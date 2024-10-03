#include "../Server.hpp"

void Server::ircPASS(int client_fd, const std::vector<std::string>& params) {
    if (params.size() > 1) {
        if (_clients.find(client_fd) != _clients.end()) {
            if (params[1] == password) {
                _clients[client_fd].setAuthed(true);
                SendBuffer = "\033[1;1;32mPassword accepted, authentication successful.\033[0m\r\n";
                sendToClient(client_fd,SendBuffer);
            } else {
                SendBuffer = "\033[1;1;31mPassword incorrect, authentication failed.\033[0m\r\n";
                sendToClient(client_fd,SendBuffer);
            }
        } else {
            SendBuffer = "Error: Client not found.\r\n";
            sendToClient(client_fd,SendBuffer);
        }
    } else {
        SendBuffer = "Error: PASS command requires a password.\r\n";
        sendToClient(client_fd,SendBuffer);
    }
}