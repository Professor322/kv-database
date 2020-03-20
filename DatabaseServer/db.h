//
// Created by professor on 20.03.20.
//

#pragma once

#include <json.h>
#include <string>
#include <unordered_map>
#include <iostream>

///interface
class DataBase {
private:
	std::unordered_map<std::string, Json::Value> db;
public:
	///constructor is going to upload data from log file
	DataBase();
	void postElem(const std::string& key, const Json::Value& val);
	void putElem(const std::string& key, const Json::Value& val);
	void getElem(const std::string& key) const;
	void deleteElem(const std::string& key);
	~DataBase();
};

