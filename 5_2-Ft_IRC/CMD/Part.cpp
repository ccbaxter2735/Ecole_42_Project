#include "../Server.hpp"
#include "../Channel.hpp"

/*Need to parse params[1] when ',' is found*/

static bool    findComma(const std::string s){
        return s.find(',') != std::string::npos;
}

static std::vector<std::string> splitComma(const std::string &strWithComma){
        std::vector<std::string> res;
        size_t start;
        size_t end = 0;

        while ((start = strWithComma.find_first_not_of(',', end)) != std::string::npos){
                end = strWithComma.find(',', start);
                res.push_back(strWithComma.substr(start, end - start));
        }
        return res;
}

void    Server::ircPART(int client_fd, const std::vector<std::string> &params) {
        if (params.size() < 2) {
		sendError(client_fd, "461", " :Not enough parameters\r\n");
		return;
	}
        std::vector<std::string> ChannelNames;
        if (findComma(params[1]))
                ChannelNames = splitComma(params[1]);
        else
                ChannelNames.push_back(params[1]);
        for (size_t i = 0; i < ChannelNames.size(); ++i){
                if (!findChannelIntoServer(ChannelNames[i])){
                        SendBuffer = ERR_NOSUCHCHANNEL(_clients[client_fd].getNickname(), ChannelNames[i]);
                        sendToClient(client_fd, SendBuffer); 
                        continue;
                }
                std::vector<Channel>::iterator it;
                for (it = _channels.begin(); it != _channels.end(); ++it){
                        if (it->getName() != ChannelNames[i])
                                continue;
                        if (it->findnicknameIntoChannel(client_fd)) {
                                std::string tmp;
                                if (params.size() < 2)
                                        tmp = ":";
                                SendBuffer = RPL_PART(_clients[client_fd].getNickname(), _clients[client_fd].getUsername(), ChannelNames[i], tmp);
                                // std::cout << SendBuffer << std::endl;
                                sendToClient(client_fd,SendBuffer);
                                /*Need to clear client_fd from channel*/
                                it->removeClient(client_fd);
                                // std::cout << "client left " << ChannelNames[i] << std::endl;
                                it->ChannelBroadcast(SendBuffer);
                                if (it->getClientFds().size() == 0)
                                        it = _channels.erase(it);
                                break ;
                        } else {
                                SendBuffer = ERR_NOTONCHANNEL(_clients[client_fd].getNickname(), ChannelNames[i]);
                                sendToClient(client_fd, SendBuffer);
                                break ;
                        }     
                }
        }
}