#include "../Server.hpp"

void Server::ircWHO(int client_fd, const std::vector<std::string> &params) {
	if (params.size() < 2) {
		sendError(client_fd, "461", " :Not enough parameters /who #channelName needed\r\n");
		return;
	}
	std::string channelName = params[1];
	if (params[1][0] != '#' || !findChannelIntoServer(channelName)) {
		sendError(client_fd, "403", params[1] + " :Channel's name doesn't begin by # or is not in the server\r\n");
		return;
	}
	Channel *channelSelec = findChannelIntoServer(channelName);
	std::vector<int> listfd = channelSelec->getClientFds();
	for (std::vector<int>::iterator it = listfd.begin(); it != listfd.end(); ++it) {
		SendBuffer = (":localhost 352 " + GetClient(*it).getNickname() + " " + channelName + " ~" + GetClient(*it).getUsername() + " localhost localhost " + GetClient(*it).getNickname() + " H :0 " + GetClient(*it).getRealname() +"\r\n");
		sendToClient(client_fd,SendBuffer);
	}
	SendBuffer = (":localhost 315 " + _clients[client_fd].getNickname() + channelName + " :End of /WHO list.\r\n");
	sendToClient(client_fd,SendBuffer);
}