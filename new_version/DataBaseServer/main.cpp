//
// Created by professor on 25.03.20.
//


#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include "../http_response_parser.h"

using namespace boost::asio;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session(socket_ptr sock) {
	std::cout << "Handling client" << std::endl;
	while (true) {
		try {
			char data[256];
			http_response_parser response;
			std::string s = "HTTP/1.1 200 OK\r\n\r\nkey : key, value : val\nue\n";
			std::istringstream ss(s);
			ss >> response;
			size_t len = sock->read_some(buffer(data));
			if (len > 0) {
				write(*sock, buffer(response.to_String()));
				std::string request(data, len);

				std::cout << request << std::endl;
			}
		} catch (boost::system::system_error& e) {
			break ;
		}
	}
	std::cout << "Finished handling\n\n";
}

int 	main() {

	io_service service;

	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

	/** creating acceptor to accept connections **/
	ip::tcp::acceptor acc(service, ep);

	std::cout << "Staring server" << std::endl;

	http_response_parser response;
	std::string s = "HTTP/1.1 200 OK\r\n\r\nkey : key, value : val\nue\n";
	std::istringstream ss(s);
	std::cout << s << std::endl;
	ss >> response;
	std::cout << response.to_String();
	while (true) {
		socket_ptr sock(new ip::tcp::socket(service));
		std::cout << "waiting for clients" << std::endl;
		acc.accept(*sock);
		std::cout << "accepting client" << std::endl;
		client_session(sock);
	}

	return 0;
}