//
// Created by professor on 25.03.20.
//

#pragma once

#include <string>
#include <sstream>
#include <fstream>

#define BUFFER_SIZE 	1024
#define DEFAULT_ADDRESS "127.0.0.1"
#define DEFAULT_PORT	8001



enum Requests {
	POST,
	PUT,
	GET,
	DELETE
};

struct Methods {
	Requests request;

	std::string to_String() const;
	Methods(){};
	Methods(const std::string& req);
};

class http_request_parser {
private:
	Methods method;
	std::string uri;
	std::string body;
public:
	http_request_parser() {}
	http_request_parser(std::istream& is);
	http_request_parser(const Requests& method);
	http_request_parser(const Requests& method, const std::string& uri);
	http_request_parser(const Requests& method, const std::string& uri, const std::string& body);

	void 				setMethod(const Methods& method);
	Methods 			getMethod() const;
	void 				setUri(const std::string& uri);
	void 				setBody(const std::string& body);
	std::string 		getBody() const;
	std::string 		getUri() const;
	std::string 		to_String() const;
	~http_request_parser() {}
};

std::istream& operator >> (std::istream& is, http_request_parser& req);