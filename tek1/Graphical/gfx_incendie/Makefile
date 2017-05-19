##
## Makefile for makefile in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
## 
## Made by Sylvain Chaugny
## Login   <sylvain@epitech.net>
## 
## Started on  Sat Dec  5 23:59:30 2015 Sylvain Chaugny
## Last update Sun Dec  6 19:04:55 2015 Sylvain Chaugny
##

CC		=	clang
NAMEFL		=	fire
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/ -I./include
SRCFL		=	main_flames.c misc.c tekpixel.c draw.c events.c
OBJFL		=	$(SRCFL:.c=.o)

all:		$(NAMEFL)
$(NAMEFL):	$(OBJFL)
		$(CC) $(OBJFL) $(LIB) -o $(NAMEFL)
clean:
		rm -f $(OBJFL)
fclean:		clean
		rm -f $(NAMEFL)
re:		fclean all
.c.o:
	$(CC) -c $< -o $@ $(FLAG)
