//
// Created by professor on 20.03.20.
//

#pragma once

#include "data_container.h"
#include "query.h"

class DataBase {
private:
	std::unordered_map<std::string, DataContainer> db;
public:
	Query q;


	void postElem();
	void putElem();
	void getElem() const;
	void deleteElem();
};
