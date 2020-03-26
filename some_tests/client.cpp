//
// Created by professor on 24.03.20.
//

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace boost::asio;
/** synchronous client using boost asio **/



int 	main(int argc, char *argv[]) {
	/** creating io service object  for system communication **/
	io_service service;

/** creating an end point **/
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);


	/** creating socket **/
	ip::tcp::socket sock(service);

	/** connecting  to endpoint **/
	sock.connect(ep);

	char buff[512] = {0};
	boost::system::error_code ignored_error;
	/** send info to server **/
	write(sock, buffer(buff));

	/** get the answer **/
	size_t len = sock.read_some(buffer(buff), ignored_error);
	std::string msg(buff, len);
	std::cout <<  msg << std::endl;

	return 0;
}
