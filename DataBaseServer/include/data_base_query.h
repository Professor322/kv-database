//
// Created by professor on 26.03.20.
//

#pragma once

#include "data_base.h"
#include <regex>
#include "../../CommonFiles/http_request_parser.h"

///to parse POST query
#define REG_POST_KEY "\\{\\s*key\\s*:\\s*\"[[:graph:]]+\","

///to parse other queries
#define REG_PUT_GET_DELETE_KEY "/\\{[[:graph:]]+\\}\\s*"
#define REG_POST_PUT_VALUE  "\"value\"\\s*:\\s*\\{.+\\}\\s*(?=\\})"

struct DataBaseQuery {
	http_request_parser request;
	std::string key;
	Json::Value value;
};

std::istream& operator>>(std::istream& is, DataBaseQuery& q);
std::string handle_request(const std::string& request);