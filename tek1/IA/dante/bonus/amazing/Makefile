##
## Makefile for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/
##
## Made by Buyumad Anas
## Login   <buyuma_a@anas.buyumad@epitech.eu>
##
## Started on  Fri Apr 29 12:01:22 2016 Buyumad Anas
## Last update Mon May 23 13:18:38 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	a-maze-ing

LIB		=	-L/usr/lib					\
			-lSDL						\
			-lSDL_image

CFLAGS		+=	-W -Wall -Wextra				\
			-Iinclude					\
			-I/usr/include/SDL/

SRCS		=	./srcs/main.c					\
			./srcs/interface/startup/start_up.c		\
			./srcs/interface/loading/load_image.c		\
			./srcs/interface/loading/load_ressources.c	\
			./srcs/interface/loading/load_buttons.c		\
			./srcs/interface/loading/load_actions.c		\
			./srcs/interface/kill/kill_data.c		\
			./srcs/interface/manipulation/blit.c		\
			./srcs/interface/drawing/draw_amazing.c		\
			./srcs/interface/drawing/draw_button.c		\
			./srcs/interface/drawing/draw_maze.c		\
			./srcs/interface/drawing/init_blit.c		\
			./srcs/interface/drawing/pixel_manip.c		\
			./srcs/interface/events/events.c		\
			./srcs/interface/events/check_hitboxes.c	\
			./srcs/interface/events/set_buttons_state.c	\
			./srcs/interface/events/click_actions.c		\
			./srcs/interface/events/generate.c		\
			./srcs/interface/events/solve.c			\
			./srcs/generator/main.c				\
			./srcs/generator/misc/format.c			\
			./srcs/generator/misc/my_atoi.c			\
			./srcs/generator/misc/put_fd.c			\
			./srcs/generator/misc/put_nb.c			\
			./srcs/generator/misc/p_error.c			\
			./srcs/generator/misc/str_len.c			\
			./srcs/generator/misc/str_dup.c			\
			./srcs/generator/misc/xmalloc.c			\
			./srcs/generator/misc/super_random.c		\
			./srcs/generator/gen/gen_map.c			\
			./srcs/generator/generation/gen_start.c		\
			./srcs/generator/generation/generation_over.c	\
			./srcs/generator/generation/select_cell.c	\
			./srcs/generator/generation/pick_neighbor.c	\
			./srcs/generator/generation/get_pos.c		\
			./srcs/generator/generation/check_directions.c	\
			./srcs/generator/generation/checks.c		\
			./srcs/generator/generation/assess_direction.c	\
			./srcs/generator/imperfection/imperfection.c	\
			./srcs/generator/list/add_elem.c		\
			./srcs/generator/list/delete_elem.c		\
			./srcs/generator/list/display_list.c		\
			./srcs/generator/output/display.c		\
			./srcs/generator/output/create_file.c		\
			./srcs/generator/clean/clean_map.c		\
			./srcs/generator/usage/display_usage.c		\
			./srcs/generator/usage/check_arguments.c	\
			./srcs/solver-depth/main.c			\
			./srcs/solver-depth/misc/my_strcmp.c		\
			./srcs/solver-depth/solve/solve.c		\
			./srcs/solver-depth/solve/get_pos.c		\
			./srcs/solver-depth/list/list.c			\
			./srcs/solver-depth/clean/clean.c		\
			./srcs/solver-depth/fill/fill.c			\
			./srcs/solver-depth/solve/gen_path.c		\
			./srcs/solver-depth/check_args/usage.c		\
			./srcs/solver-depth/check_args/check_args.c	\
			./srcs/solver-breadth/srcs/main.c		\
			./srcs/solver-breadth/srcs/solve/solve.c	\
			./srcs/solver-breadth/srcs/solve/get_pos.c	\
			./srcs/solver-breadth/srcs/list/list.c		\
			./srcs/solver-breadth/srcs/clean/clean.c	\
			./srcs/solver-breadth/srcs/fill/fill.c		\
			./srcs/solver-breadth/srcs/solve/gen_path.c	\
			./srcs/solver-astar/main.c			\
			./srcs/solver-astar/solve/solve.c		\
			./srcs/solver-astar/solve/get_pos.c		\
			./srcs/solver-astar/list/list.c			\
			./srcs/solver-astar/clean/clean.c		\
			./srcs/solver-astar/fill/fill.c			\
			./srcs/solver-astar/solve/gen_path.c		\
			./srcs/solver-astar/solve/verif.c		\
			./srcs/solver-astar/list/get_node.c


OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME) `sdl-config --cflags --libs`

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
