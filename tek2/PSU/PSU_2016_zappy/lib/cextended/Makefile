##
## Makefile for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cextended/Makefile
##
## Made by Antoine FORET
## Login   <antoine.foret@epitech.eu>
##
## Started on  Sat May 13 23:00:08 2017 Antoine FORET
## Last update Sat May 13 23:00:08 2017 Antoine FORET
##

NAME=		cextended

SRCS=		srcs/array_extended/count.c			\
		srcs/circular_buffer/clear.c			\
		srcs/circular_buffer/destroy.c			\
		srcs/circular_buffer/get_pos.c			\
		srcs/circular_buffer/get_remaining_read.c	\
		srcs/circular_buffer/get_remaining_space.c	\
		srcs/circular_buffer/get_size.c			\
		srcs/circular_buffer/is_full.c			\
		srcs/circular_buffer/new.c			\
		srcs/circular_buffer/read.c			\
		srcs/circular_buffer/skip.c			\
		srcs/circular_buffer/write.c			\
		srcs/list/at.c					\
		srcs/list/back.c				\
		srcs/list/destroy.c				\
		srcs/list/dump.c				\
		srcs/list/front.c				\
		srcs/list/new.c					\
		srcs/list/pop_at.c				\
		srcs/list/pop_back.c				\
		srcs/list/pop_data.c				\
		srcs/list/pop_front.c				\
		srcs/list/push_at.c				\
		srcs/list/push_back.c				\
		srcs/list/push_front.c				\
		srcs/list/size.c				\
		srcs/list/foreach.c				\
		srcs/list/search.c				\
		srcs/string_extended/explode.c			\
		srcs/string_extended/nb_token_ahead.c		\
		srcs/string_extended/strip_extra_token.c	\
		srcs/string_extended/strpos.c			\
		srcs/circular_buffer/size_before.c		\
		srcs/string_extended/free_explode.c		\

OBJS=		$(SRCS:.c=.o)

CFLAGS=		-W -Wall -Wextra -Iincludes

all:		lib$(NAME).a

lib$(NAME).a:	$(OBJS)
		ar rcs lib$(NAME).a $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f lib$(NAME).a

re:		fclean all