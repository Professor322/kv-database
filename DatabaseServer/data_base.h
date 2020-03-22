//
// Created by professor on 20.03.20.
//

#pragma once

#include <json.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
#include <sstream>
#include <limits>
#include "data_container.h"
#include "query_parser.h"

class DataBase {
private:
	std::unordered_map<std::string, DataContainer> db;
public:
	void help();
	void postElem(const Query& q);
	void putElem(const Query& q);
	void getElem(const Query& q) const;
	void deleteElem(const Query& q);
};
