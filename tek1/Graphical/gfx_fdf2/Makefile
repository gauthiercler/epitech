##
## Makefile for Makefile in /home/gauthier/rendu/gfx_fdf2
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Dec 20 22:31:59 2015 Gauthier Cler
## Last update Mon Dec 20 12:00:29 2015 Gauthier Cler
##

NAME		=	fdf2
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -Werror -ansi -pedantic -I/home/${USER}/.froot/include/ -Iinclude
SRC		=	./src/main.c		\
			./src/full_pix.c	\
			./src/grid.c		\
			./src/ini.c		\
			./src/draw.c		\
			./src/fdf.c		\
			./src/surface.c		\
			./src/my_strlen.c	\
			./src/my_strcmp.c	\
			./src/my_getnbr.c	\
			./tcore/tekpixel.c	\
			./tcore/tekline.c	\
			./tcore/tekisoproject.c

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

