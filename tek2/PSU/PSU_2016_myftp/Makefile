##
## Makefile for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/Makefile
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon May 08 13:49:43 2017 Gauthier Cler
## Last update Mon May 08 13:49:43 2017 Gauthier Cler
##

NAME =		server

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Iinclude

all: $(NAME)

include sources.mk

OBJS = 		$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
