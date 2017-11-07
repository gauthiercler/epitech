cmake_minimum_required(VERSION 3.8.2)

#set(BOOST_ROOT "C:/local/boost_1_65_1")
#set(BOOST_LIBRARYDIR "C:/local/boost_1_65_1/lib64-msvc-14.1")
project(spider_client)

SET (BOOST_MIN_VERSION "1.65.1")
set (Boost_NO_BOOST_CMAKE ON)
set (Boost_USE_STATIC_LIBS ON)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.65.1 COMPONENTS system filesystem date_time regex REQUIRED)
find_package(OpenSSL)

if(OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS} ../common)
endif()

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501 /wd4996")
else ()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
endif (WIN32)

set(SOURCE_FILES
        src/main.cpp
        src/ListenerManager.cpp
        src/ListenerManager.hpp
        src/Engine.cpp
        src/Engine.hpp
        src/Data.cpp
        src/Data.hpp
        src/CommunicationManager.cpp
        src/CommunicationManager.hpp
        ../common/Error.hpp
        src/IListener.hpp
        src/KeyboardListener.cpp
        src/KeyboardListener.hpp
        src/MouseListener.cpp
        src/MouseListener.hpp
        ../common/Spider/Network/Client/Client.cpp
        ../common/Spider/Network/Client/Client.hpp
        ../common/Network/Client/Client.hpp
        ../common/Network/Client/Client.cpp
        src/AOutStream.hpp
        src/Network.cpp
        src/System.cpp
        src/System.hpp
        src/Network.hpp
        src/AOutStream.cpp
        src/Config.hpp
        src/File.cpp
        src/File.hpp ../common/Network/Error.h)

set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR})

add_executable(spider_client ${SOURCE_FILES})
target_link_libraries(spider_client ${Boost_LIBRARIES})
target_link_libraries(spider_client ${OPENSSL_LIBRARIES})
