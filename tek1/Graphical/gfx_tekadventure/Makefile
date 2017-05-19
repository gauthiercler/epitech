##
## Makefile for adventure in /home/montag_v/rendu/gfx_tekadventure
## 
## Made by valentin montagne
## Login   <montag_v@epitech.net>
## 
## Started on  Sun Apr 17 18:01:36 2016 valentin montagne
## Last update Sun Apr 17 22:30:42 2016 Anas Buyumad
##
##

CC		=	gcc 

NAME		=	tekadventure

CFLAGS  	+= 	-W -Wall -Wextra 			\
			-Iinclude/ 				\
			-L/home/${USER}/.froot/lib/		\
			-L/usr/local/lib/			\
			-llapin 				\
			-lsfml-audio 				\
			-lsfml-graphics				\
			-lsfml-window				\
			-lsfml-system				\
			-lstdc++				\
			-ldl					\
			-lm

SRCS		=	./srcs/main.c				\
			./srcs/loading/load_elem.c		\
			./srcs/loading/load_levels.c		\
			./srcs/loading/load_level.c		\
			./srcs/loading/load_ressources.c	\
			./srcs/loading/load_decor.c		\
			./srcs/loading/load_character.c		\
			./srcs/loading/load_menu.c		\
			./srcs/loading/load_room.c		\
			./srcs/loading/load_graphs.c		\
			./srcs/loading/fill_hitboxes.c		\
			./srcs/drawing/draw_decor.c		\
			./srcs/drawing/draw_level.c		\
			./srcs/drawing/draw_character.c		\
			./srcs/drawing/draw_room.c		\
			./srcs/graphs/graphs.c			\
			./srcs/graphs/find_path.c		\
			./srcs/graphs/move_graph_character.c	\
			./srcs/ressources/get_picture.c		\
			./srcs/misc/str_len.c			\
			./srcs/misc/format.c			\
			./srcs/misc/my_strdup.c			\
			./srcs/misc/put_fd.c			\
			./srcs/misc/put_nb.c			\
			./srcs/misc/p_error.c			\
			./srcs/misc/my_atoi.c			\
			./srcs/misc/my_strcmp.c			\
			./srcs/misc/draw/pixel.c		\
			./srcs/misc/draw/tekblit.c		\
			./srcs/events/backup_pos.c		\
			./srcs/events/click_events.c		\
			./srcs/events/click_menu.c		\
			./srcs/events/keys_events.c		\
			./srcs/events/calc_delta.c		\
			./srcs/events/tick_decor.c		\
			./srcs/events/tick_level.c		\
			./srcs/events/tick_dynamics.c		\
			./srcs/events/analyze_click.c		\
			./srcs/events/move_character.c		\
			./srcs/events/find_hitboxes.c		\
			./srcs/loop/main_loop.c			\
			./srcs/clean/clean_struct.c		\
			./srcs/clean/clean_menu.c		\
			./srcs/clean/clean_graph.c		\
			./srcs/menu/menu_loop.c			\
			./srcs/env/check_env.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
