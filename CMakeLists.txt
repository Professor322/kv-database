cmake_minimum_required(VERSION 3.7)
project(server)

list(APPEND CMAKE_PREFIX_PATH
        "/home/professor/Desktop/vcpkg/packages/cpprestsdk_x64-linux/share/cpprestsdk")

find_package(cpprestsdk CONFIG REQUIRED)


add_executable(server DataBaseServer/main.cpp http_response_parser.h http_response_parser.cpp)
add_executable(client DataBaseClient/main.cpp new_version//http_request_parser.h http_request_parser.cpp)


target_link_libraries(server PRIVATE cpprestsdk::cpprest
    cpprestsdk::cpprestsdk_zlib_internal
       cpprestsdk::cpprestsdk_boost_internal
        cpprestsdk::cpprestsdk_openssl_internal)

target_link_libraries(client PRIVATE cpprestsdk::cpprest
        cpprestsdk::cpprestsdk_zlib_internal
        cpprestsdk::cpprestsdk_boost_internal
        cpprestsdk::cpprestsdk_openssl_internal)