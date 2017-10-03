##
## Makefile for malloc in /home/gogo/rendu/tek2/PSU_2016_malloc
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
## 
## Started on  Mon Jan 23 21:53:37 2017 Gauthier Cler
## Last update Fri Feb 10 17:00:56 2017 Gauthier Cler
##

CC		= gcc

CFLAGS		= -fPIC -Wall -Wextra -Iincludes

LDLFLAGS	= -shared

NAME		= libmy_malloc.so

SRCS		= sources/free.c \
		sources/malloc.c \
		sources/realloc.c \
		sources/split_chunk.c \
		sources/malloc_dump.c \
		sources/merge_chunks.c \
		sources/mutex.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLFLAGS)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
