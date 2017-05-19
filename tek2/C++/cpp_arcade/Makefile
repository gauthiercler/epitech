##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 09:42:28 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:17:10 2017 Gauthier Cler
##

all:	
		@make -C src/games

libs:
		@make -C src/libs

arcade: all libs core

core:
		@make -C src

clean:
		@make clean -C src
		@make clean -C src/libs
		@make clean -C src/games

fclean:
		@make fclean -C src
		@make fclean -C src/libs
		@make fclean -C src/games

re:		fclean arcade
