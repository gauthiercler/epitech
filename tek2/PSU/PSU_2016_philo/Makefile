##
## Makefile for philo in /home/gogo/rendu/tek2/PSU_2016_philo
## 
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
## 
## Started on  Mon Mar  6 17:52:42 2017 Gauthier Cler
## Last update Wed Mar 15 19:54:04 2017 Anas Buyumad
##

CC			= gcc

CFLAGS			= -Wall -Wextra -W -Iincludes -L. -lriceferee -lpthread

NAME			= philo

SRCS			= sources/main.c \
			sources/error/error.c \
			sources/list/create_list.c \
			sources/list/clean_list.c \
			sources/simulation/simulation.c \
			sources/simulation/philo_think.c \
			sources/simulation/philo_sleep.c \
			sources/simulation/philo_eat.c \
			sources/simulation/philo_pick.c \
			sources/opts/opts.c

OBJS			= $(SRCS:.c=.o)

DEBUG			= no

ifeq ($(DEBUG), yes)
	CFLAGS += 	-g
endif

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
