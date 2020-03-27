cmake_minimum_required(VERSION 3.7)
project(database_client_server)


find_package(Boost 1.65.1 COMPONENTS system )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(libs/jsoncpplib/include)
    include_directories(libs/jsoncpplib/)

    add_executable(client DataBaseClient/main.cpp
            CommonFiles/http_request_parser.h
            CommonFiles/http_request_parser.cpp)

    target_link_libraries(client ${Boost_LIBRARIES})

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

    target_link_libraries(server ${Boost_LIBRARIES} ~/kv-database/libs/jsoncpplib/libjsoncpp.a)
endif()


