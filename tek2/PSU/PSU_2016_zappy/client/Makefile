##
## Makefile for client in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy
## 
## Made by clement
## Login   <clement.nancelle@epitech.eu>
## 
## Started on  Fri Jun 23 13:07:13 2017 clement
## Last update Fri Jun 23 13:07:14 2017 clement
##

CXX=				g++

NAME=				zappy_client

MV=			mv

CXXFLAGS=			-Iincludes -Wall -Wextra -std=c++14

SRCS=				sources/main.cpp \
                 	sources/Core.cpp \
                 	sources/drawable/Rect.cpp \
                 	sources/drawable/Sprite.cpp \
                 	sources/drawable/Text.cpp \
                 	sources/game/AEntity.cpp \
                 	sources/game/Deraumere.cpp \
                 	sources/game/Egg.cpp \
                 	sources/game/Food.cpp \
                 	sources/game/Game.cpp \
                 	sources/game/Chat.cpp \
                 	sources/game/Incantation.cpp \
                 	sources/game/Inventory.cpp \
                 	sources/game/Linemate.cpp \
                 	sources/game/Map.cpp \
                 	sources/game/Material.cpp \
                 	sources/game/Mendiane.cpp \
                 	sources/game/Menu.cpp \
                 	sources/game/Phiras.cpp \
                 	sources/game/Player.cpp \
                 	sources/game/Sibur.cpp \
                 	sources/game/Thystame.cpp \
                 	sources/game/Tiles.cpp \
                 	sources/managers/Engine.cpp \
                 	sources/managers/EventManager.cpp \
                 	sources/managers/RessourcesManager.cpp \
                 	sources/managers/SoundManager.cpp \
                 	sources/managers/WindowManager.cpp \
                 	sources/managers/Wrapper.cpp \
                 	sources/server/Buffer.cpp \
                 	sources/server/Parser.cpp \
                 	sources/server/Socket.cpp \
                 	sources/utils/Color.cpp \
                 	sources/utils/Position.cpp \
                 	sources/utils/Random.cpp \
                 	sources/utils/Size.cpp \
                 	sources/utils/Utils.cpp

OBJS=				$(SRCS:.cpp=.o)

RM=					rm -rf

ifeq ($(DEBUG), yes)
CXXFLAGS+=			-g
endif

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CXX) $(OBJS) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
					mv $(NAME) ..

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)
					$(RM) ../$(NAME)

re:					fclean all

%.o:				%.c
					$(CXX) -c $< -o $@ $(CXXFLAGS)
