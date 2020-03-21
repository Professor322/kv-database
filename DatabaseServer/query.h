//
// Created by professor on 20.03.20.
//
#pragma once

///regex expressions for parsing

///to parse POST query
#define REG_POST_DATA_CONTAINER "/[[:graph:]]+\\s*(?=body:)"
#define REG_POST_KEY "\\{\\s*key\\s*:\\s*\"[[:graph:]]+\","
#define REG_POST_VALUE  "\"value\"\\s*:\\s*\\{.+\\}\\s*(?=\\})"

///to parse PUT
#define REG_PUT_VALUE "\\{\\s*\"value\"\\s*:\\s*\\{.+\\}\\s(?=\\})"
#define REG_PUT_ID "/\\{[[:graph:]]+\\}\\s*(?=body:)"
///to parse GET and DELETE
#define REG_DATA_CONTAINER "[[:graph:]]+(?=\\/)"
#define REG_ID "/\\{[[:graph:]]+\\}"

#include "data_container.h"

enum class QueryType {
	POST,
	PUT,
	GET,
	DELETE
};

struct Query {
	QueryType type;
	std::string data_container;
	std::string key;
	Json::Value val;
};

void readQuery(std::stringstream& ss, Query& q) ;
