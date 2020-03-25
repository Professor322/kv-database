//
// Created by professor on 25.03.20.
//

#include "../http_request_parser.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace boost::asio;

int 	main() {

	http_request_parser req;

	/** creating io service object  for system communication **/
	io_service service;

/** creating an end point **/
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);


	/** creating socket **/
	ip::tcp::socket sock(service);

	/** connecting  to endpoint **/
//	sock.connect(ep);

	/** sending http request **/
	char buff[256];

	std::cin >> req;
	std::cout << req.to_String() << std::endl;
//	write(sock, buffer(req.to_String()));

//	size_t len = sock.read_some(buffer(buff));
//	std::string msg(buff, len);
//	std::cout <<  msg << std::endl;

	return 0;
}