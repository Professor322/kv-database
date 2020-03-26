//
// Created by professor on 26.03.20.
//
#include "data_base_query.h"


static bool getRegex(const std::string& to_parse, std::smatch& match,const char *expression) {
	if (to_parse.empty()) {
		throw std::runtime_error("No command to parse");
	}
	std::regex reg(expression);
	return regex_search(to_parse, match, reg);
}

std::string findSubstr(const std::string& str, const size_t& first, const size_t& last) {
	return str.substr(first, last - first + 1);
}

void parsePost(const std::string&body, DataBaseQuery& q) {
	std::smatch match;
	std::string to_parse;

	if (!getRegex(body, match, REG_POST_KEY))
		throw std::runtime_error("Incorrect body");

	to_parse = match[0].str();
	q.key = findSubstr(to_parse,
			to_parse.find_first_of('\"') + 1,
			to_parse.find_last_of('\"') - 1);

	if (!getRegex(body, match, REG_POST_VALUE))
		throw std::runtime_error("Incorrect body");

	to_parse = match[0].str();
	std::istringstream is(findSubstr(to_parse,
			to_parse.find_first_of('{'),
			to_parse.find_last_of('}')));

	try {
		is >> q.value;
	} catch (const std::exception& e) {
		throw std::runtime_error("Incorrect body");
	}
}

void parsePut(const std::string& uri, const std::string& body, DataBaseQuery& q) {

}

void parseGetandDelete(const std::string& uri, DataBaseQuery& q) {

}


std::istream& operator>>(std::istream& is, DataBaseQuery& q) {

	is >> q.request;

	Requests request_type = q.request.getMethod();

	switch (request_type) {
		case POST: parsePost(q.request.getBody(), q); break;
		case PUT:
	}
	return is;
}


