//
// Created by professor on 26.03.20.
//
#include "data_base.h"

void DataBase::addElem(const std::string &key, const Json::Value &val) {
	if (this->db.count(key)) {
		throw std::runtime_error("This key already exist");
	}
	this->db.insert({key, val});
}

void DataBase::changeElem(const std::string &key, const Json::Value& val) {
	if (!this->db.count(key)) {
		throw std::runtime_error("No such key");
	}
	this->db[key] = val;
}

void DataBase::deleteElem(const std::string &key){
	if (!this->db.count(key)) {
		throw std::runtime_error("No such key");
	}
	this->db.erase(key);
}

std::string DataBase::getElem(const std::string &key) const {
	if (!this->db.count(key)) {
		throw std::runtime_error("No such key");
	}
	return "key: " + key + "value: " + this->db.at(key).toStyledString();
}
