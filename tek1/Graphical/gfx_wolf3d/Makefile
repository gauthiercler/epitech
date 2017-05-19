##
## Makefile for Makefile in /home/gauthier/rendu/gfx_wolf3d
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Sun Jan  3 21:56:29 2016 Gauthier Cler
## Last update Thu Jun  9 14:00:33 2016 Gauthier Cler
##

NAME		=	wolf3d
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -Werror -I/home/${USER}/.froot/include/ -Iinclude
SRC		=	./src/main.c	\
			./src/keys.c	\
			./src/ini.c	\
			./src/tekline.c	\
			./src/my_atoi.c	\
			./src/my_atof.c	\
			./src/ray_check.c	\
			./src/ray.c	\
			./tcore/vecnorm.c	\
			./tcore/go.c	\
			./tcore/tekpixel.c

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

