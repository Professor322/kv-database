//
// Created by professor on 20.03.20.
//

#include "../includes/data_base.h"

std::istream& operator >> (std::istream& is, DataBase& db) {
	std::string buff;

	getline(is, buff);
	std::stringstream ss(buff);
	Query q;
	try {
		parseQuery(ss, q);
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
	return is;
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