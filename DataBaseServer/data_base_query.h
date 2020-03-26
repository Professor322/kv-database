//
// Created by professor on 26.03.20.
//

#pragma once

#include "data_base.h"
#include <regex>
#include "../http_request_parser.h"

///to parse POST query
#define REG_POST_KEY "\\{\\s*key\\s*:\\s*\"[[:graph:]]+\","
#define REG_POST_VALUE  "\"value\"\\s*:\\s*\\{.+\\}\\s*(?=\\})"

///to parse PUT
#define REG_PUT_KEY "/\\{[[:graph:]]+\\}\\s*(?=body:)"
///to parse GET and DELETE
#define REG_GET_DELETE_KEY "/\\{[[:graph:]]+\\}"

struct DataBaseQuery {
	http_request_parser request;
	std::string key;
	Json::Value value;
};

std::istream& operator>>(std::istream& is, DataBaseQuery& q);