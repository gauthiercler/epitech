cmake_minimum_required(VERSION 3.6)
project(pacman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES_FILES
        ../../interfaces/IEvent.hpp
        ../../interfaces/IGame.hpp
        ../../interfaces/IFrame.hpp
        ../../interfaces/IGraphic.hpp
        ../../interfaces/IPicture.hpp
        ../../interfaces/ISprite.hpp
        ../../interfaces/ISound.hpp
        includes/Pacman.hpp
        includes/AStar.hpp
        includes/Ghost.hpp
        sources/Pacman.cpp
        sources/AStar.cpp
        sources/Ghost.cpp
        ../common/Clock.cpp
        ../common/Clock.hpp
        sources/DFS.cpp
        includes/DFS.hpp
        includes/PacmanCell.hpp)

add_executable(pacman ${SOURCES_FILES})
add_definitions(-W -Wall -Wextra)
include_directories(
        includes
        ../../interfaces
        ../common
)
