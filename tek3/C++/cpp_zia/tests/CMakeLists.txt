cmake_minimum_required(VERSION 3.9.6)
project(cpp_zia_tests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

include_directories(. ../zia_modules/ ${GTEST_INCLUDE_DIRS} ../server/include ../lib)

set(RESOURCE_FILES
        resources/index.php)

set(PARSE_SRCS)
set(PARSE_TESTS parser/ParserTest.cpp)

set(PHP_SRCS ../zia_modules/php-cgi/phpCgiModule.cpp ../zia_modules/php-cgi/Executer.cpp)
set(PHP_TESTS php-cgi/PhpCgiModuleTests.cpp)

add_executable(tests ${PHP_SRCS} ${PHP_TESTS} ${PARSE_SRCS} ${PARSE_TESTS} ../api/pp/conf.cpp)
target_link_libraries(tests GTest::GTest GTest::Main nobyte shared)

add_custom_command(TARGET tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:tests>)