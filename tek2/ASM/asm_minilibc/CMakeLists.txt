cmake_minimum_required(VERSION 3.6)
project(asm_minilibc)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)


#set(SOURCE_FILES)
#add_executable(asm_minilibc ${SOURCE_FILES})

add_subdirectory(Tests)

add_definitions(-W -Wall -Wextra -Werror)