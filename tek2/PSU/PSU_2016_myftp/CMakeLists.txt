cmake_minimum_required(VERSION 3.7)
project(PSU_2016_myftp)

set(CMAKE_C_STANDARD 99)

set(INCLUDE_FILES
        include/ftp.h
        include/macro.h
        include/structures.h
        include/socket.h
        include/commands.h
        include/misc.h)

set(SOURCE_FILES
        src/main.c
        src/ftp_server.c
        src/misc/usage.c
        src/misc/arguments_checking.c
        src/communication/socket.c
        src/misc/close.c
        src/communication/client.c
        src/misc/input.c
        src/commands/command.c
        src/commands/active_mode.c
        src/commands/change_directory.c
        src/commands/delete.c
        src/commands/download_file.c
        src/commands/help_message.c
        src/commands/list_files.c
        src/commands/noop.c
        src/commands/parent_directory.c
        src/commands/passive_mode.c
        src/commands/password_auth.c
        src/commands/print_directory.c
        src/commands/quit.c
        src/commands/upload_file.c
        src/commands/user_auth.c
        src/communication/response.c
        src/misc/utils.c
        src/communication/accept.c
        src/misc/error.c
        src/communication/data_socket.c)

add_executable(server ${SOURCE_FILES} ${INCLUDE_FILES})
include_directories(include)
