##
## Makefile for Makefile in /home/cler_g/rendu/CPE_2015_BSQ
##
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
##
## Started on  Mon Nov 30 23:35:03 2015 Gauthier Cler
## Last update Wed Dec  9 00:03:21 2015 Gauthier Cler
##

CC = gcc

NAME = bsq

RM = rm -f

FLAGS = -W -Wall -Werror -ansi -pedantic

SRCS = 	main.c	\
	my_getnbr.c	\
	my_strlen.c	\
	find_square.c	\
	fill.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I.

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
