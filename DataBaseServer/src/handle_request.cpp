//
// Created by professor on 26.03.20.
//

#include "../include/data_base.h"

static std::string create_response(const std::string &what) {
	http_response_parser response;

	std::stringstream ss(what);
	std::string buff;

	ss >> buff;
	Status status(buff);
	response.setStatus(status);

	ss >> buff;
	response.setReasonPhrase(buff);

	buff.clear();
	copy(std::istreambuf_iterator<char>(ss),
		 std::istreambuf_iterator<char>(), std::back_inserter(buff));
	response.setBody(buff);
	return response.to_String();
}

std::string handle_request(const std::string& request) {
	try {
		DataBaseQuery q;
		std::stringstream ss(request);

		ss >> q;

		Requests req = q.request.getMethod().request;
		switch (req) {
			case POST: db.addElem(q.key, q.value); break;
			case PUT: db.changeElem(q.key, q.value); break;
			case GET: {
				db.logCommand(q.request.getMethod().to_String(), q.request.getUri());
				throw std::runtime_error(OK_MSG + db.getElem(q.key));
			}
			case DELETE: db.deleteElem(q.key); 	   break;
		}
		db.logCommand(q.request.getMethod().to_String(),
				q.request.getUri() + " " + q.request.getBody());
		throw std::runtime_error(OK_MSG);

	} catch (const std::runtime_error& r) {
		return  create_response(r.what());
	}
}