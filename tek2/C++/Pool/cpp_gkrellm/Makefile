##
## Makefile for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Makefile
##
## Made by Antoine FORET
## Login   <antoine.foret@epitech.eu>
##
## Started on  Sun Jan 22 08:55:17 2017 Antoine FORET
## Last update Sun Jan 22 08:55:17 2017 Antoine FORET
##

NAME	= JetBrainsMonitor

CXX=	g++

SRCS	= main.cpp \
	Utils/Utils.cpp \
	Modules/BatteryModule.cpp \
	Modules/DateTimeModule.cpp \
	Modules/FlyModule.cpp \
	Modules/MemoryModule.cpp \
	Modules/NetworkModule.cpp \
	Modules/ProcessorModule.cpp \
	Modules/SystemModule.cpp \
	Modules/UserModule.cpp \
	Graphics/NCurses/NCursesEngine.cpp \
	Graphics/NCurses/Classes/Screen.cpp \
	Graphics/SFMLEngine/SFMLEngine.cpp \
	Env/Env.cpp \
	Core/Core.cpp \
	Config/Config.cpp \
	Charts/Chart.cpp


OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS	= -Wall -Wextra -W -I. -std=c++11 \
		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lncurses

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all