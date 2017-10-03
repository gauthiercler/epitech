cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")

set(SOURCES
        sources/main.cpp
        sources/main.cpp
        includes/managers/WindowManager.hpp
        sources/managers/WindowManager.cpp
        includes/Core.hpp
        sources/Core.cpp
        includes/managers/EventManager.hpp
        includes/utils/Position.hpp
        sources/utils/Position.cpp
        sources/managers/EventManager.cpp
        includes/managers/Engine.hpp
        sources/managers/Engine.cpp includes/managers/Wrapper.hpp
        sources/managers/Wrapper.cpp
        includes/game/Menu.hpp
        sources/game/Menu.cpp
        includes/game/Game.hpp
        sources/game/Game.cpp
        includes/managers/RessourcesManager.hpp
        sources/managers/RessourcesManager.cpp
        includes/utils/Error.hpp
        includes/utils/Color.hpp
        sources/utils/Color.cpp
        includes/utils/Size.hpp
        sources/utils/Size.cpp
        includes/drawable/IDrawable.hpp
        includes/drawable/Text.hpp
        sources/drawable/Text.cpp
        includes/drawable/Rect.hpp
        sources/drawable/Rect.cpp
        includes/game/Map.hpp
        includes/game/Tiles.hpp
        sources/game/Map.cpp
        sources/game/Tiles.cpp
        includes/game/Player.hpp
        includes/game/AEntity.hpp
        sources/game/AEntity.cpp
        sources/game/Player.cpp
        includes/drawable/Sprite.hpp
        sources/drawable/Sprite.cpp
        includes/game/Material.hpp
        sources/game/Material.cpp
        includes/game/Food.hpp
        sources/game/Food.cpp
        includes/game/Linemate.hpp
        sources/game/Linemate.cpp
        includes/game/Deraumere.hpp
        sources/game/Deraumere.cpp
        includes/game/Sibur.hpp
        sources/game/Sibur.cpp
        includes/game/Mendiane.hpp
        sources/game/Mendiane.cpp
        includes/game/Phiras.hpp
        sources/game/Phiras.cpp
        includes/game/Thystame.hpp
        sources/game/Thystame.cpp
        includes/utils/Random.hpp
        includes/server/Parser.hpp
        sources/server/Parser.cpp
        includes/server/Socket.hpp
        sources/server/Socket.cpp
        sources/utils/Random.cpp
        includes/game/Inventory.hpp
        sources/game/Inventory.cpp
        includes/utils/Utils.hpp
        sources/utils/Utils.cpp includes/server/Buffer.hpp sources/server/Buffer.cpp includes/game/Egg.hpp sources/game/Egg.cpp includes/game/Incantation.hpp sources/game/Incantation.cpp includes/managers/SoundManager.hpp sources/managers/SoundManager.cpp includes/game/Chat.hpp sources/game/Chat.cpp)

add_executable(zappy_client
        ${SOURCES})

include_directories(zappy_client includes ../lib/cnetwork/includes)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.3 REQUIRED network audio graphics window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(zappy_client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)
