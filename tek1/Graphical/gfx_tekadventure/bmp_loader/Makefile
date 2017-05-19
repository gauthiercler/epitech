##
## Makefile for BmpLoader in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekgui/BmpLoader
## 
## Made by Anas Buyumad
## Login   <anas.buyumad@epitech.eu>
## 
## Started on  Sun Feb  7 15:59:13 2016 Anas Buyumad
## Last update Wed Apr 20 21:15:00 2016 Gauthier Cler
##

NAME	= BmpLoader

SRCS	= main.c \
	loading.c \
	generation.c \
	deletion.c \
	reading.c \
	checking.c \
	transposition.c	\
	format.c	\
	put_nb.c	\
	put_fd.c	\
	str_len.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -ansi -pedantic \
	-L/home/${USER}/.froot/lib/ \
	-L/usr/local/lib/ \
	-I. \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ \
	-ldl \
	-lm

all:	$(NAME)

$(NAME):	$(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
