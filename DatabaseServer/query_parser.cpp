//
// Created by professor on 21.03.20.
//
#include "data_base.h"

bool getRegex(const std::string& to_parse, std::smatch& match,const char *expression) {
	if (to_parse.empty()) {
		throw std::runtime_error("No command to parse");
	}
	std::regex reg(expression);
	return regex_search(to_parse, match, reg);

}

std::string getDataContainer(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	std::string data_container;

	if (type == QueryType::POST) {
		if (!getRegex(to_parse, match, REG_POST_DATA_CONTAINER)) {
			throw std::runtime_error("Incorrect body: 404");
		}
		std::stringstream ss(match[0].str());
		ss.get();
		ss >> data_container;
	} else {
		if (!getRegex(to_parse, match, REG_DATA_CONTAINER)) {
			throw std::runtime_error("Incorrect body: 404");
		}
		data_container = match[0].str();
	}
	return data_container;
}

std::string getID(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	bool is_correct;
	if (type == QueryType::PUT) {
		is_correct = getRegex(to_parse, match,REG_PUT_ID);
	} else {
		is_correct = getRegex(to_parse, match,REG_ID);
	}
	if (!is_correct) {
		throw std::runtime_error("Incorrect ID syntax");
	}
	size_t begin = match[0].str().find_first_of('{') + 1;
	size_t end = match[0].str().find_last_of('}') - 1;
	return match[0].str().substr(begin, end - begin + 1);
}

std::string	getKey(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	if (!getRegex(to_parse, match, REG_POST_KEY)) {
		throw std::runtime_error("Incorrect body: 400");
	}

	size_t begin = match[0].str().find_first_of('\"') + 1;
	size_t end = match[0].str().find_last_of('\"') - 1;

	return match[0].str().substr(begin, end - begin + 1);
}

Json::Value getValue(const QueryType& type, const std::string& to_parse) {
	std::smatch match;
	std::string to_stream;
	Json::Value root;
	bool is_correct;

	if (type == QueryType::POST) {
		is_correct = getRegex(to_parse, match, REG_POST_VALUE);
	} else if (type == QueryType::PUT) {
		is_correct = getRegex(to_parse, match, REG_PUT_VALUE);
	}
	if (!is_correct) {
		throw std:: runtime_error("Incorrect body: 400");
	}
	to_stream = match[0].str();

	if (type == QueryType::PUT)
		to_stream.erase(to_stream.begin());

	size_t begin = to_stream.find_first_of('{');
	size_t end = to_stream.find_last_of('}');

	std::istringstream is(to_stream.substr(begin, end - begin + 1));

	try {
		is >> root;
	} catch (const std::exception& e){
		throw std::runtime_error("Incorrect body: 400");
	}
	return root;
}
