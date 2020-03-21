//
// Created by professor on 20.03.20.
//

#include "query.h"
#include <sstream>
#include <regex>

///if syntax error throw exception
std::string commandPostDataContainer(const std::string& to_parse) {
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

std::string commandPostKey(const std::string& to_parse) {
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

Json::Value commandPostVal(const std::string& to_parse) {
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

std::string	commandPutDataContainer(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::string data_container;
	std::regex reg(REG_DATA_CONTAINER);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	return match[0].str();
}

std::string	commandPutID(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::regex reg(REG_PUT_ID);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	size_t begin = match[0].str().find_first_of('{') + 1;
	size_t end = match[0].str().find_last_of('}') - 1;

	return match[0].str().substr(begin, end - begin + 1);
}


Json::Value	commandPutVal(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	Json::Value root;
	std::regex reg(REG_PUT_VALUE);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}

	std::string temp = match[0].str();

	temp.erase(temp.begin());
	size_t begin = temp.find_first_of('{');
	size_t end = temp.find_last_of('}');

	std::istringstream is(temp.substr(begin, end - begin + 1));

	is >> root;
	return root;
}

std::string getDataContainer(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::regex reg(REG_DATA_CONTAINER);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	return match[0].str();
}

std::string getID(const std::string& to_parse) {
	if (to_parse.empty()) {
		///throw exception
	}

	std::regex reg(REG_ID);
	std::smatch match;

	std::regex_search(to_parse, match, reg);

	if (match.empty()) {
		///throw exception
	}
	size_t begin = match[0].str().find_first_of('{') + 1;
	size_t end = match[0].str().find_last_of('}') - 1;

	return match[0].str().substr(begin, end - begin + 1);
}


void readQuery(std::stringstream& ss, Query& q) {
	std::string token;

	ss >> token;

	std::string to_parse(ss.str());

	if (token == "POST") {
		q.type = QueryType::POST;
		q.data_container = commandPostDataContainer(to_parse);
		q.key = commandPostKey(to_parse);
		q.val = commandPostVal(to_parse);
	} else if (token == "PUT") {
		q.type = QueryType::PUT;
		q.data_container = commandPutDataContainer(to_parse);
		q.key = commandPutID(to_parse);
		q.val = commandPutVal(to_parse);
	} else if (token == "GET") {
		q.type = QueryType::GET;
		q.data_container = getDataContainer(to_parse);
		q.key = getID(to_parse);
	} else if (token == "DELETE") {
		q.type = QueryType::DELETE;
		q.data_container = getDataContainer(to_parse);
		q.key = getID(to_parse);
	} else {
		///help
	}
}