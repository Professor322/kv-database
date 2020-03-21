//
// Created by professor on 20.03.20.
//

#include "data_base.h"
#include "data_container.h"
#include "query.h"

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
		getline(std::cin, buff);
		std::stringstream ss(buff);
		readQuery(ss, db.q);
		std::cout << db.q << std::endl;
	return 0;
}