//
// Created by professor on 26.03.20.
//

#pragma once

#include <unordered_map>
#include <string>
#include <json.h>
#include <fstream>
#include "../../CommonFiles/http_request_parser.h"
#include "../../CommonFiles/http_response_parser.h"
#include "data_base_query.h"

#define LOG_FILENAME "./DataBaseServer/logs/logs.txt"

class DataBase {
private:
	std::unordered_map<std::string, Json::Value> db;
	std::fstream log;
public:
	explicit DataBase(const std::string& log_filename);
	void addElem(const std::string& key, const Json::Value& val);
	void changeElem(const std::string& key, const Json::Value& val);
	std::string getElem(const std::string& key) const;
	void deleteElem(const std::string& key);
	void logCommand(const std::string& command, const std::string& arg);
	~DataBase();

};

extern DataBase db;