//
// Created by professor on 21.03.20.
//

#pragma once

#include "old_version/DatabaseServer/includes/data_base.h"

///to parse POST query
#define REG_POST_DATA_CONTAINER "/[[:graph:]]+\\s*(?=body:)"
#define REG_POST_KEY "\\{\\s*key\\s*:\\s*\"[[:graph:]]+\","
#define REG_POST_VALUE  "\"value\"\\s*:\\s*\\{.+\\}\\s*(?=\\})"

///to parse PUT
#define REG_PUT_VALUE "\\{\\s*\"value\"\\s*:\\s*\\{.+\\}\\s*(?=\\})"
#define REG_PUT_ID "/\\{[[:graph:]]+\\}\\s*(?=body:)"
///to parse GET and DELETE
#define REG_DATA_CONTAINER "[[:graph:]]+(?=\\/)"
#define REG_ID "/\\{[[:graph:]]+\\}"

enum class QueryType {
	POST,
	PUT,
	GET,
	DELETE,
	HELP,
	QUIT
};

struct Query {
	QueryType type;
	std::string data_container;
	std::string key;
	Json::Value val;
};

std::string getDataContainer(const QueryType& type, const std::string& to_parse);
std::string getID(const QueryType& type, const std::string& to_parse);
std::string getKey(const QueryType& type, const std::string& to_parse);
Json::Value getValue(const QueryType& type, const std::string& to_parse);
std::smatch getRegex(const std::string& to_parse, const char* expression);

void parseQuery(std::stringstream& ss, Query& q);