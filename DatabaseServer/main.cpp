//
// Created by professor on 20.03.20.
//

#include "data_base.h"


std::ostream& operator << (std::ostream& os, const Query& q) {
	os << static_cast<int>(q.type) << std::endl;
	os << q.data_container << std::endl;
	os << q.key << std::endl;
	os << q.val << std::endl;
	return os;
}

int 	main() {
	DataBase db;

	std::string buff;
	while (getline(std::cin, buff)) {
		std::stringstream ss(buff);
		try {
			parseQuery(ss, db.q);
			switch (db.q.type) {
				case QueryType::POST:
					db.postElem();
					break;
				case QueryType::PUT:
					db.putElem();
					break;
				case QueryType::GET:
					db.getElem();
					break;
				case QueryType::DELETE:
					db.deleteElem();
					break;
				case QueryType::QUIT:
					return 0;
				case QueryType ::HELP:
					db.help();
					break;
			}
		} catch (const std::runtime_error& r) {
			std::cerr << r.what() << std::endl;
		}
	}

	return 0;
}