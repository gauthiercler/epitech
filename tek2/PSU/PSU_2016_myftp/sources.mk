##
## sources.mk for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/sources.mk
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon May 08 16:49:43 2017 Gauthier Cler
## Last update Mon May 08 16:49:43 2017 Gauthier Cler
##

SRCS =  src/main.c \
		src/ftp_server.c

#Misc
SRCS +=	src/misc/close.c \
		src/misc/arguments_checking.c \
		src/misc/input.c \
		src/misc/utils.c \
		src/misc/usage.c \
		src/misc/error.c

#Communication
SRCS +=	src/communication/socket.c \
		src/communication/client.c \
		src/communication/response.c \
		src/communication/accept.c \
		src/communication/data_socket.c

#Commands
SRCS +=	src/commands/command.c \
		src/commands/active_mode.c \
		src/commands/change_directory.c \
        src/commands/delete.c \
        src/commands/download_file.c \
        src/commands/help_message.c \
        src/commands/list_files.c \
        src/commands/noop.c \
        src/commands/parent_directory.c \
        src/commands/passive_mode.c \
        src/commands/password_auth.c \
        src/commands/print_directory.c \
        src/commands/quit.c \
        src/commands/upload_file.c \
        src/commands/user_auth.c