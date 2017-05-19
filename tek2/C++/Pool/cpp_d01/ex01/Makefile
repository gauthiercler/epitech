##
## Makefile for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex01/
##
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
##
## Started on  Wed Jan  4 13:41:53 2017 Gauthier Cler
## Last update Wed Jan  4 16:13:24 2017 Gauthier Cler
##

NAME		=	menger

CFLAGS		+=	-Wall -Werror -Wextra -std=gnu99

SRC		=	menger.c					\
			main.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(FLAGS) -o $(NAME)
clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:		fclean all
