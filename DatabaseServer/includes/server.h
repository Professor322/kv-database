//
// Created by professor on 23.03.20.
//

#pragma once

#include "data_base.h"

#define BUFF_SIZE 256

class Server {
private:
	int serverfd, port, queue_size, clientfd;
	in_addr ip;
	sockaddr_in server_address;
public:
	explicit	Server(const char* address, const int& port, const int& queue_size = 1);
	std::string	recieveRequest();
	void 		sendAnswer(const std::string& answer);
	void 		closeClientSocket();
	~Server();
};