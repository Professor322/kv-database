//
// Created by professor on 20.03.20.
//

#ifndef DB_DB_H
#define DB_DB_H

#include <json.h>
#include <string>
#include <unordered_map>

///interface
class DataBase {
private:
	std::unordered_map<std::string, Json::Value> db;
public:
	///constructor is going to upload data from log file
	DataBase();
	void post(const std::string& key, const Json::Value& val);
	void put(const std::string& key, const Json::Value& val);
	void get(const std::string& key) const;
	void delete_elem(const std::string& key);
	~DataBase();
};

#endif //DB_DB_H
