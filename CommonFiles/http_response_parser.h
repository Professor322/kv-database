//
// Created by professor on 25.03.20.
//

#pragma once

#include <string>
#include <sstream>

#define OK_MSG "200 OK"
#define KEY_EXISTS_MSG "409 KEY_EXISTS"
#define NO_KEY_MSG "404 NO_KEY"
#define INCOR_BODY_MSG "400 INCORRECT_BODY"
#define INCOR_REQ_MSG "400 INCORRECT_REQUEST"

enum StatusCodes {
	OK = 200,
	NOT_FOUND = 409,
	NO_KEY = 404,
	INCORRECT_BODY = 400
};

struct Status {
	StatusCodes status;

	Status(){}
	Status(const std::string& status);
	std::string to_String() const;
};

class http_response_parser {
private:
	Status status;
	std::string reason_phrase;
	std::string header;
	std::string body;
public:
	http_response_parser(){}
	http_response_parser(const Status& status);
	http_response_parser(const Status& status, const std::string& reason_phrase);
	http_response_parser(const Status& status, const std::string& reason_phrase,
							const std::string& header);
	http_response_parser(const Status& status, const std::string& reason_phrase,
						 const std::string& header, const std::string& body);
	void setStatus(const Status& status);
	Status getStatus() const;

	void setReasonPhrase(const std::string& reason_phrase);
	std::string getReasonPhrase() const;

	void setHeader(const std::string& header);
	std::string getHeader() const;

	void setBody(const std::string& body);
	std::string getBody() const;

	std::string to_String() const;
	~http_response_parser(){}
};

std::istream& operator>>(std::istream& is, http_response_parser& response);
