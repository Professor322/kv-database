//
// Created by professor on 23.03.20.
//
#include "../includes/data_base.h"

Server::Server(const char *address, const int &port, const int& queue_size) {
				/**creating a socket*/
	this->serverfd = socket(AF_INET, SOCK_STREAM, 0);

	if (this->serverfd == -1) {
		throw std::runtime_error("Socket init failed");
	}
	this->queue_size = queue_size;
	/**before binding we need to fill struct sockaddr_in*/
	this->port = port;

	this->server_address.sin_family = AF_INET;

	///since we using intel processor we need to convert from "little endian" to "big endian"

	///setting server port
	/// htons host to network short
	this->server_address.sin_port = htons(this->port);

	///setting server ip
	///converting dot representaion ip to in_addr
	inet_aton(address, &this->ip);

	///htonl host to network long
	this->server_address.sin_addr.s_addr = htonl(this->ip.s_addr);

	/**bind ip to the socket**/
	if (bind(this->serverfd, (sockaddr*)&this->server_address, sizeof(this->server_address))) {
		throw std::runtime_error("Binding failed");
	}

	/**start listening**/
	listen(this->serverfd, this->queue_size);
}

std::string 	Server::recieveRequest() {
	this->clientfd = accept(this->serverfd, nullptr, nullptr);

	if (this->clientfd == -1) {
		throw std::runtime_error("Client acception error");
	}
	int size;
	char buff[BUFF_SIZE];

	std::string request;

	///no flags that is why 4th argument is set to 0
	while ((size = recv(this->clientfd, &buff, BUFF_SIZE, 0)) > 0) {
		request.append(buff, size);
	}
	return request;
}

void Server::sendAnswer(const std::string& answer) {
	send(this->clientfd, answer.c_str(), answer.size(), 0);
}

void Server::closeClientSocket() {
	close(this->clientfd);
}