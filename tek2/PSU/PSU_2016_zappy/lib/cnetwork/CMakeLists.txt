cmake_minimum_required(VERSION 3.7)
project(C_Network)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -O2")

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib/cextended)
LINK_LIBRARIES(cextended)

include_directories(../cextended/includes)


set(SOURCE_FILES
        includes/client.h
        includes/portability.h
        includes/socket_watcher.h
        includes/tcp_socket.h
        srcs/client/destroy.c
        srcs/client/disable_keep_alive.c
        srcs/client/disconnect.c
        srcs/client/enable_keep_alive.c
        srcs/client/get_host_ip.c
        srcs/client/get_host_port.c
        srcs/client/get_ip.c
        srcs/client/get_port.c
        srcs/client/is_connected.c
        srcs/client/keep_alive_status.c
        srcs/client/new.c
        srcs/client/receive.c
        srcs/client/receive_until.c
        srcs/client/send.c
        srcs/socket_watcher/can_read.c
        srcs/socket_watcher/can_write.c
        srcs/socket_watcher/clear_tracking.c
        srcs/socket_watcher/destroy.c
        srcs/socket_watcher/generate_tracking.c
        srcs/socket_watcher/get_record.c
        srcs/socket_watcher/get_record_socket.c
        srcs/socket_watcher/new.c
        srcs/socket_watcher/track.c
        srcs/socket_watcher/untrack.c
        srcs/socket_watcher/untrack_all.c
        srcs/socket_watcher/wait.c
        srcs/tcp_socket/accept.c
        srcs/tcp_socket/bind.c
        srcs/tcp_socket/connect.c
        srcs/tcp_socket/destroy.c
        srcs/tcp_socket/disable_keep_alive.c
        srcs/tcp_socket/disconnect.c
        srcs/tcp_socket/enable_keep_alive.c
        srcs/tcp_socket/get_foreign_ip.c
        srcs/tcp_socket/get_foreign_port.c
        srcs/tcp_socket/get_ip.c
        srcs/tcp_socket/get_port.c
        srcs/tcp_socket/is_connected.c
        srcs/tcp_socket/keep_alive_status.c
        srcs/tcp_socket/listen.c
        srcs/tcp_socket/new.c
        srcs/tcp_socket/receive.c
        srcs/tcp_socket/receive_until.c
        srcs/tcp_socket/send.c)

add_library(cnetwork STATIC ${SOURCE_FILES})
target_include_directories(cnetwork PRIVATE includes)