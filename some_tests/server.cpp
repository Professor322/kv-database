//
// Created by professor on 24.03.20.
//
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;

/**synchronous server using boost asio **/

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void client_session(socket_ptr socket) {
	std::cout << "Handling client" << std::endl;
	while (true) {
		try {
			char data[256];

			size_t len = socket->read_some(buffer(data));
			if (len > 0) {
				write(*socket, buffer("OK\nsup\n", 7));
				std::string request(data, len);

				std::cout << request << std::endl;
			}
		} catch (boost::system::system_error& e) {
			break ;
		}
	}
	std::cout << "Finished handling\n\n";
}


int 	main(int argc, char *argv[])
{
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

