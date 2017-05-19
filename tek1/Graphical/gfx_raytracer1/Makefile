##
## Makefile for raytracer1 in /home/gogo/rendu/gfx_raytracer1
## 
## Made by Gauthier Cler
## Login   <cler_g@epitech.eu>
## 
## Started on  Mon Feb 29 09:55:57 2016 Gauthier Cler
## Last update Sun Mar 13 18:57:53 2016 Gauthier Cler
##

NAME		=	raytracer1
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAGS		=	-Werror -W -Wall -I/home/${USER}/.froot/include/ -Iinclude

SRC		=	./src/main.c		\
			./src/render.c		\
			./src/full_pix.c	\
			./src/load_ini.c	\
			./src/objects.c		\
			./src/raytracer.c	\
			./src/norm.c		\
			./src/intersection.c	\
			./src/calc_cos_sin.c	\
			./src/my_atof.c		\
			./src/damier.c		\
			./src/my_atoi.c		\
			./src/my_strdup.c	\
			./src/my_strlen.c	\
			./tcore/tekray.c	\
			./tcore/tekpixel.c	

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)

		@tput setaf 6
		@tput bold
		@$(CC) $(OBJ) $(FLAGS) $(LIB) -o $(NAME)
		@printf "Linking     "
		@tput setaf 6
		@printf "%s\n" $(NAME)
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

%.o:		%.c
		@tput setaf 3
		@tput bold
		@printf "Compiling   "
		@tput setaf 4
		@printf "%s\n" $(patsubst $(OBJ)/%,%,$^)
		@$(CC) $(LIB) -c -o $@ $^ $(FLAGS) -Iinclude
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

clean:
		@tput setaf 1
		@tput bold
		@printf "Removing    "
		@tput setaf 4
		@printf "object files\n" 
		@rm -f $(OBJ)
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

fclean:         clean
		@tput setaf 1
		@tput bold
		@rm -f $(NAME)
		@printf "Removing   "
		@tput setaf 4
		@printf " %s\n" $(NAME)
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2	
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

re:		fclean all

