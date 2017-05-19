##
## Makefile for tekgui in /home/gogo/rendu/gfx_tekgui
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Feb  1 16:19:55 2016 Gauthier Cler
## Last update Fri Feb 26 15:58:46 2016 Gauthier Cler
##

NAME		=	test

LIB		=	-L../	\
			-ltekgui	\
			-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
CFLAG		=	-W -Wall -I/home/${USER}/.froot/include/ -I. -rdynamic -fPIC -shared

SRC             =       main.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
	gcc -c $< -o $@ $(FLAG)

