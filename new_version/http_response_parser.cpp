//
// Created by professor on 25.03.20.
//
#include "http_response_parser.h"

Status::Status(const std::string& status) {
	this->status = static_cast<StatusCodes>(std::stoi(status));
}

std::string Status::to_String() const {
	return std::to_string(this->status);
}

http_response_parser::http_response_parser(const Status &status){
	this->status = status;
}

http_response_parser::http_response_parser(const Status &status, const std::string &reason_phrase) {
	this->status = status;
	this->reason_phrase = reason_phrase;
}

http_response_parser::http_response_parser(const Status &status, const std::string &reason_phrase,
										   const std::string &header) {
	this->status = status;
	this->reason_phrase = reason_phrase;
	this->header = header;
}

http_response_parser::http_response_parser(const Status &status, const std::string &reason_phrase,
										   const std::string &header, const std::string& body) {
	this->status = status;
	this->reason_phrase = reason_phrase;
	this->header = header;
	this->body = body;
}

void http_response_parser::setBody(const std::string &body) {
	this->body = body;
}

std::string http_response_parser::getBody() const {
	return this->body;
}


void http_response_parser::setHeader(const std::string &header) {
	this->header = header;
}

std::string http_response_parser::getHeader() const {
	return this->header;
}

void http_response_parser::setReasonPhrase(const std::string &reason_phrase){
	this->reason_phrase = reason_phrase;
}

std::string http_response_parser::getReasonPhrase() const {
	return this->reason_phrase;
}


void http_response_parser::setStatus(const Status &status) {
	this->status = status;
}

Status http_response_parser::getStatus() const {
	return this->status;
}

std::string http_response_parser::to_String() const {
	std::stringstream response;

	response << "HTTP/1.1 " << this->status.to_String() << " " << this->reason_phrase + "\r\n";
	//response << header << "\r\n\r\n";
	response << "\r\n";
	response << body << "\r\n";

	return response.str();
}

std::istream& operator>>(std::istream& is, http_response_parser& response) {

	std::string buff;

	getline(is, buff);

	std::stringstream ss(buff);

	///skip HTTP/1.1
	ss >> buff;

	///status
	ss >> buff;
	Status status(buff);
	response.setStatus(status);

	///reason phrase
	std::string val;
	buff.clear();
	while (ss >> val)
		buff += val;
	response.setReasonPhrase(buff);

	///skip new line
	getline(is, buff);
	///body
	buff.clear();
	copy(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>(), std::back_inserter(val));
	response.setBody(buff);
	return is;
}