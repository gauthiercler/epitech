cmake_minimum_required(VERSION 3.5.1)
project(cpp_rtype_rnetwork)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

set(SOURCES_FILES
        rnetwork/rnetwork.cpp
        rnetwork/rnetwork.hpp
        rnetwork/udp/Client.cpp
        rnetwork/udp/Client.hpp
        rnetwork/exceptions/InvalidSocket.cpp
        rnetwork/exceptions/InvalidSocket.hpp
        rnetwork/exceptions/BadHostname.cpp
        rnetwork/exceptions/BadHostname.hpp
        rnetwork/packet/IPacket.hpp
        rnetwork/packet/PacketBase.cpp
        rnetwork/packet/PacketBase.hpp
        rnetwork/Endpoint.cpp
        rnetwork/Endpoint.hpp
        rnetwork/packet/StringPacket.cpp
        rnetwork/packet/StringPacket.hpp
        rnetwork/exceptions/IOError.cpp
        rnetwork/exceptions/IOError.hpp
        rnetwork/async/IOService.cpp
        rnetwork/async/IOService.hpp
        rnetwork/services/IService.hpp
        rnetwork/services/ExecService.cpp
        rnetwork/services/ExecService.hpp
        rnetwork/tasks/ExecTask.cpp
        rnetwork/tasks/ExecTask.hpp
        rnetwork/services/IService.cpp
        rnetwork/services/NetworkService.cpp
        rnetwork/services/NetworkService.hpp
        rnetwork/ISender.hpp
        rnetwork/IReceiver.hpp
        rnetwork/tasks/SendTask.cpp
        rnetwork/tasks/SendTask.hpp
        rnetwork/tasks/ReceiveTask.cpp
        rnetwork/tasks/ReceiveTask.hpp
        rnetwork/udp/Server.cpp
        rnetwork/udp/Server.hpp
        rnetwork/exceptions/BadBind.cpp
        rnetwork/exceptions/BadBind.hpp
        rnetwork/packet/PacketBase.tcc
        rnetwork/exceptions/AcceptError.cpp
        rnetwork/exceptions/AcceptError.hpp
        rnetwork/exceptions/BadListen.hpp
        rnetwork/exceptions/BadListen.cpp
        rnetwork/exceptions/ConnectionError.hpp
        rnetwork/exceptions/ConnectionError.cpp
        rnetwork/tasks/AcceptTask.cpp
        rnetwork/tasks/AcceptTask.hpp
        rnetwork/tasks/ITask.hpp
        rnetwork/tcp/Acceptor.cpp
        rnetwork/tcp/Acceptor.hpp
        rnetwork/tcp/Client.cpp
        rnetwork/tcp/Client.hpp
        rnetwork/IAcceptor.hpp
        rnetwork/IClient.hpp
        config/Export.hpp rnetwork/exceptions/InvalidPacket.cpp rnetwork/exceptions/InvalidPacket.hpp rnetwork/Router.hpp rnetwork/tasks/DelayedTask.cpp rnetwork/tasks/DelayedTask.hpp rnetwork/tasks/InfiniteTask.cpp rnetwork/tasks/InfiniteTask.hpp)

set(CLIENT_SOURCES client.cpp)
set(SERVER_SOURCES server.cpp)

add_library(rnetwork SHARED ${SOURCES_FILES})
target_link_libraries(rnetwork ${CMAKE_THREAD_LIBS_INIT})

if(WIN32)
    target_link_libraries(rnetwork wsock32 ws2_32)
    add_definitions(-DRNETWORK_EXPORTS)
endif()

add_executable(rnetwork_client ${CLIENT_SOURCES})
add_executable(rnetwork_server ${SERVER_SOURCES})
target_link_libraries(rnetwork_client rnetwork)
target_link_libraries(rnetwork_server rnetwork)