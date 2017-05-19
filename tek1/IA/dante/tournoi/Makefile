##
## Makefile for profondeur in /home/gogo/rendu/dante/profondeur
##
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
##
## Started on  Wed Apr 27 21:52:40 2016 Gauthier Cler
## Last update Thu May  5 16:28:01 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	solver

CFLAGS		+=	-W -Wall -Wextra -Iinclude

SRCS		=	./srcs/main.c			\
			./srcs/loading/load_map.c	\
			./srcs/misc/format.c		\
			./srcs/misc/get_next_line.c	\
			./srcs/misc/put_fd.c		\
			./srcs/misc/put_nb.c		\
			./srcs/misc/str_len.c		\
			./srcs/misc/xmalloc.c		\
			./srcs/misc/p_error.c		\
			./srcs/misc/my_strcmp.c		\
			./srcs/solve/solve.c		\
			./srcs/solve/get_pos.c		\
			./srcs/list/list.c		\
			./srcs/clean/clean.c		\
			./srcs/fill/fill.c		\
			./srcs/solve/gen_path.c		\
			./srcs/check_args/usage.c	\
			./srcs/check_args/check_args.c

OBJS		=	$(SRCS:.c=.o)

LIB		=

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
