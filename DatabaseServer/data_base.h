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
	Query q;

	void help();
	void postElem();
	void putElem();
	void getElem() const;
	void deleteElem();
};
