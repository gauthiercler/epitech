##
## Makefile for n4s in /home/gogo/rendu/CPE_2015_n4s/
##
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
##
## Started on  Tue Apr 26 21:58:13 2016 Gauthier Cler
## Last update Fri May 27 19:15:59 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	ia

CFLAGS		+=	-W -Wall -Wextra -Iinclude

RM		=	rm -f

SRCS		=	./srcs/main.c					\
  			./srcs/misc/format.c				\
			./srcs/misc/get_next_line.c			\
			./srcs/misc/my_atoi.c				\
			./srcs/misc/my_strcmp.c				\
			./srcs/misc/put_fd.c				\
			./srcs/misc/put_nb.c				\
			./srcs/misc/str_len.c				\
			./srcs/misc/copy_substring.c			\
			./srcs/misc/my_atof.c				\
			./srcs/misc/put_float.c				\
			./srcs/deletion/free_array.c			\
			./srcs/explode/explode_count.c			\
			./srcs/explode/explode_strings.c		\
			./srcs/explode/explode.c			\
			./srcs/explode/purge_strings.c			\
			./srcs/explode/skips.c				\
			./srcs/algorithm/treatment/call_instruction.c	\
			./srcs/algorithm/rays/assess_rays.c		\
			./srcs/algorithm/rays/assess_spread.c		\
			./srcs/algorithm/computation/compute_output.c	\
			./srcs/algorithm/computation/speed.c		\
			./srcs/algorithm/computation/wheels.c		\
			./srcs/algorithm/computation/wheels_angle.c

OBJS		=	$(SRCS:.c=.o)

LIB		=

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
