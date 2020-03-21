//
// Created by professor on 20.03.20.
//

#pragma once


#include "data_base.h"

///interface
class DataContainer {
private:
	std::unordered_map<std::string, Json::Value> dc;
public:
	///constructor is going to upload data from log file

	void postElem(const std::string& key, const Json::Value& val);
	void putElem(const std::string& key, const Json::Value& val);
	void getElem(const std::string& key) const;
	void deleteElem(const std::string& key);

};

