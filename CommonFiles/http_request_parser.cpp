//
// Created by professor on 25.03.20.
//

#include "http_request_parser.h"

std::string Methods::to_String() const {
	switch (this->request) {
		case POST: return "POST";
		case PUT: return "PUT";
		case GET: return "GET";
		case DELETE: return "DELETE";
	}
	return {};
}

Methods::Methods(const std::string &req) {
	if (req == "POST") {
		this->request = POST;
	} else if (req == "PUT") {
		this->request = PUT;
	} else if (req == "GET") {
		this->request = GET;
	} else if (req == "DELETE") {
		this->request = DELETE;
	}
}


http_request_parser::http_request_parser(const Requests &method) {
	this->method.request = method;
}

http_request_parser::http_request_parser(const Requests &method, const std::string &uri) {
	this->method.request = method;
	this->uri = uri;
}

http_request_parser::http_request_parser(const Requests &method, const std::string &uri, const std::string& body) {
	this->method.request = method;
	this->uri = uri;
	this->body = body;
}


http_request_parser::http_request_parser(std::istream& is) {
	std::string buff;

	is >> buff;
	this->method = Methods(buff);

	is >> buff;
	this->uri = buff;

	Requests method = this->method.request;
	if (method == POST || method == PUT) {
		///skip 'body:'
		is >> buff;

		std::string body;
		getline(is, body);

		this->body = body;
	}
}

std::string http_request_parser::to_String() const{
	std::stringstream http_req;

	http_req << this->method.to_String() << " " << this->uri << " HTTP/1.1\r\n";
	http_req << "\r\n";
	http_req << this->body << "\r\n";
	return http_req.str();
}

void http_request_parser::setMethod(const Methods &method) {
	this->method = method;
}

void http_request_parser::setUri(const std::string& uri) {
	this->uri = uri;
}

void http_request_parser::setBody(const std::string &body) {
	this->body = body;
}

Methods http_request_parser::getMethod() const {
	return this->method;
}

std::string http_request_parser::getBody() const {
	return this->body;
}

std::string http_request_parser::getUri() const {
	return this->uri;
}

std::istream& operator >> (std::istream& is, http_request_parser& req) {

	std::string buff;

	getline(is, buff);

	std::stringstream ss(buff);
	std::string val;

	ss >> val;
	req.setMethod(Methods(val));

	ss >> val;
	req.setUri(val);

	///skip HTTP/1.1
	ss >> val;

	Methods request = req.getMethod();

	if (request.request == POST || request.request == PUT) {
		///skip blank line
		getline(is, buff);

		getline(is, buff);
		req.setBody(buff);
	}
	return is;
}