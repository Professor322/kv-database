//
// Created by professor on 24.03.20.
//

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;

int		main() {
	auto fileStream = std::make_shared<ostream>();



	pplx::task<void> requestTask =
			fstream::open_ostream(U("result.html")).then([=](ostream outFile) {
				*fileStream = outFile;

				http_client client(U("http://www.bing.com"));
				uri_builder builder(U("/search"));
				builder.append_query(U("q"), U("hey"));
				return client.request(methods::GET, builder.to_string());
			})
			.then([=](http_response response) {
				printf("Received response status code: %u\n", response.status_code());

				return response.body().read_to_end(fileStream->streambuf());
			})
			.then([=](size_t) {
				return fileStream->close();
			});
	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
	return 0;
}