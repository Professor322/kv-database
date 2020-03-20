//
// Created by professor on 20.03.20.
//
#pragma once

#include "db.h"

enum class QueryType {
	POST,
	PUT,
	GET,
	DELETE
};

struct Query {
	QueryType type;
	std::string key;
	Json::Value val;
};

std::istream& operator >> (std::istream& is, Query& q);
