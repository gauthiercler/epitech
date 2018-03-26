cmake_minimum_required(VERSION 3.9.6)
project(server)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

# Include basic API
include_directories(../api)
# Include Lille API
include_directories(../api/pp)
# Include libs
include_directories(../lib)
# Include basics
include_directories(include)

set(BOOST_ROOT ~/Utils/boost_1_65_1)

set(API_HEADERS
        ../api/pp/.
        ../api
        ../lib/.)

set(FILE_SYSTEM_UNIX src/DLLoader/unixFileSystem.cpp src/DLLoader/unixDllLoader.cpp)
set(FILE_SYSTEM_WIN32 src/DLLoader/win32FileSystem.cpp src/DLLoader/win32DllLoader.cpp)

set(SERVER_SRCS
        src/main.cpp
        src/Core.cpp
        include/Core.hpp
        src/ConfigManager.cpp
        include/ConfigManager.hpp
        src/ModuleManager.cpp
        include/ModuleManager.hpp
        src/JSONParser.cpp
        include/JSONParser.hpp
        include/ModuleLoader.hpp
        include/DLLoader
        src/ModuleLoader.cpp
        include/BetterConf.hpp)

if(WIN32)
    add_executable(zia-${PROJECT_NAME} src/main.cpp ${API_HEADERS} ${SERVER_SRCS} ${FILE_SYSTEM_WIN32} ../api/pp/conf.cpp)
else()
    add_executable(zia-${PROJECT_NAME} src/main.cpp ${API_HEADERS} ${SERVER_SRCS} ${FILE_SYSTEM_UNIX} ../api/pp/conf.cpp)
endif()
target_link_libraries(zia-${PROJECT_NAME} ${CMAKE_DL_LIBS})
target_link_libraries(zia-${PROJECT_NAME} rnetwork shared nobyte)