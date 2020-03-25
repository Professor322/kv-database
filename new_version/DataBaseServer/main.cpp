//
// Created by professor on 25.03.20.
//


#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include "../http_response_parser.h"

int 	main() {

	//io_service service;

	//ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

	/** creating acceptor to accept connections **/
	//ip::tcp::acceptor acc(service, ep);

	//std::cout << "Staring server" << std::endl;

	http_response_parser response;
	std::string s = "HTTP/1.1 200 OK\r\n\r\nkey : key, value : val\nue\n";
	std::istringstream ss(s);
	std::cout << s << std::endl;
	ss >> response;
	std::cout << response.to_String();
	/*	while (true) {
		socket_ptr sock(new ip::tcp::socket(service));
		std::cout << "waiting for clients" << std::endl;
		acc.accept(*sock);
		std::cout << "accepting client" << std::endl;
		client_session(sock);


	}*/

	return 0;
}