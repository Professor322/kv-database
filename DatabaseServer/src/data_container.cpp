//
// Created by professor on 20.03.20.
//

#include "../includes/data_base.h"

///methods going to throw exception if something invalid happens

void DataContainer::postElem(const std::string &key, const Json::Value &val) {
	if (dc.count(key)) {
		throw std::runtime_error("Key already exist: 409");
	}
	dc[key] = val;
}

void DataContainer::putElem(const std::string &key, const Json::Value &val) {
	if (!dc.count(key)) {
		throw std::runtime_error("No such key: 404");
	}
	dc[key] = val;
}

void DataContainer::getElem(const std::string &key) const {
	if (!dc.count(key)) {
		throw std::runtime_error("No such key: 404");
	}
	std::cout << "key : " << key
	          << " value: " << dc.at(key) << std::endl;
}

void DataContainer::deleteElem(const std::string &key) {
	if (!dc.count(key)) {
		throw std::runtime_error("No such key: 404");
	}
	dc.erase(key);
}



