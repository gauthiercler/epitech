cmake_minimum_required(VERSION 3.8)
project(spider_server)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)
find_package(OpenSSL)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
endif()

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.64.1 REQUIRED system)

set(SOURCE_FILES
        src/database/Collection.cpp
        src/database/Collection.hpp
        src/database/Manager.cpp
        src/database/Manager.hpp
        src/database/Error.hpp
        src/database/Model.cpp
        src/database/Model.hpp
        src/database/Schema.cpp
        src/database/Schema.hpp
        src/parser/Parser.cpp
        src/parser/Parser.hpp
        ../common/Network/Client/Client.cpp
        ../common/Network/Client/Client.hpp
        src/Network/Server/Server.cpp
        src/Network/Server/Server.hpp
        src/Spider/Network/NetworkManager/NetworkManager.cpp
        src/Spider/Network/NetworkManager/NetworkManager.hpp
        ../common/Spider/Network/Client/Client.cpp
        ../common/Spider/Network/Client/Client.hpp src/Spider/CommandManager/CommandManager.cpp src/Spider/CommandManager/CommandManager.hpp src/Spider/Commands/ICommand.hpp src/Spider/Commands/commands/pingCommand.cpp src/Spider/Commands/commands/pingCommand.hpp
        ../common/Spider/Network/Client/Client.hpp src/parser/Error.hpp src/Spider/Commands/commands/ClientCommand.cpp src/Spider/Commands/commands/KeyboardCommand.cpp src/Spider/Commands/commands/KeyboardCommand.hpp src/Spider/Commands/commands/MouseCommand.cpp src/Spider/Commands/commands/MouseCommand.hpp src/Spider/Commands/commands/CommandResponseCommand.cpp src/Spider/Commands/commands/CommandResponseCommand.hpp)

set(TEST_FILES
        test/schema/schema.cpp
        test/schema/enum/enum.cpp
        test/schema/number/number.cpp
        test/schema/object/object.cpp
        test/schema/regex/regex.cpp
        test/schema/string/string.cpp
        test/schema/schema.hpp test/schema/size/size.cpp src/Spider/Commands/commands/ClientCommand.cpp)

set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests ${TEST_FILES} ${SOURCE_FILES})

add_executable(spider_server ${SOURCE_FILES} src/main.cpp src/Spider/Spider/Spider.cpp src/Spider/Spider/Spider.hpp)

if(Boost_FOUND)
    target_link_libraries(spider_server ${Boost_LIBRARIES} boost_regex boost_thread)
    target_link_libraries(tests ${Boost_LIBRARIES} boost_regex boost_thread)
endif()

if(OPENSSL_FOUND)
    target_link_libraries(spider_server ${OPENSSL_LIBRARIES})
    target_link_libraries(tests ${OPENSSL_LIBRARIES})
endif()

target_link_libraries(spider_server rethinkdb++)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread rethinkdb++)

include_directories(../common)
include_directories(src/database)
include_directories(test)
include_directories(src)
