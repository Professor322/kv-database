cmake_minimum_required(VERSION 3.13)

project(db)

set(CMAKE_CXX_STANDARD 17)

include_directories(jsoncpplib/includes)

add_executable(db DatabaseServer/main.cpp
        DatabaseServer/data_container.h
        DatabaseServer/data_container.cpp
        DatabaseServer/query_parser2.cpp
        ./DatabaseServer/data_base.cpp
        ./DatabaseServer/data_base.h
        DatabaseServer/query_parser.h DatabaseServer/query_parser.cpp)
target_link_libraries(db ~/Desktop/kv-database/jsoncpplib/libjsoncpp.a)