##
## Makefile for my_ls in /home/cler_g/rendu/PSU_2015_my_ls
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
## 
## Started on  Mon Nov 23 10:53:20 2015 Gauthier Cler
## Last update Sun Nov 29 12:02:11 2015 Gauthier Cler
##

CC = gcc

NAME = my_ls

RM = rm -f

SRCS = 	main.c	\
	my_strlen.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_putchar.c	\
	nb_fichier.c	\
	read_to_list.c	\
	sort_ascii.c	\
	disp_simple.c	\
	cases.c	\
	droits.c	\
	time.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
