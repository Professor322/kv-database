//
// Created by professor on 25.03.20.
//

#include "http_response_parser.h"
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void 	client_session(socket_ptr sock) {

}

int 	main() {

	io_service service;

	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

	/** creating acceptor to accept connections **/
	ip::tcp::acceptor acc(service, ep);

	std::cout << "Staring server" << std::endl;
	while (true) {
		socket_ptr sock(new ip::tcp::socket(service));
		std::cout << "waiting for clients" << std::endl;
		acc.accept(*sock);
		std::cout << "accepting client" << std::endl;
		client_session(sock);


	}

	return 0;
}