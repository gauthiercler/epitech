##
## Makefile for Makefile in /home/cler_g/rendu/PSU_2015_my_popup
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
## 
## Started on  Mon Nov 30 15:18:51 2015 Gauthier Cler
## Last update Sat Dec 12 16:00:37 2015 Gauthier Cler
##

CC = gcc

NAME = my_select

RM = rm -f

SRCS = 	my_strlen.c	\
	my_putchar.c	\
	loop.c		\
	my_put_nbr.c	\
	my_putstr.c	\
	delete.c	\
	keys.c		\
	space.c		\
	my_strdup.c	\
	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
