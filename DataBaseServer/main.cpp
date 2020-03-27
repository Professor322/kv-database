

#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "include/data_base.h"

using namespace boost::asio;
using std::cout;
using std::endl;
using std::string;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

DataBase db(LOG_FILENAME);

void session(socket_ptr sock)
{
	try
	{
		cout << "Starting client session\n";
		for (;;)
		{
			char data[BUFFER_SIZE];

			boost::system::error_code error;
			cout  << "Reading request...\n";
			size_t length = sock->read_some(boost::asio::buffer(data), error);
			cout << "Finished reading\n";

			if (error == boost::asio::error::eof) {
				cout << "End of session\n\n";
				break;
			}
			else if (error)
				throw boost::system::system_error(error);

			string request(data, length);
			string response = handle_request(request);

			boost::asio::write(*sock, boost::asio::buffer(response, response.size()));
			cout << "Response is sent\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
}

void server(boost::asio::io_service& io_service, const std::string& address, unsigned short port)
{
	ip::tcp::acceptor a(io_service, ip::tcp::endpoint(ip::address::from_string(address), port));
	for (;;)
	{
		socket_ptr sock(new ip::tcp::socket(io_service));
		a.accept(*sock);
		session(sock);
	}
}

int main(int argc, char* argv[])
{
	try
	{

		boost::asio::io_service io_service;
		switch (argc) {
			case 1: server(io_service, DEFAULT_ADDRESS, DEFAULT_PORT); break;
			case 2: server(io_service, argv[1], DEFAULT_PORT); break;
			case 3: server(io_service, argv[1], atoi(argv[2]));
			default: throw std::runtime_error("Invalid args");
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}