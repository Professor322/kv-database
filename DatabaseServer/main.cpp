//
// Created by professor on 20.03.20.
//

#include "data_base.h"
#include "data_container.h"
#include "query.h"


using namespace std;

int 	main() {


	string s = "kv/{id} body: {\"value\": {\"characters\": [{\"name\": \"Jabberwock\", \"chapter\":1}]} }";

	regex a("/\\{[[:graph:]]+\\}\\s*(?=body:)");
	smatch m;

	regex_search(s, m, a);
	cout << m[0] << endl;
	/*while (regex_search(s, m, b)) {
		for (const auto& i : m) {
			cout << i << " ";
		}
		cout << endl;
		s = m.suffix().str();
	}*/
	return 0;
}