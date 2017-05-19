##
## Makefile for Makefile in /home/cler_g/rendu/CPE_2015_Pushswap
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.net>
## 
## Started on  Thu Nov 19 18:57:59 2015 Gauthier Cler
## Last update Sun Nov 22 14:36:56 2015 Gauthier Cler
##


CC = gcc

NAME = push_swap

RM = rm -f

SRCS = 	pushswap.c	\
	sa.c	\
	sb.c	\
	ss.c	\
	pa.c	\
	pb.c	\
	ra.c	\
	rb.c	\
	rr.c	\
	rra.c	\
	rrb.c	\
	rrr.c	\
	liste.c		\
	liste2.c	\
	my_strlen.c	\
	my_putstr.c	\
	my_put_nbr.c	\
	my_putchar.c	\
	my_getnbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I./

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
