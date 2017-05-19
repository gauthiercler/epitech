##
## Makefile for Makefile in /home/gogo/rendu/tek2/cpp_nanotekspice
## 
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
## 
## Started on  Wed Feb 15 00:14:32 2017 Gauthier Cler
## Last update Thu Feb 23 15:20:04 2017 Gauthier Cler
##

CXX		= g++

CXXFLAGS	= -std=c++11 -Wall -Wextra -I.

LIB		= libnanotekspice.a

NAME		= nanotekspice

SRCS		= sources/interfaces/IParser.cpp \
		sources/classes/parser/Parser.cpp \
		sources/interfaces/IComponent.cpp \
		sources/classes/AComponent.cpp \
		sources/classes/Pin.cpp \
		sources/classes/misc/Misc.cpp \
		sources/classes/core/Core.cpp \
		sources/classes/components/C4001.cpp \
		sources/classes/components/C4008.cpp \
		sources/classes/components/C4011.cpp \
		sources/classes/components/C4013.cpp \
		sources/classes/components/C4017.cpp \
		sources/classes/components/C4030.cpp \
		sources/classes/components/C4040.cpp \
		sources/classes/components/C4069.cpp \
		sources/classes/components/C4071.cpp \
		sources/classes/components/C4081.cpp \
		sources/classes/components/C4094.cpp \
		sources/classes/components/C4514.cpp \
		sources/classes/components/C4801.cpp \
		sources/classes/components/C2716.cpp \
		sources/classes/components/True.cpp \
		sources/classes/components/False.cpp \
		sources/classes/components/INPUT.cpp \
		sources/classes/components/OUTPUT.cpp \
		sources/classes/components/CLOCK.cpp \
		sources/classes/components/FULL_ADDER.cpp \
		sources/classes/components/D_FLIP_FLOP.cpp \
		sources/classes/components/gates/AND.cpp \
		sources/classes/components/gates/NAND.cpp \
		sources/classes/components/gates/OR.cpp \
		sources/classes/components/gates/NOR.cpp \
		sources/classes/components/gates/XOR.cpp \
		sources/classes/components/gates/NOT.cpp \
		sources/classes/components/gates/FLIP_FLOP.cpp

MAIN		= sources/main.cpp

OBJS		= $(SRCS:.cpp=.o)

OBJS_MAIN	= $(MAIN:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(OBJS_MAIN)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

clean:
	rm -f $(OBJS) $(OBJS_MAIN)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re:	fclean all
