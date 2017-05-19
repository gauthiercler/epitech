##
## Makefile for megalovania in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller
## 
## Made by Anas Buyumad
## Login   <anas.buyumad@epitech.eu>
## 
## Started on  Sat Mar 19 13:53:49 2016 Anas Buyumad
## Last update Sun Mar 20 21:07:31 2016 Anas Buyumad
##

CC		=	gcc

NAME		=	megalovania

CFLAGS		+= -W -Wall -Werror		\
		-Iinclude                       \
		-L/home/${USER}/.froot/lib/     \
		-L/usr/local/lib/               \
		-llapin                         \
		-lsfml-audio                    \
		-lsfml-graphics                 \
		-lsfml-window                   \
		-lsfml-system                   \
		-lstdc++                        \
		-lm

SRCS		=	./srcs/main.c \
			./srcs/loop/initialization.c \
			./srcs/loop/loop.c \
			./srcs/event/keys.c \
			./srcs/misc/fill.c \
			./srcs/misc/pixel.c \
			./srcs/misc/line.c \
			./srcs/misc/draw_square.c \
			./srcs/stars/draw_star.c \
			./srcs/stars/gen_stars.c \
			./srcs/misc/tektext.c \
			./srcs/front/front_draw.c \
			./srcs/sprite/draw_sprite.c \
			./srcs/sprite/peanut.c \
			./srcs/loop/loading.c \
			./srcs/loop/names.c	\
			./srcs/sample/sample.c \
			./srcs/loop/sans.c

OBJS		=	$(SRCS:.c=.o)

LIB		=

all:		$(NAME)

$(NAME):	$(OBJS)

		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
