//
// Created by professor on 26.03.20.
//
#include "data_base.h"

void DataBase::addElem(const std::string &key, const Json::Value &val) {
	if (this->db.count(key)) {
		throw std::runtime_error(KEY_EXISTS_MSG);
	}
	this->db.insert({key, val});
}

void DataBase::changeElem(const std::string &key, const Json::Value& val) {
	if (!this->db.count(key)) {
		throw std::runtime_error(NO_KEY_MSG);
	}
	this->db[key] = val;
}

void DataBase::deleteElem(const std::string &key){
	if (!this->db.count(key)) {
		throw std::runtime_error(NO_KEY_MSG);
	}
	this->db.erase(key);
}

std::string DataBase::getElem(const std::string &key) const {
	if (!this->db.count(key)) {
		throw std::runtime_error(NO_KEY_MSG);
	}
	return "key: " + key + "value: " + this->db.at(key).toStyledString();
}
