cmake_minimum_required(VERSION 3.7)
project(cpp_spider)

set(CMAKE_CXX_STANDARD 14)

if (UNIX)
    add_subdirectory(server)
endif()
if (WIN32)
    add_subdirectory(client)
endif()