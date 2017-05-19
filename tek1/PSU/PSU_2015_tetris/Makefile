##
## Makefile for tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris
## 
## Made by Anas Buyumad
## Login   <anas.buyumad@epitech.eu>
## 
## Started on  Thu Mar 17 18:27:54 2016 Anas Buyumad
## Last update Thu Mar 17 19:44:51 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	tetris

CFLAGS		+=	-W -Wall -Wextra -Iinclude

SRCS		=	./srcs/main.c					\
			./srcs/parsing/get_next_line.c			\
			./srcs/parsing/flags/action_keys.c		\
			./srcs/parsing/flags/flags_parser.c		\
			./srcs/parsing/flags/help.c			\
			./srcs/parsing/flags/debug_mode.c		\
			./srcs/parsing/flags/parse_action_duo.c		\
			./srcs/parsing/flags/parse_action_single.c	\
			./srcs/parsing/flags/level.c			\
			./srcs/parsing/flags/map_size.c			\
			./srcs/data_manipulation/key_assesment.c	\
			./srcs/terminal_settings/set_settings.c		\
			./srcs/initialisation/init_generation.c		\
			./srcs/game/start.c				\
			./srcs/game/main_loop.c				\
			./srcs/game/timer/timer.c			\
			./srcs/game/board/check_row.c			\
			./srcs/misc/my_strcmp.c				\
			./srcs/misc/my_strncmp.c			\
			./srcs/misc/my_strlen.c				\
			./srcs/misc/my_strdup.c				\
			./srcs/misc/my_putstr.c				\
			./srcs/misc/my_putchar.c			\
			./srcs/misc/my_put_nbr.c			\
			./srcs/misc/my_strcat.c				\
			./srcs/misc/my_atoi.c				\
			./srcs/debug/debug_display.c			\
			./srcs/debug/key_display.c			\
			./srcs/parsing/tetriminos/tetriminos.c		\
			./srcs/parsing/tetriminos/clone_tetri.c		\
			./srcs/parsing/tetriminos/clone_tetri2.c	\
			./srcs/parsing/tetriminos/sort.c		\
			./srcs/parsing/tetriminos/parse.c		\
			./srcs/game/layout/draw_outline.c		\
			./srcs/game/layout/set_windows.c		\
			./srcs/game/board/board_initialization.c	\
			./srcs/game/board/display_board.c		\
			./srcs/game/pieces/alter_piece.c		\
			./srcs/game/pieces/select_piece_part.c		\
			./srcs/game/pieces/action_piece.c		\
			./srcs/game/pieces/checkings/call_checker.c	\
			./srcs/game/pieces/checkings/lower_check.c	\
			./srcs/game/pieces/checkings/rotate_check.c	\
			./srcs/game/pieces/checkings/left_check.c	\
			./srcs/game/pieces/checkings/right_check.c	\
			./srcs/game/layout/draw_next_piece.c		\
			./srcs/game/layout/set_informations.c		\
			./srcs/game/highscore/highscore.c		\
			./srcs/initialisation/falling_piece_init.c	\
			./srcs/game/input/input.c			\
			./srcs/game/input/pause.c			\
			./srcs/parsing/flags/pre_parsing.c		\
			./srcs/game/layout/resize.c

OBJS		=	$(SRCS:.c=.o)

LIB		=	-lncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
