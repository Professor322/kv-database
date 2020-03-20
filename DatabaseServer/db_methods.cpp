//
// Created by professor on 20.03.20.
//

#include "db.h"

///methods going to throw exception if something invalid happens

void DataBase::postElem(const std::string &key, const Json::Value &val) {
	if (db.count(key)) {
		///throw exception 409
	}
	db[key] = val;
}

void DataBase::putElem(const std::string &key, const Json::Value &val) {
	if (!db.count(key)) {
		///throw exception 404
	}
	db[key] = val;
}

void DataBase::getElem(const std::string &key) const {
	if (!db.count(key)) {
		///throw exception 404
	}
	///on first version of data base we are going to print it on std out
	std::cout << "key : " << key
	          << " value: " << db.at(key) << std::endl;
}

void DataBase::deleteElem(const std::string &key) {
	if (!db.count(key)) {
		///throw exception 404
	}
	db.erase(key);
}



