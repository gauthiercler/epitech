##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Wed Apr 05 10:00:28 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:02:41 2017 Gauthier Cler
##

NAME=		../arcade

SRCS=		main.cpp \
			core/sources/Core.cpp \
			core/sources/DynLoader.cpp \
			libs/common/Utils.cpp \
			games/common/Clock.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra \
			-Iinterfaces \
			-Ierrors \
			-Icore/includes \
			-Ilibs/common \
			-Igames/common \
			-std=c++11 -ldl -rdynamic

CXX=		g++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
