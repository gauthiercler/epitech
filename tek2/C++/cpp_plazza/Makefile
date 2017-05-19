##
## Makefile for pizza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza
## 
## Made by Anas Buyumad
## Login   <anas.buyumad@epitech.eu>
## 
## Started on  Mon Apr 10 00:26:27 2017 Anas Buyumad
## Last update Sat Apr 29 13:05:48 2017 Gauthier Cler
##

CXX=	g++

CXXFLAGS= -std=c++11 -Wall -Wextra -Iincludes

LXXFLAGS= -lpthread

NAME=	plazza

SRCS=	sources/main.cpp \
		sources/Reception.cpp \
		sources/Office.cpp \
		sources/ProcessManager.cpp \
		sources/ConnectorPipe.cpp \
		sources/CommandManager.cpp \
		sources/Command.cpp \
		sources/Utils.cpp \
		sources/Thread.cpp \
		sources/ThreadPool.cpp \
		sources/Worker.cpp \
		sources/File.cpp \
		sources/XorCypher.cpp \
		sources/CaesarCypher.cpp \
		sources/XorCracker.cpp \
		sources/ACypher.cpp \
		sources/Mutex.cpp

OBJS=	$(SRCS:.cpp=.o)

NAME_CYPHER= cypher

SRCS_CYPHER= sources/main_cypher.cpp \
			 sources/XorCypher.cpp \
			 sources/CaesarCypher.cpp \
			 sources/File.cpp \
			 sources/ACypher.cpp

OBJS_CYPHER= $(SRCS_CYPHER:.cpp=.o)

OBJS_MAIN= $(MAIN:.cpp=.o)

all: $(NAME)

ui:
	@make -C gui

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LXXFLAGS)

cypher: $(OBJS_CYPHER)
		$(CXX) $(CXXFLAGS) -o $(NAME_CYPHER) $(OBJS_CYPHER)

clean:
	rm -f $(OBJS) $(OBJS_CYPHER)
	@make clean -C gui

fclean: clean
	rm -f $(NAME) $(NAME_CYPHER)
	@make fclean -C gui

re:	fclean all
	@make re -C gui
