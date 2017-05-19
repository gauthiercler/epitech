##
## Makefile for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/Makefile
##
## Made by Vincent DUSAUTOIR
## Login   <vincent.dusautoir@epitech.eu>
##
## Started on  Sun Mar 19 20:17:38 2017 Vincent DUSAUTOIR
## Last update Sun Apr  9 01:04:43 2017 Gauthier Cler
##

NAME=		../../../lib/lib_arcade_sfml.so

SRCS=		sources/Sfml.cpp \
			sources/SfmlFrame.cpp \
			sources/SfmlSound.cpp \
			sources/SfmlPicture.cpp \
			sources/SfmlSprite.cpp \
			sources/SfmlEvent.cpp \
			../common/Utils.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS+=	-W -Wall -Wextra \
			-I../../interfaces \
			-I../../errors \
			-I../common \
			-Iincludes \
			-std=c++11

LD_FLAGS=	-lsfml-graphics \
            -lsfml-window \
            -lsfml-system \
            -lsfml-audio \

CXX=		g++ -fPIC

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS) $(LD_FLAGS) -shared

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
