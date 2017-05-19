##
## Makefile for Makefile in /home/gogo/rendu/CPE_2015_Allum1
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Tue Feb  9 23:05:12 2016 Gauthier Cler
## Last update Wed Feb 10 20:39:08 2016 Gauthier Cler
##

CC = gcc

NAME = allum1

RM = rm -f

FLAGS = -W -Wall -Werror -ansi -pedantic

SRCS = 	main.c	\
	get_next_line.c	\
	misc.c		\
	my_atoi.c	\
	input.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I.

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
