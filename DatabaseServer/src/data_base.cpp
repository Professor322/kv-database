//
// Created by professor on 20.03.20.
//

#include "../includes/data_base.h"

DataBase::DataBase(const char *log_filname) {
	logs.open(log_filname);
	if (logs.is_open()) {
		without_log = true;
		if (logs.is_open()) {
			while (logs >> *this);
		}
		logs.close();
	}
	logs.open(log_filname, std::ios_base::app);
	without_log = false;
}

DataBase::~DataBase() {
	logs.close();
}

std::istream& operator >> (std::istream& is, DataBase& db) {
	std::string buff;

	getline(is, buff);
	if (buff.empty()) {
		return is;
	}
	std::stringstream ss(buff);
	Query q;
	try {
		parseQuery(ss, q);
		db.setCurrentQuery(q.type);
		switch (q.type) {
			case QueryType::POST:
				db.postElem(q);
				break;
			case QueryType::PUT:
				db.putElem(q);
				break;
			case QueryType::GET:
				db.getElem(q);
				break;
			case QueryType::DELETE:
				db.deleteElem(q);
				break;
			case QueryType::QUIT:
				break;
			case QueryType::HELP:
				db.help();
				break;
		}
	} catch (const std::runtime_error& r) {
		std::cerr << r.what() << std::endl;
	}
	if ((q.type == QueryType::POST ||
		q.type == QueryType::PUT ||
		q.type == QueryType::POST) &&
		!db.getWithoutLog()) {
		db.logCommand(buff);
	}
	return is;
}

void DataBase::setCurrentQuery(const QueryType& type) {
	this->current_query = type;
}

QueryType DataBase::getCurrentQuery() const {
	return this->current_query;
}

bool DataBase::getWithoutLog() const {
	return this->without_log;
}

void DataBase::logCommand(const std::string &command) {
	this->logs << command << std::endl;
}

void DataBase::postElem(const Query& q) {
	db[q.data_container].postElem(q.key, q.val);
}

void DataBase::putElem(const Query& q) {
	db[q.data_container].putElem(q.key, q.val);
}

void DataBase::getElem(const Query& q) const {
	if (!db.count(q.data_container)) {
		throw std::runtime_error("No such Data Container: 404");
	}
	db.at(q.data_container).getElem(q.key);
}

void DataBase::deleteElem(const Query& q) {
	if (!db.count(q.data_container)) {
		throw std::runtime_error("No such Data Container: 404");
	}
	db[q.data_container].deleteElem(q.key);

}

void DataBase::help() {
	std::cout << "Vi tolko derzhites`" << std::endl;
}

