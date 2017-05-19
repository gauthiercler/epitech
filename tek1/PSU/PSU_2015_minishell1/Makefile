##
## Makefile for minishell1 in /home/gauthier/rendu/PSU_2015_minishell1
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Sun Jan 24 23:18:21 2016 Gauthier Cler
## Last update Sun Jan 24 23:18:42 2016 Gauthier Cler
##

CC = gcc

NAME = mysh

RM = rm -f

SRCS =	./src/get_next_line.c		\
	./src/my_putstr.c		\
	./src/my_putchar.c		\
	./src/my_str_to_wordtab.c	\
	./src/my_path_to_tab.c		\
	./src/chain_list.c		\
	./src/my_strcat.c		\
	./src/get_env.c			\
	./src/my_strlen.c		\
	./src/my_strdup.c		\
	./src/tools.c			\
	./src/env.c			\
	./src/my_strcmp.c		\
	./src/my_strncmp.c		\
	./src/my_atoi.c			\
	./src/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -Iinclude

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
