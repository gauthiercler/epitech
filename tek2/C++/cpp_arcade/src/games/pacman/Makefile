##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/pacman/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 09:25:42 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 03:18:27 2017 Anas Buyumad
##

NAME=		../../../games/lib_arcade_pacman.so

SRCS=		sources/Pacman.cpp \
			sources/Ghost.cpp \
			sources/DFS.cpp \
			sources/AStar.cpp \
			../common/Input.cpp \
			../common/Scores.cpp \
			../common/ProtocolHandler.cpp \
			../common/Clock.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS+=	-W -Wall -Wextra \
			-I../../interfaces \
			-I../../errors \
			-Iincludes \
			-I../common \
			-std=c++11

CXX=		g++ -fPIC

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS) -shared

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
