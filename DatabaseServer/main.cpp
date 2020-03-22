//
// Created by professor on 20.03.20.
//

#include "includes/data_base.h"

///for testing purposes
std::ostream& operator << (std::ostream& os, const Query& q) {
	os << static_cast<int>(q.type) << std::endl;
	os << q.data_container << std::endl;
	os << q.key << std::endl;
	os << q.val << std::endl;
	return os;
}

void testRegexReturnValue() {
	std::regex reg(REG_POST_KEY);

	std::string buff = "POST /kv body: {key: \"test\", \"value\" : { \"key\" : \"value\"}}";

	std::smatch m;

	std::cout <<std::regex_search(buff, m, reg) << std::endl;

}

int 	main(int argc, char *argv[]) {
	DataBase db(LOG_FILE);

	while (std::cin >> db) {
		if (db.getCurrentQuery() == QueryType::QUIT) {
			break;
		}
	}

	return 0;
}