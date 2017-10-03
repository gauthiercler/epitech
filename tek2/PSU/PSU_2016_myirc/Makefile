##
## Makefile for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/Makefile
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Mon May 22 11:24:40 2017 Gauthier Cler
## Last update Mon May 22 11:24:40 2017 Gauthier Cler
##

NAME =		server

RM = 		rm -f

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Iinclude

all: client server

client: $(NAME_CLIENT)
server: $(NAME_SERVER)

clean:
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean : clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

re: fclean all

include server.mk
include client.mk
