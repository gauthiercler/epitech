##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/snake/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 09:25:42 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:05:21 2017 Gauthier Cler
##

NAME=		../../../games/lib_arcade_snake.so

SRCS=		sources/Snake.cpp \
			../common/ProtocolHandler.cpp \
			../common/Clock.cpp \
			../common/Input.cpp \
			../common/Scores.cpp

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
