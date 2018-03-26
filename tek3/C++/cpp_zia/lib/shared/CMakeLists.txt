cmake_minimum_required(VERSION 3.9.6)
project(shared)

set(CMAKE_CXX_STANDARD 17)

include_directories(. ../../api ..)

set(SOURCES_FILES RequestBuilder.cpp DataBuffer.cpp ResponseSerializer.cpp ResponseSerializer.hpp MessageParser.cpp MessageParser.hpp MessageData.hpp ResponseBuilder.cpp ResponseBuilder.hpp)

add_library(shared SHARED ${SOURCES_FILES})
target_link_libraries(shared nobyte)