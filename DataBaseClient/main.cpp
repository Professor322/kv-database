#include <iostream>
#include <boost/asio.hpp>
#include "../CommonFiles/http_request_parser.h"

using namespace boost::asio;

int main(int argc, char* argv[])
{
	try
	{

		boost::asio::io_service io_service;


		ip::tcp::endpoint ep;

		switch (argc) {
			case 1: ep.address(ip::address::from_string(DEFAULT_ADDRESS)); ep.port(DEFAULT_PORT); break;
			case 2: ep.address(ip::address::from_string(argv[1])); ep.port(DEFAULT_PORT); break;
			case 3: ep.address(ip::address::from_string(argv[1])); ep.port(atoi(argv[2])); break;
			default: throw std::runtime_error("Wrong args");
		}

		for (;;) {
			ip::tcp::socket s(io_service);

			s.connect(ep);

			http_request_parser request(std::cin);

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