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


std::string http_request_parser::to_String() const{
	std::stringstream http_req;

	http_req << this->method.to_String() << " " << this->uri << " HTTP/1.1\r\n";
	http_req << std::endl;
	http_req << this->body;
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

Requests http_request_parser::getMethod() const {
	return this->method.request;
}

std::istream& operator >> (std::istream& is, http_request_parser& req) {

	std::string buff;

	is >> buff;
	req.setMethod(Methods(buff));

	is >> buff;
	req.setUri(buff);

	Requests method = req.getMethod();
	if (method == POST || method == PUT) {
		///skip 'body:'
		is >> buff;

		std::string body;
		getline(is, body);

		req.setBody(body);
	}

	return is;
}