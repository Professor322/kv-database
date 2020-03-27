cmake_minimum_required(VERSION 3.7)
project(database_client_server)


include_directories(libs/boost_system/include)
include_directories(libs/boost_thread/include)
include_directories(libs/jsoncpplib/include)

add_executable(server DataBaseServer/main.cpp
        CommonFiles/http_response_parser.h
        CommonFiles/http_response_parser.cpp
        CommonFiles/http_request_parser.h
        CommonFiles/http_request_parser.cpp
        DataBaseServer/include/data_base.h
        DataBaseServer/src/data_base.cpp
        DataBaseServer/src/data_base_query.cpp
        DataBaseServer/include/data_base_query.h
        DataBaseServer/src/handle_request.cpp)

add_executable(client DataBaseClient/main.cpp
        CommonFiles/http_request_parser.h
        CommonFiles/http_request_parser.cpp)

target_link_libraries(server
        ~/Desktop/kv-database/libs/jsoncpplib/libjsoncpp.a
        ~/Desktop/kv-database/libs/boost_system/libboost_system.a)

target_link_libraries(client
        ~/Desktop/kv-database/boost_system/libboost_system.a)