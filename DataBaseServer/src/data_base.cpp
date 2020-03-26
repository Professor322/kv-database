//
// Created by professor on 26.03.20.
//
#include "../include/data_base.h"
#include <iostream>

DataBase::DataBase(const std::string& log_filename) {
	this->log.open(log_filename, std::ios_base::out | std::ios_base::in | std::ios_base::app);
	if (this->log.is_open()) {
		std::cout << "Log file is opened" << std::endl;
	}
}

DataBase::~DataBase() {
	if (this->log.is_open()) {
		this->log.close();
	}
}

void DataBase::logCommand(const std::string &command, const std::string &arg) {
	this->log << command + " " + arg << std::endl;
}

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
	return "key: " + key + ", value: " + this->db.at(key).toStyledString();
}
