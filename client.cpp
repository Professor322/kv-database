//
// Created by professor on 19.03.20.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

#include <string>
#include <cstring>

#define PORT 54000

int 	main() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		std::cerr << "Socket creation failed" << std::endl;
	}
	sockaddr_in c_addr;
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);
	c_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (connect(sockfd, (sockaddr*)&c_addr, sizeof(c_addr)) == -1) {
		std::cerr << "Connection error" << std::endl;
	}


	while (true) {
		std::string message;
		std::cout << "Enter massage: " << std::endl;
		std::cin >> message;

		send(sockfd, message.c_str(), message.length(), 0);
	}
	return 0;
}