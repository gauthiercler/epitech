
##
## Makefile for client in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy
## 
## Made by clement
## Login   <clement.nancelle@epitech.eu>
## 
## Started on  Fri Jun 23 13:07:13 2017 clement
## Last update Fri Jun 23 16:46:48 2017 clement
##

CXX		=	g++

MV		=	mv

NAME		=	zappy_ai

CXXFLAGS	=	-I. -Iclasses -IFSM -IFSM/event -IFSM/guards -IFSM/states -IFSM/transitions -Wall -Wextra -std=c++14

SRCS		=	main.cpp \
				classes/Parser.cpp \
            	classes/AResponse.cpp \
            	classes/Engine.cpp \
            	classes/Socket.cpp \
            	classes/IOStreamHandler.cpp \
            	classes/LevelRequirement.cpp \
            	classes/OptionHandler.cpp \
            	classes/Random.cpp \
            	classes/ResponseHandler.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -rf

ifeq ($(DEBUG), yes)
	CXXFLAGS += -g
endif

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) -pthread -lboost_system -lboost_regex -lboost_program_options -lboost_thread
		$(MV) $(NAME) ..

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all

%.o: %.c
	$(CXX) -c $< -o $@ $(CXXFLAGS)
