##
## Makefile for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex00/Makefile
##
## Made by Gauthier CLER
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon Jan 09 09:50:00 2017 Gauthier CLER
## Last update Mon Jan 09 09:50:00 2017 Gauthier CLER
##


CC = g++

NAME = my_convert_temp

CFLAGS += -Wall -Werror -Wextra -std=c++03

RM = rm -f

SRCS = ./main.cpp

OBJS = $(SRCS:.cpp=.o)

all:  $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all