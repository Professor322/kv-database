//
// Created by professor on 20.03.20.
//

#include "query.h"

///if syntax error throw exception


std::istream& operator >> (std::istream& is, Query& q) {
	std::string token;
	is >> token;
	if (token == "POST") {
		q.type = QueryType::POST;
		///get data_container
		///get key
		///get value
	} else if (token == "PUT") {
		q.type = QueryType::PUT;
		///get data_container
		///get key
		///get value
	} else if (token == "GET") {
		q.type = QueryType::GET;
		///get data_container
		///get key
	} else if (token == "DELETE") {
		q.type = QueryType::DELETE;
		///get data_container
		///get key
	} else {
		///help
	}
	return is;
}