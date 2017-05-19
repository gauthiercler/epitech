##
## Makefile for cpp_santa in /home/foret_a/Lab/cpp_santa/Makefile
##
## Made by Antoine FORET
## Login   <antoine.foret@epitech.eu>
##
## Started on  Sun Jan 15 09:36:09 2017 Antoine FORET
## Last update Sun Jan 15 09:36:09 2017 Antoine FORET
##

NAME	= cpp_santa

CXX=	g++

SRCS	= Abstracts/AObject.cpp \
          	Abstracts/AToy.cpp \
          	Abstracts/AWrap.cpp \
          	Classes/Box.cpp \
          	Classes/ConveyorBeltPePeNoel.cpp \
          	Classes/Elf.cpp \
          	Classes/GiftPaper.cpp \
          	Classes/LittlePony.cpp \
          	Classes/TablePePeNoel.cpp \
          	Classes/Teddy.cpp \
          	main.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS	= -Wall -Wextra -std=c++03 -I.

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all