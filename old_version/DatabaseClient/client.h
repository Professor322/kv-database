//
// Created by professor on 23.03.20.
//

#pragma once
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string>

#define BUFF_SIZE 3

class Client {
private:
	int server_socket, port;
	in_addr ip;
	sockaddr_in server_address;
public:
	explicit Client(const char *address, const int& port);
	std::string recieveAnswer();
	void sendRequest(const std::string& request);
	void closeConnection();
	~Client(){}
};