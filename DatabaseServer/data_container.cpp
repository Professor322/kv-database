//
// Created by professor on 20.03.20.
//

#include "data_base.h"

///methods going to throw exception if something invalid happens

void DataContainer::postElem(const std::string &key, const Json::Value &val) {
	if (dc.count(key)) {
		///throw exception 409
	}
	dc[key] = val;
}

void DataContainer::putElem(const std::string &key, const Json::Value &val) {
	if (!dc.count(key)) {
		///throw exception 404
	}
	dc[key] = val;
}

void DataContainer::getElem(const std::string &key) const {
	if (!dc.count(key)) {
		///throw exception 404
	}
	///on first version of data base we are going to print it on std out
	std::cout << "key : " << key
	          << " value: " << dc.at(key) << std::endl;
	std::cout << std::endl;
}

void DataContainer::deleteElem(const std::string &key) {
	if (!dc.count(key)) {
		///throw exception 404
	}
	dc.erase(key);
}



