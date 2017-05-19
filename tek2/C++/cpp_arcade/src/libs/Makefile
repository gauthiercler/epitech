##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 09:42:28 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:11:27 2017 Gauthier Cler
##

all:
		mkdir -p ../../lib
		@make -C ncurses
		@make -C opengl
		@make -C sfml

clean:
		@make clean -C ncurses
		@make clean -C opengl
		@make clean -C sfml

fclean:
		@make fclean -C ncurses
		@make fclean -C opengl
		@make fclean -C sfml
		rm -rf lib

re:		fclean all
