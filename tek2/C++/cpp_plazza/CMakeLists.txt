cmake_minimum_required(VERSION 3.7)
project(cpp_plazza)

set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES
        includes/Command.hpp
        includes/CommandManager.hpp
        includes/Error.hpp
        includes/Office.hpp
        includes/Reception.hpp
        includes/Thread.hpp
        includes/Mutex.hpp
        includes/ProcessManager.hpp
        includes/CondVar.hpp
        includes/ConnectorPipe.hpp
        includes/Command.hpp
        includes/CommandManager.hpp
        includes/ThreadPool.hpp
        includes/Worker.hpp
        includes/Utils.hpp
        includes/File.hpp
        includes/ACypher.hpp
        includes/XorCypher.hpp
        includes/CaesarCypher.hpp
        includes/XorCracker.hpp
        includes/Config.hpp)

set(MAIN_FILES
        sources/main.cpp)

set(SOURCE_FILES
        ${MAIN_FILES}
        sources/Mutex.cpp
        sources/Thread.cpp
        sources/Reception.cpp
        sources/Office.cpp
        sources/ProcessManager.cpp
        sources/ConnectorPipe.cpp
        sources/ThreadPool.cpp
        sources/CommandManager.cpp
        sources/Utils.cpp
        sources/XorCracker.cpp
        sources/Command.cpp
        sources/Worker.cpp
        sources/File.cpp
        sources/ACypher.cpp
        sources/XorCypher.cpp
        sources/CaesarCypher.cpp
        sources/main_cypher.cpp)

add_executable(cpp_plazza ${SOURCE_FILES} ${HEADER_FILES})
add_definitions(-W -Wall -Wextra)

include_directories(
        includes
)

target_link_libraries(cpp_plazza -lpthread)