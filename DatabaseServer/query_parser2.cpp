//
// Created by professor on 20.03.20.
//

#include "data_base.h"


static void parsePostAndGet(const std::string& to_parse, Query& q) {
	q.data_container = getDataContainer(q.type, to_parse);
	q.key = q.type == QueryType ::POST ?
			getKey(q.type, to_parse) : getID(q.type, to_parse);
	q.val = getValue(q.type, to_parse);
}


static void parseGetAndDelete(const std::string& to_parse, Query& q) {
	q.data_container = getDataContainer(q.type, to_parse);
	q.key = getID(q.type, to_parse);
}

void parseQuery(std::stringstream& ss, Query& q) {
	std::string token;

	ss >> token;

	std::string to_parse(ss.str());

	if (token == "POST") {
		q.type = QueryType::POST;
		parsePostAndGet(to_parse, q);
	} else if (token == "PUT") {
		q.type = QueryType::PUT;
		parsePostAndGet(to_parse, q);
	} else if (token == "GET") {
		q.type = QueryType::GET;
		parseGetAndDelete(to_parse, q);
	} else if (token == "DELETE") {
		q.type = QueryType::DELETE;
		parseGetAndDelete(to_parse, q);
	} else if (token == "QUIT") {
		q.type = QueryType::QUIT;
	} else {
		q.type = QueryType::HELP;
	}
}