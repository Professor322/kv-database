//
// Created by professor on 26.03.20.
//

#pragma once

#include <unordered_map>
#include <string>
#include <json.h>
#include "../CommonFiles/http_request_parser.h"
#include "../CommonFiles/http_response_parser.h"
#include "data_base_query.h"

class DataBase {
private:
	std::unordered_map<std::string, Json::Value> db;
public:
	DataBase() {}
	void addElem(const std::string& key, const Json::Value& val);
	void changeElem(const std::string& key, const Json::Value& val);
	std::string getElem(const std::string& key) const;
	void deleteElem(const std::string& key);
	~DataBase() {}

};

extern DataBase db;