cmake_minimum_required(VERSION 3.7)
project(database_client_server)

list(APPEND CMAKE_PREFIX_PATH
        "/home/professor/Desktop/vcpkg/packages/cpprestsdk_x64-linux/share/cpprestsdk")

find_package(cpprestsdk CONFIG REQUIRED)


include_directories(./jsoncpplib/includes)

add_executable(server DataBaseServer/main.cpp
        CommonFiles/http_response_parser.h
        CommonFiles/http_response_parser.cpp
        CommonFiles/http_request_parser.h
        CommonFiles/http_request_parser.cpp
        DataBaseServer/data_base.h
        DataBaseServer/data_base.cpp
        DataBaseServer/data_base_query.cpp DataBaseServer/data_base_query.h DataBaseServer/handle_request.cpp)

add_executable(client DataBaseClient/main.cpp CommonFiles/http_request_parser.h CommonFiles/http_request_parser.cpp)

target_link_libraries(server PRIVATE cpprestsdk::cpprest
    cpprestsdk::cpprestsdk_zlib_internal
       cpprestsdk::cpprestsdk_boost_internal
        cpprestsdk::cpprestsdk_openssl_internal)

target_link_libraries(client PRIVATE cpprestsdk::cpprest
        cpprestsdk::cpprestsdk_zlib_internal
        cpprestsdk::cpprestsdk_boost_internal
        cpprestsdk::cpprestsdk_openssl_internal)