##
## Makefile for gfx_tekpaint in /home/gauthier/rendu/gfx_tekpaint
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Jan  4 16:39:47 2016 Gauthier Cler
## Last update Tue Jan 26 21:25:45 2016 Gauthier Cler
##

NAME		=	tekpaint
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/ -Iinclude
SRC		=	./src/main.c			\
			./src/load_bitmap.c		\
			./src/filter/grey_filter.c	\
			./src/filter/negative_filter.c	\
			./src/filter/inverse_filter.c	\
			./src/filter/pixel_filter.c	\
			./src/filter/sepia_filter.c	\
			./src/tekline.c			\
			./src/teksquare_line.c		\
			./src/tekpixel.c		\
			./src/my_strcat.c		\
			./src/tekcircle.c		\
			./src/tekcircle_pen.c		\
			./src/teksquare.c		\
			./src/full_pix.c		\
			./src/draw_form.c		\
			./src/misc.c			\
			./src/check_arg.c		\
			./src/env.c			\
			./src/selec.c			\
			./src/my_atoi.c			\
			./src/load_cactus.c		\
			./src/palet.c			\
			./src/save.c			\
			./src/my_strcmp.c		\
			./src/my_putstr.c

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

