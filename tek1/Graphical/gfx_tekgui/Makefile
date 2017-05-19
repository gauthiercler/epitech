##
## Makefile for tekgui in /home/gogo/rendu/gfx_tekgui
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Feb  1 16:19:55 2016 Gauthier Cler
## Last update Tue Mar  1 21:06:18 2016 Gauthier Cler
##

NAME		=	libtekgui.a

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -I/home/${USER}/.froot/include/ -Iinclude

SRC             =       ./src/main.c            \
                        ./src/tekgui_load.c     \
                        ./src/tekgui_display.c  \
                        ./src/draw_form.c       \
                        ./src/my_tektext.c      \
                        ./src/my_strcmp.c       \
                        ./src/my_strncmp.c       \
			./src/response.c        \
			./src/tekline.c         \
			./src/my_strdup.c       \
			./src/my_strlen.c       \
			./src/blit_to_pix.c     \
			./src/my_atoi.c         \
			./src/load_bitmap.c     \
			./src/invert_color.c	\
			./tcore/tekpixel.c      \
			./tcore/tekfunction.c   \
			./tcore/tektext.c       \
			./src/full_pix.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
	gcc -c $< -o $@ $(FLAG)

