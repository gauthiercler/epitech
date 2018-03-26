cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

if (UNIX)
    set (CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS} "-pg -g")
    set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -pg -g -O2")
    set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -pg")
endif()

set(SOURCES
        src/system/Move.cpp
        include/system/Move.hpp
        src/entity/Square.cpp
        include/Square.hpp
        src/Game.cpp
        include/Game.hpp
        include/system/Render.hpp
        src/system/Render.cpp
        include/singleton/Window.hpp
        src/singleton/Window.cpp
        include/system/HandleMoveInput.hpp
        src/system/HandleMoveInput.cpp
        src/system/HandleInput.cpp
        include/system/HandleInput.hpp
        include/system/EntityDrawable.hpp
        src/system/EntityDrawable.cpp
        include/system/FontDrawable.hpp
        src/system/FontDrawable.cpp
        include/asset/AssetsLoader.hpp
        include/asset/AssetsStore.hpp
        include/asset/Asset.hpp
        include/asset/AssetType.hpp
        include/asset/Font.hpp
        src/asset/Font.cpp
        src/asset/Asset.cpp
        src/system/FPSCalculator.cpp
        include/system/FPSCalculator.hpp
        include/asset/AssetIdGenerator.hpp
        include/AContext.hpp
        src/AContext.cpp
        include/Engine.hpp
        include/Menu.hpp
        src/Menu.cpp
        src/spawner/SimpleBullet.cpp
        src/Engine.cpp
        include/spawner/SimpleBullet.hpp
        src/system/HandleShoot.cpp
        include/system/AddAcceleration.hpp
        src/system/AddAcceleration.cpp
        ../shared/components/BoundingBox.hpp
        ../shared/components/Collide.hpp
        include/system/Collisions.hpp
        src/system/Collisions.cpp
        include/system/Death.hpp
        src/system/Death.cpp
        include/spawner/StarSpawner.hpp
        src/spawner/StarSpawner.cpp
        include/system/Starfield.hpp
        src/system/Starfield.cpp
        include/singleton/Singleton.hpp
        include/singleton/Settings.hpp
        include/singleton/Context.hpp
        src/singleton/Settings.cpp
        ../shared/EntityType.hpp
        ../shared/components/Type.hpp
        src/NetworkHandler.cpp
        src/system/SendToNetwork.cpp
        include/system/SendToNetwork.hpp
        include/singleton/NetworkManager.hpp
        src/system/UpdateNetworkMove.cpp
        include/system/UpdateNetworkMove.hpp
        include/asset/Music.hpp
        src/asset/Music.cpp)

set(COMPONENTS_SOURCES
        ../shared/components/RtypeInput.hpp
        ../shared/components/Drawable.hpp
        ../shared/components/Text.hpp
        ../shared/components/FPS.hpp
        ../shared/components/RtypeCommand.hpp
        ../shared/components/Acceleration.hpp
        ../shared/components/Position.hpp
        ../shared/components/Speed.hpp
        ../shared/components/PlayerID.hpp
        ../shared/components/ClientUdp.hpp
        ../shared/components/Dead.hpp ../shared/components/Life.hpp
        ../shared/components/LifeTime.hpp
        src/system/RemoveWhenOutBounds.cpp
        include/system/RemoveWhenOutBounds.hpp
        ../shared/components/Dead.hpp ../shared/components/Life.hpp
        ../shared/components/LifeTime.hpp
        ../shared/components/Library.hpp)

if (WIN32)
    set(Boost_USE_STATIC_LIBS ON)
    set(BOOST_LIBRARYDIR "C:\\local\\boost_1_65_1\\lib32-msvc-14.1")
    set(BOOST_ROOT "C:\\local\\boost_1_65_1")
endif()

find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set (MENU_SOURCES
        src/menu/FSM/FSM.hpp
        src/menu/FSM/definitions.hpp
        src/menu/FSM/states/StateMainMenu.hpp
        src/menu/FSM/events/EventStartComputation.hpp
        src/menu/FSM/states/StateCredits.hpp
        src/menu/FSM/states/StateOptionsMenu.hpp
        src/menu/FSM/states/StateExit.hpp
        src/menu/FSM/states/StatePlayMenu.hpp
        src/menu/FSM/states/StateSingleplayerMenu.hpp
        src/menu/FSM/states/StateMultiplayerMenu.hpp
        src/menu/FSM/states/StateMultiplayerLobbiesListingMenu.hpp
        src/menu/FSM/states/StateMultiplayerLobbyMenu.hpp
        src/menu/FSM/transitions/TransitionSwitchMenuState.hpp
        src/menu/FSM/guards/GuardTransitionIsTriggered.hpp
        src/menu/GUI/IMenuHandler.hpp
        src/menu/FSM/states/StateStartGame.hpp
        src/menu/State.hpp
        src/menu/GUI/CreditsHandler.hpp
        src/menu/GUI/Handler.hpp
        src/menu/GUI/MenuHandler.hpp
        src/menu/GUI/MainMenuHandler.hpp
        src/menu/GUI/ExitHandler.hpp
        src/menu/GUI/MultiplayerLobbyHandler.hpp
        src/menu/GUI/MultiplayerLobbiesListingHandler.hpp
        src/menu/GUI/MultiplayerMenuHandler.hpp
        src/menu/GUI/OptionsMenuHandler.hpp
        src/menu/GUI/PlayMenuHandler.hpp
        src/menu/GUI/SingleplayerMenuHandler.hpp
        src/menu/GUI/Callback.hpp
        src/menu/GUI/Utils.hpp
        src/menu/GUI/GameStartingHandler.hpp)

set(IMGUI
        ImGui/imgui.cpp
        ImGui/imgui_demo.cpp
        ImGui/imgui-SFML.cpp
        ImGui/imconfig.h
        ImGui/imgui_draw.cpp
        ImGui/imgui_internal.h
        ImGui/stb_rect_pack.h
        ImGui/stb_textedit.h
        ImGui/stb_truetype.h
        include/spawner/Spawner.hpp
        include/system/HandleShoot.hpp
        src/Engine.cpp
        src/singleton/ServerId.cpp include/singleton/ServerId.hpp)

include_directories(../shared/rnetwork include ../shared .. ImGui src/menu)

if (WIN32)
    set(SFML_ROOT "C:/Program Files/SFML/")
endif()

set(${CMAKE_EXE_LINKER_FLAGS} -pg)

add_executable(cpp_client_rtype src/main.cpp ${SOURCES} ${COMPONENTS_SOURCES} ${IMGUI} ${MENU_SOURCES})

find_package(SFML 2 REQUIRED audio graphics window system)
find_package(OpenGL REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(cpp_client_rtype ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

if(Boost_FOUND)
    target_link_libraries(cpp_client_rtype ${Boost_LIBRARIES})
endif()

target_link_libraries(cpp_client_rtype rtecs rnetwork_extended ${OPENGL_LIBRARIES})