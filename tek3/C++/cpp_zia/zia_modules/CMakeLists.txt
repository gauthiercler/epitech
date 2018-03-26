cmake_minimum_required(VERSION 3.9.6)
project(zia_modules)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/)

include_directories(. ../lib/rnetwork ../lib)
set(COMMON Config.hpp)

set(API_SOURCES ${CMAKE_SOURCE_DIR}/api/pp/conf.cpp)
# Creation of shared library test module
set(TEST_SOURCES test/Test.cpp test/Test.hpp)
# Creation of shared library net module
set(NET_SOURCES net/Net.cpp
        net/Net.hpp
        net/Client.cpp
        net/Client.hpp)

set(PHP_SOURCES php-cgi/phpCgiModule.cpp php-cgi/phpCgiModule.hpp php-cgi/Executer.cpp php-cgi/Executer.hpp)

add_definitions(-DMODULE_EXPORTS)

#find_package(Boost 1.65.1 COMPONENTS system)

#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    if(WIN32)
#        add_executable(${PROJECT_NAME} src/main.cpp ${API_HEADERS} ${SERVER_SRCS} ${FILE_SYSTEM_WIN32})
#    else()
#        add_executable(${PROJECT_NAME} src/main.cpp ${API_HEADERS} ${SERVER_SRCS} ${FILE_SYSTEM_UNIX})
#    endif()
#    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#    target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})
#    target_link_libraries(${PROJECT_NAME} rnetwork)
#endif()

add_library(module_test SHARED ${TEST_SOURCES} ${COMMON} ${API_SOURCES})
add_library(net SHARED ${NET_SOURCES} ${COMMON} ${API_SOURCES})
target_link_libraries(net shared rnetwork)
add_library(php-cgi SHARED ${PHP_SOURCES} ${COMMON} ${API_SOURCES})
target_link_libraries(php-cgi nobyte shared)
