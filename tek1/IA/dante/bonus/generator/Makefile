##
## Makefile for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/
##
## Made by Buyumad Anas
## Login   <buyuma_a@anas.buyumad@epitech.eu>
##
## Started on  Tue Apr 26 16:00:27 2016 Buyumad Anas
## Last update Sat May 21 21:09:56 2016 Buyumad Anas
##

CC		=	gcc

NAME		=	perfection

CFLAGS		+=	-W -Wall -Wextra				\
			-Iinclude

SRCS		=	./srcs/main.c					\
			./srcs/misc/format.c				\
			./srcs/misc/my_atoi.c				\
			./srcs/misc/put_fd.c				\
			./srcs/misc/put_nb.c				\
			./srcs/misc/p_error.c				\
			./srcs/misc/str_len.c				\
			./srcs/misc/str_dup.c				\
			./srcs/misc/xmalloc.c				\
			./srcs/misc/super_random.c			\
			./srcs/gen/gen_map.c				\
			./srcs/generation/gen_start.c			\
			./srcs/generation/generation_over.c		\
			./srcs/generation/select_cell.c			\
			./srcs/generation/pick_neighbor.c		\
			./srcs/generation/check_directions.c		\
			./srcs/generation/get_pos.c			\
			./srcs/generation/checks.c			\
			./srcs/generation/assess_direction.c		\
			./srcs/imperfection/imperfection.c		\
			./srcs/list/add_elem.c				\
			./srcs/list/delete_elem.c			\
			./srcs/list/display_list.c			\
			./srcs/output/display.c				\
			./srcs/output/create_file.c			\
			./srcs/clean/clean_map.c			\
			./srcs/usage/display_usage.c			\
			./srcs/usage/check_arguments.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
