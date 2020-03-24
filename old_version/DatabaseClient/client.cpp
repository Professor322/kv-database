//
// Created by professor on 23.03.20.
//

#include "client.h"

Client::Client(const char *address, const int &port) {
	this->server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (this->server_socket == -1) {
		throw std::runtime_error("Socket creation failed");
	}
	this->port = port;
	this->server_address.sin_family = AF_INET;
	this->server_address.sin_port = htons(this->port);

	inet_aton(address, &this->ip);

	this->server_address.sin_addr.s_addr = this->ip.s_addr;

	if (connect(this->server_socket, (sockaddr*)&this->server_address, sizeof(this->server_address)) == -1) {
		throw std::runtime_error("Connetction error");
	}
}

std::string Client::recieveAnswer() {
	int size;
	char buff[BUFF_SIZE];

	std::string answer;

	while ((size = recv(this->server_socket, &buff, BUFF_SIZE, 0)) > 0) {

		answer.append(buff, size);

		if (answer.find('\n') != std::string::npos)
			break ;
	}
	if (size == -1) {
		throw std::runtime_error("Bad socket");
	}
	return answer;
}

void Client::sendRequest(const std::string& request) {
	send(this->server_socket, request.c_str(), request.size(), 0);
}

void Client::closeConnection() {
	close(this->server_socket);
}