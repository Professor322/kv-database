//
// Created by professor on 20.03.20.
//

#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	std::string token;
	is >> token;
	if (token == "POST") {
		q.type = QueryType::POST;
	} else if (token == "PUT") {
		q.type = QueryType::PUT;
	} else if (token == "GET") {
		q.type = QueryType::GET;
	} else if (token == "DELETE") {
		q.type = QueryType::DELETE;
	}
	return is;
}