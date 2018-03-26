cmake_minimum_required(VERSION 3.9.6)
project(noByte)

set(CMAKE_CXX_STANDARD 17)

include_directories(. ../../api)

set(SOURCES_FILES NoByte.cpp NoByte.hpp)

add_library(nobyte SHARED ${SOURCES_FILES})