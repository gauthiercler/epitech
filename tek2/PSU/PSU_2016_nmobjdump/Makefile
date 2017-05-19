##
## Makefile for malloc in /home/gogo/rendu/tek2/PSU_2016_nmobjdump
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.net>
##
## Started on  Mon Jan 23 21:53:37 2017 Gauthier Cler
## Last update Fri Feb 24 09:14:37 2017 Gauthier Cler
##

CC			= gcc

CFLAGS			= -Wall -Wextra -W -Werror

NM			= my_nm

$(NM): CFLAGS 		+= -Inm/include

OBJDUMP			= my_objdump

$(OBJDUMP): CFLAGS 	+= -Iobjdump/include

SRCS_NM			= ./nm/src/main.c \
			nm/src/nm.c \
			nm/src/loading.c \
			nm/src/sorting.c \
			nm/src/unloading.c \
			nm/src/init.c \
			nm/src/get_section_header.c \
			nm/src/get_sym_type.c \
			nm/src/get_symbol.c \
			nm/src/print_sym.c

SRCS_OBJDUMP		= ./objdump/src/main.c \
			objdump/src/objdump.c \
			objdump/src/loading.c \
			objdump/src/unloading.c \
			objdump/src/display_sections.c \
			objdump/src/flags.c \
			objdump/src/init_archi.c

OBJS_NM			= $(SRCS_NM:.c=.o)

OBJS_OBJDUMP		= $(SRCS_OBJDUMP:.c=.o)

DEBUG			= no

ifeq ($(DEBUG), yes)
	CFLAGS += 	-g
endif

all: nm objdump


nm: $(NM)

objdump: $(OBJDUMP)

$(NM): $(OBJS_NM)
	$(CC) $(CFLAGS) -o $(NM) $(OBJS_NM)

$(OBJDUMP): $(OBJS_OBJDUMP)
	$(CC) $(CFLAGS_OBJDUMP) -o $(OBJDUMP) $(OBJS_OBJDUMP)
clean:
	rm -f $(OBJS_NM) $(OBJS_OBJDUMP)

fclean: clean
	rm -f $(NM) $(OBJDUMP)

re:	fclean all
