

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

using namespace boost::asio;

const int max_length = 1024;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
using std::cout;
using std::endl;
using std::string;

void session(socket_ptr sock)
{
	try
	{
		cout << "Starting client session\n";
		for (;;)
		{
			char data[max_length];

			boost::system::error_code error;
			cout  << "Reading request...\n";
			size_t length = sock->read_some(boost::asio::buffer(data), error);
			cout << "Finished reading\n";

			string msg(data, length);



			if (error == boost::asio::error::eof) {
				cout << "End of session\n\n";
				break; // Connection closed cleanly by peer.
			}
			else if (error)
				throw boost::system::system_error(error); // Some other error.

			boost::asio::write(*sock, boost::asio::buffer(msg, msg.size()));
			cout << "Response is sent\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
}

void server(boost::asio::io_service& io_service, unsigned short port)
{
	ip::tcp::acceptor a(io_service, ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), port));
	for (;;)
	{
		socket_ptr sock(new ip::tcp::socket(io_service));
		a.accept(*sock);
		boost::thread t(boost::bind(session, sock));
	}
}

int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_service io_service;

		server(io_service, 8001);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}