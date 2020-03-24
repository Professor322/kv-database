cmake_minimum_required(VERSION 3.7)
project(main)

list(APPEND CMAKE_PREFIX_PATH
        "/home/professor/Desktop/vcpkg/packages/cpprestsdk_x64-linux/share/cpprestsdk")

find_package(cpprestsdk CONFIG REQUIRED)


add_executable(main ./new_version/some_tests/testing_networklib.cpp)

target_link_libraries(main PRIVATE cpprestsdk::cpprest
    cpprestsdk::cpprestsdk_zlib_internal
       cpprestsdk::cpprestsdk_boost_internal
        cpprestsdk::cpprestsdk_openssl_internal)
