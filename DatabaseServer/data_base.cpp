//
// Created by professor on 20.03.20.
//

#include "data_base.h"

void DataBase::postElem() {
	db[q.data_container].postElem(q.key, q.val);
}

void DataBase::putElem() {
	db[q.data_container].putElem(q.key, q.val);
}

void DataBase::getElem() const {
	if (!db.count(q.data_container)) {
		///throw exception 404
	}
	db.at(q.data_container).getElem(q.key);
}

void DataBase::deleteElem() {
	if (!db.count(q.data_container)) {
		///throw exception 404
	}
	db[q.data_container].deleteElem(q.key);

}