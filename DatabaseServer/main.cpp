//
// Created by professor on 20.03.20.
//

#include "data_base.h"
#include "data_container.h"
#include "query.h"
#include <regex>

using namespace std;

int 	main() {


	string s = "/kv body: {key: \"test\", \"value\": {SOME ARBITRARY JSON} } ";
	regex e("key\\s*:\\s*\"[[:graph:]]+\"");

	regex b("\"value\"\\s*:\\s*\\{.+(?=\\})");
	smatch m;


	regex_search(s, m, b);

	cout << m[0] << endl;

	return 0;
}