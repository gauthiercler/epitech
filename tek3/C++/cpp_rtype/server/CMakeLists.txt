cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 14)


set(RTYPE_SERVER_HEADERS include/Engine.hpp
        include/Game.hpp
        include/Player.hpp
        include/libloader/DLLoaderManager.hpp
        include/spawner/PlayerSpawner.hpp
        ../shared/EntityType.hpp
        include/spawner/Spawner.hpp
        include/system/Move.hpp
        include/libloader/impl/types.hpp
        include/libloader/impl/ImplDllLoader.hpp
        include/libloader/DLInstanceLoader.hpp
        include/libloader/DLLoaderFactory.hpp
        include/libloader/FileSystem.hpp
        ../shared/components/Life.hpp
        ../shared/components/LifeTime.hpp
        ../shared/components/Library.hpp
        include/system/NotifyMove.hpp
        include/system/UpdateMove.hpp
        include/spawner/SpawnerManager.hpp)

set(RTYPE_SERVER_SOURCES
        src/Engine.cpp
        src/Game.cpp
        src/Player.cpp
        src/system/Move.cpp
        src/spawner/PlayerSpawner.cpp
        src/spawner/Spawner.cpp
        src/system/NotifyMove.cpp
        src/system/UpdateMove.cpp
        src/spawner/SpawnerManager.cpp)

if (WIN32)
    set (RTYPE_SERVER_SOURCES ${RTYPE_SERVER_SOURCES}
            include/libloader/impl/win32DllLoader.cpp
            include/libloader/impl/win32FileSystem.cpp)
else()
    set (RTYPE_SERVER_SOURCES ${RTYPE_SERVER_SOURCES}
            include/libloader/impl/unixDllLoader.cpp
            include/libloader/impl/unixFileSystem.cpp src/system/UpdateMove.cpp include/system/UpdateMove.hpp src/system/NotifyMove.cpp include/system/NotifyMove.hpp)
endif()

add_executable(cpp_server_rtype src/main.cpp ${RTYPE_SERVER_HEADERS} ${RTYPE_SERVER_SOURCES})

target_include_directories(cpp_server_rtype PUBLIC include)
if (UNIX)
    target_link_libraries(cpp_server_rtype rtecs rnetwork_extended dl)
else()
    target_link_libraries(cpp_server_rtype rtecs rnetwork_extended)
endif()
