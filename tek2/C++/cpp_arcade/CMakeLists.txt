cmake_minimum_required(VERSION 3.6)
project(cpp_arcade)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/interfaces/IEvent.hpp
        src/interfaces/Protocol.hpp
        src/interfaces/IFrame.hpp
        src/interfaces/IGame.hpp
        src/interfaces/IGraphic.hpp
        src/interfaces/IPicture.hpp
        src/interfaces/ISound.hpp
        src/interfaces/ISprite.hpp
        src/interfaces/Structures.hpp
        src/main.cpp
        src/libs/common/Utils.cpp
        src/libs/common/Utils.hpp
        src/core/sources/Core.cpp
        src/core/includes/Core.hpp
        src/core/sources/DynLoader.cpp
        src/core/includes/DynLoader.hpp
        src/games/common/Scores.cpp
        src/games/common/Clock.cpp
        src/games/common/ProtocolHandler.cpp
        src/games/common/ProtocolHandler.hpp)

add_executable(arcade ${SOURCE_FILES})
add_definitions(-W -Wall -Wextra)
target_include_directories(arcade PRIVATE src/interfaces)

add_subdirectory(src/libs/ncurses)
add_subdirectory(src/libs/sfml)
add_subdirectory(src/libs/opengl)
add_subdirectory(src/games/snake)
add_subdirectory(src/games/pacman)
include_directories(
        src/core/includes
        src/errors
        src/libs/common
        src/games/common
)

target_link_libraries(arcade -ldl)