##
## Makefile for lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc
## 
## Made by gauthier Cler
## Login   <gauthier.cler@epitech.eu>
## 
## Started on  Wed Mar 22 09:12:46 2017 gauthier Cler
## Last update Thu Mar 30 18:45:18 2017 anas Buyumad
##

CC			= gcc

CFLAGS			= -Wall -Wextra -W -Iincludes -lpthread

NAME			= lemipc

SRCS			= sources/main.c \
			sources/errors/error.c \
			sources/args_handler/parse_args.c \
			sources/ipc/init_ipc.c \
			sources/player/init_player.c \
			sources/ipc/ipc.c \
			sources/ipc/clean_ipc.c \
			sources/player/simulation.c \
			sources/player/insert_player.c \
			sources/arena/get_free_spot.c \
			sources/misc/xrand.c \
			sources/arena/is_winner.c \
			sources/player/move.c \
			sources/player/is_alive.c \
			sources/arena/display.c \
			sources/player/attack.c \
			sources/player/target.c \
			sources/arena/update_arena.c \
			sources/path_finding/clean/clean.c \
			sources/path_finding/list/get_node.c \
			sources/path_finding/list/list.c \
			sources/path_finding/solve/gen_path.c \
			sources/path_finding/solve/get_pos.c \
			sources/path_finding/solve/solve.c \
			sources/path_finding/solve/verif.c \
			sources/path_finding/misc/xmalloc.c \
			sources/arena/is_last_of_team.c \
			sources/player/streamer/startup_match.c \
			sources/arena/is_empty.c \
			sources/arena/exit.c \
			sources/player/streamer/broadcast.c \
			sources/player/channel/emit_order.c \
			sources/player/channel/receive_order.c \
			sources/player/captain/determine_target.c \
			sources/player/captain/command.c \
			sources/player/follow_command.c

OBJS			= $(SRCS:.c=.o)

DEBUG			= no

ifeq ($(DEBUG), yes)
	CFLAGS += 	-g
endif

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
