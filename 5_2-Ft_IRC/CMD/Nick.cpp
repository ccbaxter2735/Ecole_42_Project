#include "../Server.hpp"

static bool CheckValidNick(const std::string name) {
    if (name.empty() || name[0] == '$' || name[0] == ':' || name[0] == '#')
        return false;
    const char InvalidChars[] = { ' ', ',', '*', '?', '!', '@', '.' };
    const size_t InvalidCharsSize = sizeof(InvalidChars) / sizeof(InvalidChars[0]);
    for (size_t i = 0; i < name.size(); ++i) {
        for (size_t j = 0; j < InvalidCharsSize; ++j) {
            if (name[i] == InvalidChars[j])
                return false;
        }
    }

    return true;
}

void Server::ircNICK(int client_fd, const std::vector<std::string> &params) {
    if (params.size() > 1) {
      std::string requestedNick = params[1];
      std::string actualNick = requestedNick;
      int suffix = 1;

			if (!CheckValidNick(params[1])){
				SendBuffer = ERR_ERRONEUSNICKNAME(_clients[client_fd].getNickname(), params[1]);
				sendToClient(client_fd, SendBuffer);
				return;
			}

      while (true) {
        bool nickIsUnique = true;
        for (std::map<int, Client>::iterator it = _clients.begin();
             it != _clients.end(); ++it) {
          if (it->second.getNickname() == actualNick &&
              client_fd != it->first) {
            std::ostringstream os;
            os << requestedNick << suffix++;
            actualNick = os.str();
            nickIsUnique = false;
            break;
          }
        }
        if (nickIsUnique) {
          break;
        }
      }

      std::string oldNick = _clients[client_fd].getNickname();
      _clients[client_fd].setNickname(actualNick);

      std::string userHost = _clients[client_fd].getUsername() + "@" +
                             _clients[client_fd].getHostname();
      std::string nickChangeMsg =
          ":" + oldNick + "!" + userHost + " NICK " + actualNick + "\r\n";
      send(client_fd, nickChangeMsg.c_str(), nickChangeMsg.length(), 0);
      std::vector<Channel *> ClientChans;
      if (!_channels.empty()){
        for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it){
          if (it->findnicknameIntoChannel(client_fd)){
            ClientChans.push_back(&(*it));
          }
        }
        if (!ClientChans.empty()){
        for (std::vector<Channel *>::iterator chIt = ClientChans.begin(); chIt != ClientChans.end(); ++chIt){
          Channel *channel = *chIt;
          for (std::map<int,Client>::iterator ClientIt = _clients.begin(); ClientIt != _clients.end(); ++ClientIt){
            if (channel->findnicknameIntoChannel(ClientIt->first) && ClientIt->first != client_fd){
              send(ClientIt->first, nickChangeMsg.c_str(), nickChangeMsg.length(), 0);
            }
          }
        }
        }
      }
    } else {
      sendError(client_fd, "431", ":No nickname given");
    }
}
