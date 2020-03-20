//
// Created by professor on 20.03.20.
//

#include <json.h>
#include <fstream>
#include <string>
#include <iostream>


int 	main(int argc, char *argv[]) {
	std::ifstream input(argv[1], std::ifstream::in);
	Json::Value root;
	Json::Reader reader;
	if (!input.is_open()) {
		std::cout << "no file" << std::endl;
		return 0;
	}
	reader.parse(input, root);
	std::cout << root  << std::endl;
	std::cout << root["book"].asString() << std::endl;
	std::cout << root["year"].asUInt() << std::endl;
	const Json::Value& chars = root["characters"];
	for (const auto& chr : chars) {
		std::cout << chr["name"].asString() << std::endl;
		std::cout << chr["chapter"].asString() << std::endl;
		std::cout << std::endl;
	}
	input.close();
	return 0;
}