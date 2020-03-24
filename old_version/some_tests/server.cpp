//
// Created by professor on 19.03.20.
//
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 54000
#define QUEUE_SIZE 1

int		main() {
	///create socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		std::cerr << "Socket init failed" << std::endl;
		exit(0);
	}
	std::cout << "Socket created!" << std::endl;
	///bind socket to an address
	sockaddr_in s_addr;

	///init protocol`s family
	s_addr.sin_family = AF_INET;

	///setting port and reversing bits
	s_addr.sin_port = htons(PORT);

	///setting server ip and reversing bits
	s_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	///binding socket to address 127.0.0.1
	if (bind(sockfd, (struct sockaddr*)&s_addr, sizeof(s_addr))) {
		std::cerr << "Binding failed" << std::endl;
		exit(0);
	}
	std::cout << "Binding successfull!" << std::endl;
	listen(sockfd, QUEUE_SIZE);
	char buff[1024];
	int size = 0;
	///recieve while can
	while (true) {
		///null null if client address is not needed
		int client = accept(sockfd, nullptr, nullptr);
		if (client == -1) {
			std::cerr << "Client acception error" << std::endl;
			exit(0);
		}
		while ((size = recv(client, &buff, 1024, 0)) > 0) {
			write(0, buff, size);
		}
		close(client);
	}

	return 0;
}