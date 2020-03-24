cmake_minimum_required(VERSION 3.13)

project(db)

set(CMAKE_CXX_STANDARD 17)

include_directories(jsoncpplib/includes)

add_executable(client  DatabaseClient/main.cpp DatabaseClient/client.h DatabaseClient/client.cpp)

add_executable(db DatabaseServer/main.cpp
        DatabaseServer/includes/data_container.h
        DatabaseServer/src/data_container.cpp
        DatabaseServer/src/query_parser2.cpp
        DatabaseServer/src/data_base.cpp
        DatabaseServer/includes/data_base.h
        DatabaseServer/includes/query_parser.h DatabaseServer/src/query_parser.cpp DatabaseServer/includes/server.h DatabaseServer/src/server.cpp)
target_link_libraries(db ~/Desktop/kv-database/jsoncpplib/libjsoncpp.a)