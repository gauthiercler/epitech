cmake_minimum_required(VERSION 3.6)
project(snake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES_FILES
        ../../interfaces/IEvent.hpp
        ../../interfaces/IGame.hpp
        ../../interfaces/IFrame.hpp
        ../../interfaces/IGraphic.hpp
        ../../interfaces/IPicture.hpp
        ../../interfaces/ISprite.hpp
        ../../interfaces/ISound.hpp
        includes/Snake.hpp
        sources/Snake.cpp
        ../common/Clock.hpp
        ../common/Clock.cpp
        ../common/Input.cpp ../common/Input.hpp)

add_executable(snake ${SOURCES_FILES})
add_definitions(-W -Wall -Wextra)
include_directories(
        includes
        ../../interfaces
        ../common
)
