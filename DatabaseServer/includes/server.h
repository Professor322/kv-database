//
// Created by professor on 23.03.20.
//

#pragma once

#include "data_base.h"

class Server {
private:
	int serverfd, port, queue_size, clientfd;
	in_addr ip;
	sockaddr_in server_address;
public:
	explicit Server(const char* address, const int& port, const int& queue_size = 1);
	void	recieveRequest();
	void 	sendAnswer();
	~Server();
};