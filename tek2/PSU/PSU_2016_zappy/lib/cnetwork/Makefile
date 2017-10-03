##
## Makefile for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/Makefile
##
## Made by Antoine FORET
## Login   <antoine.foret@epitech.eu>
##
## Started on  Sat May 13 23:00:08 2017 Antoine FORET
## Last update Sat May 13 23:00:08 2017 Antoine FORET
##

NAME=		cnetwork

SRCS=		srcs/client/destroy.c			\
		srcs/client/disable_keep_alive.c	\
		srcs/client/disconnect.c		\
		srcs/client/enable_keep_alive.c		\
		srcs/client/get_host_ip.c		\
		srcs/client/get_host_port.c		\
		srcs/client/get_ip.c			\
		srcs/client/get_port.c			\
		srcs/client/is_connected.c		\
		srcs/client/keep_alive_status.c		\
		srcs/client/new.c			\
		srcs/client/receive.c			\
		srcs/client/receive_until.c		\
		srcs/client/send.c			\
		srcs/tcp_socket/accept.c		\
		srcs/tcp_socket/connect.c		\
		srcs/tcp_socket/bind.c			\
		srcs/tcp_socket/destroy.c		\
		srcs/tcp_socket/disconnect.c		\
		srcs/tcp_socket/disable_keep_alive.c	\
		srcs/tcp_socket/get_foreign_ip.c	\
		srcs/tcp_socket/enable_keep_alive.c	\
		srcs/tcp_socket/get_foreign_port.c	\
		srcs/tcp_socket/get_ip.c		\
		srcs/tcp_socket/get_port.c		\
		srcs/tcp_socket/is_connected.c		\
		srcs/tcp_socket/keep_alive_status.c	\
		srcs/tcp_socket/listen.c		\
		srcs/tcp_socket/new.c			\
		srcs/tcp_socket/receive.c		\
		srcs/tcp_socket/receive_until.c		\
		srcs/tcp_socket/send.c			\
		srcs/socket_watcher/can_read.c		\
		srcs/socket_watcher/can_write.c		\
		srcs/socket_watcher/clear_tracking.c	\
		srcs/socket_watcher/destroy.c		\
		srcs/socket_watcher/generate_tracking.c	\
		srcs/socket_watcher/get_record.c	\
		srcs/socket_watcher/get_record_socket.c	\
		srcs/socket_watcher/new.c		\
		srcs/socket_watcher/track.c		\
		srcs/socket_watcher/untrack.c		\
		srcs/socket_watcher/untrack_all.c	\
		srcs/socket_watcher/wait.c


OBJS=		$(SRCS:.c=.o)

CFLAGS=		-W -Wall -Wextra -Iincludes -I../cextended/includes

all:		lib$(NAME).a

lib$(NAME).a:	$(OBJS)
		make -C ../cextended
		mkdir -p build_cextended
		cd build_cextended && ar -x ../../cextended/libcextended.a
		ar rcs lib$(NAME).a build_cextended/*.o $(OBJS)
		rm -rf build_cextended

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f lib$(NAME).a

re:		fclean all