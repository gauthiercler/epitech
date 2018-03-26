cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype_rnetwork)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

include_directories(${CMAKE_SOURCE_DIR}/shared/rnetwork .)

set(SOURCES_FILES
        shared_queue/shared_storage.hpp
        shared_queue/alias.hpp
        ClientChannel.cpp
        ClientChannel.hpp
        ClientChannel.cpp
        ClientChannel.hpp
        packet/UDPTokenPacket.cpp
        packet/UDPTokenPacket.hpp
        packet/AssociationPacket.cpp
        packet/AssociationPacket.hpp
        packet/UDPHostPacket.cpp
        packet/UDPHostPacket.hpp
        ClientMasterChannel.cpp
        ClientMasterChannel.hpp
        packet/EntitySpawnPacket.cpp
        packet/EntitySpawnPacket.hpp
        utils/Pos.hpp
        packet/JoinGamePacket.cpp
        packet/JoinGamePacket.hpp
        packet/PlayerIdPacket.cpp
        packet/LobbyListPacket.cpp
        packet/PlayerIdPacket.hpp
        packet/MovePacket.cpp
        packet/MovePacket.hpp
        utils/htonll.hpp
        packet/LobbyListPacket.hpp
        packet/LobbyEntryPacket.cpp
        packet/LobbyEntryPacket.hpp
        packet/LobbyJoinPacket.cpp
        packet/LobbyJoinPacket.hpp
        packet/CreateLobbyPacket.cpp
        packet/CreateLobbyPacket.hpp
        packet/StartGamePacket.cpp
        packet/StartGamePacket.hpp
        packet/Opcodes.hpp
        packet/LobbyLeavePacket.cpp
        packet/LobbyLeavePacket.hpp
        packet/PlayerJoinedPacket.cpp
        packet/PlayerJoinedPacket.hpp
        packet/PlayerLeavedPacket.cpp
        packet/PlayerLeavedPacket.hpp)

if(WIN32)
    add_definitions(-DRNETWORK_EXPORTS)
endif()

add_library(rnetwork_extended SHARED ${SOURCES_FILES})
target_link_libraries(rnetwork_extended rnetwork)

add_executable(rnetwork_extended_client client.cpp)
target_link_libraries(rnetwork_extended_client rnetwork_extended)
add_executable(rnetwork_extended_server server.cpp)
target_link_libraries(rnetwork_extended_server rnetwork_extended)
