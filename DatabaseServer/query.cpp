//
// Created by professor on 20.03.20.
//

#include "query.h"
#include <sstream>
#include <regex>

///if syntax error throw exception
std::string commandPutDataContainer(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::string data_container;
	std::regex reg(REG_POST_DATA_CONTAINER);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}

	std::stringstream ss(match[0].str());

	ss.get();
	ss >> data_container;

	return data_container;
}

std::string commandPutKey(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::regex reg(REG_POST_KEY);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	size_t begin = match[0].str().find_first_of('\"') + 1;
	size_t end = match[0].str().find_last_of('\"') - 1;

	return match[0].str().substr(begin, end - begin + 1);
}

Json::Value commandPutVal(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	Json::Value root;
	std::regex reg(REG_POST_VALUE);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	size_t begin = match[0].str().find_first_of('{');
	size_t end = match[0].str().find_last_of('}');

	std::istringstream is(match[0].str().substr(begin, end - begin + 1));


	is >> root;


	return root;
}


void readQuery(std::stringstream& ss, Query& q) {
	std::string token;

	ss >> token;

	std::string to_parse(ss.str());

	if (token == "POST") {
		q.type = QueryType::POST;
		q.data_container = commandPutDataContainer(to_parse);
		q.key = commandPutKey(to_parse);
		q.val = commandPutVal(to_parse);
	} else if (token == "PUT") {
		q.type = QueryType::PUT;
		///get data_container
		///get key
		///get value
	} else if (token == "GET") {
		q.type = QueryType::GET;
		///get data_container
		///get key
	} else if (token == "DELETE") {
		q.type = QueryType::DELETE;
		///get data_container
		///get key
	} else {
		///help
	}
}