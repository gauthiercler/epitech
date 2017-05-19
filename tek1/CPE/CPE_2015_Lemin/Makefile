##
## Makefile for Makefile in /home/montag_v/rendu/CPE_2015_Lemin
##
## Made by montag_v
## Login   <montag_v@epitech.net>
##
## Started on  Fri Apr 22 15:19:38 2016 montag_v
## Last update Mon Apr 25 20:42:51 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	lem_in

CFLAGS		+=	-W -Wall -Wextra -Iinclude

RM		=	rm -f

SRCS		=	./srcs/main.c					\
			./srcs/misc/get_next_line.c			\
			./srcs/misc/my_strlen.c				\
			./srcs/misc/format.c				\
			./srcs/misc/p_error.c				\
			./srcs/misc/put_fd.c				\
			./srcs/misc/put_nb.c				\
			./srcs/misc/str_len.c				\
			./srcs/misc/my_strdup.c				\
			./srcs/misc/my_atoi.c				\
			./srcs/misc/my_strcmp.c				\
			./srcs/misc/epur_str.c				\
			./srcs/misc/my_str_to_wordtab.c			\
			./srcs/misc/my_strncpy.c			\
			./srcs/misc/free_array.c			\
			./srcs/parsing/parsing.c			\
			./srcs/parsing/fill_links.c			\
			./srcs/parsing/fill_graph.c			\
			./srcs/parsing/is_room.c			\
			./srcs/parsing/is_link.c			\
			./srcs/parsing/liste.c				\
			./srcs/parsing/check_links.c			\
			./srcs/parsing/graph_links.c			\
			./srcs/dijkstra/dijkstra.c			\
			./srcs/dijkstra/evaluate.c			\
			./srcs/dijkstra/get_paths.c			\
			./srcs/dijkstra/get_node_index.c		\
			./srcs/dijkstra/evaluate_neighbors.c		\
			./srcs/dijkstra/gen_anthill.c			\
			./srcs/ant_attack/ant_attack.c			\
			./srcs/clean/clean_struct.c			\
			./srcs/clean/free_tab.c

OBJS		=	$(SRCS:.c=.o)

LIB		=

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
