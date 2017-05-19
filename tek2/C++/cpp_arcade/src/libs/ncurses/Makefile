##
## Makefile for Makefile in /home/gogo/rendu/tek2/cpp_nanotekspice
## 
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
## 
## Started on  Wed Feb 15 00:14:32 2017 Gauthier Cler
## Last update Sun Apr  9 03:18:46 2017 Anas Buyumad
##

CXX=		 g++

CXXFLAGS=	-std=c++11 -Wall -Wextra -g -Iincludes -I../../interfaces -I../../errors -fPIC

NAME=		../../../lib/lib_arcade_ncurses.so

SRCS=		sources/NCurses.cpp \
			sources/Terminal.cpp \
			sources/Window.cpp \
			sources/ColorHandler.cpp \
			sources/EventHandler.cpp \
			sources/Event.cpp \
			sources/CursesPicture.cpp \
			sources/CursesSprite.cpp \
			../common/Utils.cpp

OBJS=		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_MAIN)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -lncurses -shared

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
