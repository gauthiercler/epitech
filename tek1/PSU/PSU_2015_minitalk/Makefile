##
## Makefile for minital in /home/gogo/rendu/PSU_2015_minitalk
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Feb  1 11:48:34 2016 Gauthier Cler
## Last update Sun Feb 21 09:40:04 2016 Gauthier Cler
##

CC = gcc

NAME1 = ./server/server

NAME2 = ./client/client

RM = rm -f

SRCS1 =	./server/src/main.c		\
	./server/src/my_putchar.c	\
	./server/src/my_put_nbr.c

SRCS2 = ./client/src/main.c		\
	./server/src/my_putchar.c	\
	./client/src/my_atoi.c		\
	./server/src/my_put_nbr.c

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	$(CC) -o $(NAME1) $(OBJS1) -I./server/include

$(NAME2): $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2) -I./client/include

clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean: clean
	$(RM) ./server/server
	$(RM) ./client/client

re: fclean all
