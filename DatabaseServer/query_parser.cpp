//
// Created by professor on 21.03.20.
//
#include "data_base.h"

std::smatch getRegex(const std::string& to_parse, const char *expression) {
	if (to_parse.empty()) {
		throw std::runtime_error("No command to parse");
	}
	std::regex reg(expression);
	std::smatch match;

	std::regex_search(to_parse, match, reg);
	return match;
}

std::string getDataContainer(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	std::string data_container;

	if (type == QueryType::POST) {
		match = getRegex(to_parse, REG_POST_DATA_CONTAINER);
		if (match.empty()) {
			///throw exception
		}
		std::stringstream ss(match[0].str());
		ss.get();
		ss >> data_container;
	} else {
		match = getRegex(to_parse, REG_DATA_CONTAINER);
		if (match.empty()) {
			///throw exception
		}
		data_container = match[0].str();
	}
	return data_container;
}

std::string getID(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	if (type == QueryType::PUT) {
		match = getRegex(to_parse, REG_PUT_ID);
	} else {
		match = getRegex(to_parse, REG_ID);
	}
	if (match.empty()) {
		throw std::runtime_error("Wrong syntax");
	}
	size_t begin = match[0].str().find_first_of('{') + 1;
	size_t end = match[0].str().find_last_of('}') - 1;
	return match[0].str().substr(begin, end - begin + 1);
}

std::string	getKey(const QueryType& type, const std::string& to_parse) {
	std::smatch match = getRegex(to_parse, REG_POST_KEY);

	if (match.empty()) {
		///throw exception
	}
	size_t begin = match[0].str().find_first_of('\"') + 1;
	size_t end = match[0].str().find_last_of('\"') - 1;

	return match[0].str().substr(begin, end - begin + 1);
}

Json::Value getValue(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	std::string to_stream;
	Json::Value root;

	if (type == QueryType::POST) {
		match = getRegex(to_parse, REG_POST_VALUE);
	} else if (type == QueryType::PUT) {
		match = getRegex(to_parse, REG_PUT_VALUE);

	}
	if (match.empty()) {
		///throw exception
	}
	to_stream = match[0].str();

	if (type == QueryType::PUT)
		to_stream.erase(to_stream.begin());

	size_t begin = to_stream.find_first_of('{');
	size_t end = to_stream.find_last_of('}');

	std::istringstream is(to_stream.substr(begin, end - begin + 1));

	is >> root;
	return root;
}
