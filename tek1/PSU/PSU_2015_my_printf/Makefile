##
## Makefile for makefile in /home/cler_g/rendu/piscine/Piscine_C_J10/include
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
## 
## Started on  Mon Oct 12 11:01:56 2015 Gauthier Cler
## Last update Mon Nov 16 11:26:02 2015 Gauthier Cler
##

CC	= gcc

ARRC	= ar rc

RM	= rm -f

RANLIB  = ranlib

NAME	= libmy.a

SRCS	= base.c	\
	  my_put_nbr.c	\
	  my_strlen.c	\
	  base_mini.c	\
	  my_printf.c	\
	  my_put_nbr_unsigned.c	\
	  base_s.c	\
	  my_putchar.c	\
	  my_putstr.c	\
	  null.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -c $(SRCS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
