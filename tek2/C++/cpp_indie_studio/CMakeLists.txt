cmake_minimum_required(VERSION 3.7)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")

include_directories(include)

set(SOURCE_FILES
        include/IrrlichtWrapper.hpp
        sources/IrrlichtWrapper/IrrlichtWrapper.cpp
        include/managers/RessourceManager.hpp
        sources/IrrlichtWrapper/RessourceManager.cpp
        sources/IrrlichtWrapper/WindowManager.cpp
        include/managers/WindowManager.hpp
        sources/IrrlichtWrapper/SoundManager.cpp
        include/managers/SoundManager.hpp
        sources/IrrlichtWrapper/EventManager.cpp
        include/managers/EventManager.hpp
        sources/IrrlichtWrapper/ScriptManager.cpp
        include/managers/ScriptManager.hpp
        include/entity/IEntity.hpp
        include/entity/ABomb.hpp
        include/entity/ACube.hpp
        include/entity/HumanPlayer.hpp
        sources/game/Game.cpp
        include/game/Game.hpp
        sources/game/MapManager.cpp
        include/game/MapManager.hpp
        sources/game/GameGUI.cpp
        include/game/GameGUI.hpp
        sources/game/PlayerManager.cpp
        include/game/PlayerManager.hpp
        sources/core/Core.cpp
        include/core/Core.hpp
        sources/main.cpp
        include/Error.hpp
        include/managers/VideoDriverManager.hpp
        sources/menu/Menu.cpp
        include/menu/Menu.hpp
        include/game/IDCreator.hpp
        include/game/Position.hpp


        include/core/IController.hpp
        include/menu/IMenu.hpp
        include/menu/HomeMenu.hpp
        include/menu/OptionsMenu.hpp
        sources/menu/HomeMenu.cpp
        sources/menu/OptionsMenu.cpp

        sources/entity/ABomb.cpp
        include/core/IController.hpp
        include/controllers/MenuController.hpp
        include/controllers/EntityController.hpp
        sources/controllers/EntityController.cpp
        sources/entity/HumanPlayer.cpp
        include/game/Map.hpp
        sources/game/Map.cpp
        include/entity/Camera.cpp
        include/entity/Camera.hpp
        include/entity/IBombSpawner.hpp
        sources/entity/BombSpawner.cpp
        include/entity/IMutableEntity.hpp
        include/entity/BasicBomb.hpp
        include/Engine.hpp
        sources/entity/BasicBomb.cpp
        sources/core/Engine.cpp
        sources/controllers/CoreControllers.cpp
        include/controllers/CoreControllers.hpp
        include/controllers/PlayerController.hpp
        sources/controllers/PlayerController.cpp
        sources/controllers/MenuController.cpp
        include/menu/MenuButton.hpp
        sources/menu/MenuButton.cpp
        include/game/Save.hpp
        sources/game/Save.cpp
        include/entity/Box.hpp
        sources/entity/Box.cpp
        sources/entity/ACube.cpp
        include/entity/ACube.hpp
        include/entity/Brick.hpp
        sources/entity/Brick.cpp
        include/state/IPlayerState.hpp
        include/state/core/ACoreState.hpp
        sources/state/core/ACoreState.cpp
        include/core/Random.hpp
        sources/core/Random.cpp
        sources/game/CollisionManager.cpp
        include/game/CollisionManager.hpp
        include/menu/PlayerSelectMenu.hpp
        sources/menu/PlayerSelectMenu.cpp
        include/entity/AquaBomb.hpp
        sources/entity/AquaBomb.cpp
        sources/game/PowerUpFactory.cpp
        include/entity/PowerUpFactory.hpp
        sources/entity/powerup/APowerUp.cpp
        include/entity/APowerUp.hpp
        sources/entity/powerup/PowMoreBomb.cpp
        include/entity/PowMoreBomb.hpp
        include/game/IA.hpp
        sources/game/IA.cpp
        include/entity/PowMorePower.hpp
        sources/entity/powerup/PowMorePower.cpp
        include/game/Score.hpp
        sources/game/Score.cpp
        sources/entity/APlayer.cpp
        include/entity/APlayer.hpp
        sources/entity/powerup/PowAquaBomb.cpp
        include/entity/PowAquaBomb.hpp
        include/entity/PowSkullMalus.hpp
        sources/entity/powerup/PowSkullMalus.cpp
        include/entity/PowMoreSpeed.hpp
        sources/entity/powerup/PowMoreSpeed.cpp
        include/maps/IJsonLoader.hpp
        include/maps/MapInfo.hpp
        include/maps/MapLoader.hpp
        sources/maps/MapLoader.cpp
        include/maps/Errors.hpp
        sources/maps/Error.cpp
        sources/maps/Infos.cpp
        sources/maps/MapFileManager.cpp
        include/maps/MapFileManager.hpp
        include/maps/ConfigMapLoader.hpp
        sources/maps/ConfigMapLoader.cpp
        sources/maps/AJsonParser.cpp
        include/maps/AJsonParser.hpp
        include/menu/HighscoreMenu.hpp
        sources/menu/HighscoreMenu.cpp
        include/core/IABinding.hpp
        sources/core/IABinding.cpp
        include/maps/Serialize.hpp
        include/menu/MapSelectMenu.hpp
        sources/menu/MapSelectMenu.cpp
        include/menu/SplashScreen.hpp
        sources/menu/SplashScreen.cpp
        include/core/Pause.cpp
        include/core/Pause.hpp
        include/entity/Fire.hpp
        sources/entity/Fire.cpp
        include/game/Highscore.hpp
        sources/game/Highscore.cpp
        include/maps/MapSaver.cpp
        include/maps/MapSaver.hpp
        sources/maps/serialize/SerializePlayer.cpp
        sources/maps/serialize/SerializeBomb.cpp)


set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#find_library(IRR_LIBRARY Irrlicht GLU GL X11 Xxf86vm)
#find_library()

add_subdirectory(deps/pybind11)

add_executable(cpp_indie_studio ${SOURCE_FILES})

target_link_libraries(cpp_indie_studio Irrlicht GL X11 Xxf86vm pthread
        sfml-audio pybind11::embed)

