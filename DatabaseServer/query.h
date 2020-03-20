//
// Created by professor on 20.03.20.
//
#pragma once

#define TO_PARSE_KEY "key\\s*:\\s*\"[[:graph:]]+\""
#define TO_PARSE_VAL "\"value\"\\s*:\\s*\\{.+(?=\\})"

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

std::istream& operator >> (std::istream& is, Query& q);
