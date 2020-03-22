//
// Created by professor on 20.03.20.
//

#include "data_base.h"

void DataBase::postElem(const Query& q) {
	db[q.data_container].postElem(q.key, q.val);
}

void DataBase::putElem(const Query& q) {
	db[q.data_container].putElem(q.key, q.val);
}

void DataBase::getElem(const Query& q) const {
	if (!db.count(q.data_container)) {
		///throw exception 404
	}
	db.at(q.data_container).getElem(q.key);
}

void DataBase::deleteElem(const Query& q) {
	if (!db.count(q.data_container)) {
		///throw exception 404
	}
	db[q.data_container].deleteElem(q.key);

}

void DataBase::help() {
	std::cout << "Vi tolko derzhites`" << std::endl;
}