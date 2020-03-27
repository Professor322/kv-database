#include <iostream>
#include "../CommonFiles/http_request_parser.h"
#include <boost/asio.hpp>

using namespace boost::asio;

int main(int argc, char* argv[])
{
	try
	{

		boost::asio::io_service io_service;


		ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

		for (;;) {
			ip::tcp::socket s(io_service);

			s.connect(ep);

			http_request_parser request(std::cin);
			std::cout << request.to_String() << std::endl;

			boost::asio::write(s, boost::asio::buffer(request.to_String(), request.to_String().size()));

			char reply[BUFFER_SIZE];

			size_t reply_length = s.read_some(boost::asio::buffer(reply));
			std::string response(reply, reply_length);
			std::cout << response << std::endl;

			s.close();
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}