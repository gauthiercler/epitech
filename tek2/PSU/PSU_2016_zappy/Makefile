##
## Makefile for zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy
## 
## Made by Anas Buyumad
## Login   <anas.buyumad@epitech.eu>
## 
## Started on  Mon Jun 19 15:51:30 2017 Anas Buyumad
## Last update Mon Jun 19 15:59:54 2017 Anas Buyumad
##

all: zappy_lib_cextended zappy_lib_cnetwork zappy_server zappy_client zappy_ai

zappy_lib_cextended:
	make -C lib/cextended

zappy_lib_cnetwork:
	make -C lib/cnetwork

zappy_ai:
	make -C ai

zappy_server: zappy_lib_cextended zappy_lib_cnetwork
	make -C server

zappy_client:
	make -C client

clean_server: clean_cextended clean_cnetwork
	make clean -C server

fclean_server: fclean_cextended fclean_cnetwork
	make fclean -C server

clean_client:
	make clean -C client

fclean_client:
	make fclean -C client

clean_ai:
	make clean -C ai

fclean_ai:
	make fclean -C ai

clean_cextended:
	make clean -C lib/cextended

fclean_cextended:
	make fclean -C lib/cextended

clean_cnetwork:
	make clean -C lib/cnetwork

fclean_cnetwork:
	make fclean -C lib/cnetwork

clean: clean_server clean_cextended clean_cnetwork clean_client clean_ai

fclean : clean fclean_cextended fclean_cnetwork fclean_server fclean_client fclean_ai

re: fclean all

