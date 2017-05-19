##
## Makefile for asm in /home/houzet_j/rendu/CPE_2015_corewar/asm
## 
## Made by Julien HOUZET
## Login   <houzet_j@epitech.net>
## 
## Started on  Sun Mar 27 22:08:47 2016 Julien HOUZET
## Last update Thu Apr  7 14:27:27 2016 Gauthier Cler
##

CC		=	gcc

NAME		=	asm/asm

CFLAGS		+=	-W -Wall -Wextra -Iasm/include

RM		=	rm -f

SRCS		=	./asm/srcs/main.c					\
			./asm/srcs/get_next_line.c				\
			./asm/srcs/opening/open.c				\
			./asm/srcs/complex/complex.c				\
			./asm/srcs/complex/check_macros.c			\
			./asm/srcs/misc/my_strlen.c				\
			./asm/srcs/misc/put_fd.c				\
			./asm/srcs/misc/my_strdup.c				\
			./asm/srcs/misc/put_nb.c				\
			./asm/srcs/misc/format.c				\
			./asm/srcs/initialization/initialize.c			\
			./asm/srcs/delete/delete_asm.c				\
			./asm/srcs/labels/find_labels.c				\
			./asm/srcs/labels/is_label.c				\
			./asm/srcs/labels/get_label.c				\
			./asm/srcs/labels/add_label.c				\
			./asm/srcs/labels/check_label/check_label.c		\
			./asm/srcs/process/process_file.c			\
			./asm/srcs/parser/parser.c				\
			./asm/srcs/parser/parse_param.c				\
			./asm/srcs/parser/remove_end.c				\
			./asm/srcs/misc/my_strncpy.c				\
			./asm/srcs/misc/my_strcmp.c				\
			./asm/srcs/misc/my_getnbr.c				\
			./asm/srcs/initialization/init_arg/init_add.c		\
			./asm/srcs/initialization/init_arg/init_aff.c		\
			./asm/srcs/initialization/init_arg/init_and.c		\
			./asm/srcs/initialization/init_arg/init_fork.c		\
			./asm/srcs/initialization/init_arg/init_ld.c		\
			./asm/srcs/initialization/init_arg/init_ldi.c		\
			./asm/srcs/initialization/init_arg/init_lfork.c		\
			./asm/srcs/initialization/init_arg/init_live.c		\
			./asm/srcs/initialization/init_arg/init_lld.c		\
			./asm/srcs/initialization/init_arg/init_lldi.c		\
			./asm/srcs/initialization/init_arg/init_or.c		\
			./asm/srcs/initialization/init_arg/init_st.c		\
			./asm/srcs/initialization/init_arg/init_sti.c		\
			./asm/srcs/initialization/init_arg/init_sub.c		\
			./asm/srcs/initialization/init_arg/init_xor.c		\
			./asm/srcs/initialization/init_arg/init_zjmp.c		\
			./asm/srcs/count_bytes/count_bytes.c			\
			./asm/srcs/count_bytes/add_args_size.c			\
			./asm/srcs/count_bytes/count_total.c			\
			./asm/srcs/get_type/get_type.c				\
			./asm/srcs/line_assigner/line_assigner.c		\
			./asm/srcs/get_value/get_value.c			\
			./asm/srcs/get_type/get_lab.c				\
			./asm/srcs/get_label_name/get_label_name.c		\
			./asm/srcs/lexer/lexer.c				\
			./asm/srcs/header/get_header.c				\
			./asm/srcs/header/get_champ_name.c			\
			./asm/srcs/header/get_champ_comment.c			\
			./asm/srcs/header/clear_buffer.c			\
			./asm/srcs/compiler/compiler.c				\
			./asm/srcs/compiler/open_cor.c				\
			./asm/srcs/compiler/compile_champ.c			\
			./asm/srcs/compiler/compile_instruction.c		\
			./asm/srcs/compiler/compile_octets.c			\
			./asm/srcs/compiler/write_coding_octet.c		\
			./asm/srcs/compiler/find_label_address.c		\
			./asm/srcs/compiler/compile_arg.c			\
			./asm/srcs/compiler/reverse_integer.c

OBJS		=	$(SRCS:.c=.o)

LIB		=

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
