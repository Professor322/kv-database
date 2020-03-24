//
// Created by professor on 23.03.20.
//
#include "client.h"

int 	main(int argc, char *argv[]) {
	Client client(argv[1], atoi(argv[2]));

	while (true) {
		std::string request;
		getline(std::cin, request);
		if (request == "QUIT") {
			client.closeConnection();
			break ;
		}
		client.sendRequest(request + '\n');
		std::string answer = client.recieveAnswer();
		if (!answer.empty() && answer != "\n")
			std::cout << answer;
	}
	return 0;
}