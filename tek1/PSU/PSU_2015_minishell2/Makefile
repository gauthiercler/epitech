##
## Makefile for minishell1 in /home/gogo/rendu/PSU_2015_minishell2
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Wed Mar 16 08:36:56 2016 Gauthier Cler
## Last update Mon Apr 18 13:16:19 2016 Gauthier Cler
##

CC = gcc

NAME = mysh

RM = rm -f

SRCS =	./src/main.c				\
	./src/get_next_line.c			\
	./src/misc/misc.c			\
	./src/misc/disp_prompt.c		\
	./src/misc/signal_handler.c		\
	./src/misc/my_strcpy.c			\
	./src/misc/put_fd.c			\
	./src/misc/put_nb.c			\
	./src/misc/my_strlen.c			\
	./src/misc/my_strcat.c			\
	./src/misc/my_strdup.c			\
	./src/misc/my_strcmp.c			\
	./src/misc/my_strncmp.c			\
	./src/misc/format.c			\
	./src/misc/is_empty.c			\
	./src/misc/my_atoi.c			\
	./src/misc/is_num.c			\
	./src/misc/xmalloc.c			\
	./src/env/gen_path.c			\
	./src/env/check_env.c			\
	./src/env/disp_env.c			\
	./src/env/clone_env.c			\
	./src/env/set_env.c			\
	./src/env/unset_env.c			\
	./src/cmd/command_finder.c		\
	./src/cmd/my_exit.c			\
	./src/cmd/my_cd.c			\
	./src/cmd/path_exec.c			\
	./src/cmd/current_dir_exec.c		\
	./src/cmd/launch_command.c		\
	./src/parsing/my_str_to_wordtab.c	\
	./src/parsing/separator_to_tab.c	\
	./src/clean/free_tab.c			\
	./src/pipe/check_pipe.c			\
	./src/pipe/pipe_command.c		\
	./src/pipe/exec_pipe.c			\
	./src/redir/check_redir.c		\
	./src/redir/redir_command.c		\
	./src/redir/right_redir.c		\
	./src/redir/left_redir.c		\
	./src/redir/dright_redir.c		\
	./src/redir/dleft_redir.c

OBJS = $(SRCS:.c=.o)

CFLAGS += -W -Wall -Wextra -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
