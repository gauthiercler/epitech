##
## Makefile for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/
##
## Made by Buyumad Anas
## Login   <buyuma_a@anas.buyumad@epitech.eu>
##
## Started on  Sun Jun  5 20:37:20 2016 Buyumad Anas
## Last update Sun Jun  5 20:37:30 2016 Buyumad Anas
##

NAME	=	42sh

SRC	=	srcs/main.c \
		srcs/libc/get_next_line.c \
		srcs/libc/split.c \
		srcs/libc/in_string.c \
		srcs/libc/is_numeric.c \
		srcs/libc/is_alpha.c \
		srcs/libc/get_number.c \
		srcs/libc/purge.c \
		srcs/libc/io.c \
		srcs/libc/array/swap.c \
		srcs/libc/strnkcmp.c \
		srcs/libc/strings/extract.c \
		srcs/libc/strings/string_from_tab.c \
		srcs/libc/strings/strcat.c \
		srcs/libc/array/array_cpy.c \
		srcs/libc/array/array_dup.c \
		srcs/libc/array/isolate_tab.c \
		srcs/libc/array/merge_array.c \
		srcs/libc/array/array_row_cpy.c \
		srcs/libc/array/count.c \
		srcs/libc/array/up_tab.c \
		srcs/libc/array/destroy_array.c \
		srcs/libc/error/ambigious.c \
		srcs/class/builtins/cd/constructor.c \
		srcs/class/builtins/cd/get_pwd.c \
		srcs/class/builtins/cd/get_old_pwd.c \
		srcs/class/builtins/cd/get_request_type.c \
		srcs/class/builtins/cd/process_request.c \
		srcs/class/builtins/cd/run.c \
		srcs/class/builtins/cd/destructor.c \
		srcs/class/builtins/exit/constructor.c \
		srcs/class/builtins/exit/run.c \
		srcs/class/builtins/exit/checker.c \
		srcs/class/builtins/exit/get_value.c \
		srcs/class/builtins/exit/destructor.c \
		srcs/class/builtins/env/constructor.c \
		srcs/class/builtins/env/run.c \
		srcs/class/builtins/env/destructor.c \
		srcs/class/builtins/setenv/constructor.c \
		srcs/class/builtins/setenv/run.c \
		srcs/class/builtins/setenv/checker.c \
		srcs/class/builtins/setenv/destructor.c \
		srcs/class/builtins/unsetenv/constructor.c \
		srcs/class/builtins/unsetenv/run.c \
		srcs/class/builtins/unsetenv/destructor.c \
		srcs/class/builtins/echo/constructor.c \
		srcs/class/builtins/echo/run.c \
		srcs/class/builtins/echo/assess_style.c \
		srcs/class/builtins/echo/assess_flags.c \
		srcs/class/builtins/echo/display.c \
		srcs/class/builtins/echo/display_variable.c \
		srcs/class/builtins/echo/escape_sequences.c \
		srcs/class/builtins/echo/destructor.c \
		srcs/class/builtins/which/constructor.c \
		srcs/class/builtins/which/checker.c \
		srcs/class/builtins/which/run.c \
		srcs/class/builtins/which/destructor.c \
		srcs/class/builtins/alias/constructor.c \
		srcs/class/builtins/alias/run.c \
		srcs/class/builtins/alias/destructor.c \
		srcs/class/builtins/unalias/constructor.c \
		srcs/class/builtins/unalias/run.c \
		srcs/class/builtins/unalias/destructor.c \
		srcs/class/builtins/history/constructor.c \
		srcs/class/builtins/history/destructor.c \
		srcs/class/builtins/history/run.c \
		srcs/class/builtins/constructor.c \
		srcs/class/builtins/set_data.c \
		srcs/class/builtins/is_builtin.c \
		srcs/class/builtins/run.c \
		srcs/class/builtins/destructor.c \
		srcs/class/shell/constructor.c \
		srcs/class/shell/prompt.c \
		srcs/class/shell/instruction.c \
		srcs/class/shell/run.c \
		srcs/class/shell/destructor.c \
		srcs/class/line_editor/constructor.c \
		srcs/class/line_editor/build_sequences.c \
		srcs/class/line_editor/run.c \
		srcs/class/line_editor/set_terminal.c \
		srcs/class/line_editor/unset_terminal.c \
		srcs/class/line_editor/get_input.c \
		srcs/class/line_editor/generate_input.c \
		srcs/class/line_editor/assess_sequence.c \
		srcs/class/line_editor/add_character.c \
		srcs/class/line_editor/delete_character.c \
		srcs/class/line_editor/insert_character.c \
		srcs/class/line_editor/delete_end_of_line.c \
		srcs/class/line_editor/get_sequence.c \
		srcs/class/line_editor/print_sequence.c \
		srcs/class/line_editor/load_cursor_coord.c \
		srcs/class/line_editor/parse_coordinates.c \
		srcs/class/line_editor/load_terminal_size.c \
		srcs/class/line_editor/handle_left.c \
		srcs/class/line_editor/handle_right.c \
		srcs/class/line_editor/handle_up.c \
		srcs/class/line_editor/handle_down.c \
		srcs/class/line_editor/handle_backspace.c \
		srcs/class/line_editor/handle_erase.c \
		srcs/class/line_editor/handle_clear.c \
		srcs/class/line_editor/destructor.c \
		srcs/class/signal_handler/constructor.c \
		srcs/class/signal_handler/set.c \
		srcs/class/signal_handler/unset.c \
		srcs/class/signal_handler/destructor.c \
		srcs/class/env_manager/constructor.c \
		srcs/class/env_manager/add.c \
		srcs/class/env_manager/cache_clear.c \
		srcs/class/env_manager/cache.c \
		srcs/class/env_manager/display.c \
		srcs/class/env_manager/export.c \
		srcs/class/env_manager/find.c \
		srcs/class/env_manager/get.c \
		srcs/class/env_manager/import.c \
		srcs/class/env_manager/insert.c \
		srcs/class/env_manager/remove.c \
		srcs/class/env_manager/set.c \
		srcs/class/env_manager/destructor.c \
		srcs/class/env_entry/constructor.c \
		srcs/class/env_entry/compose.c \
		srcs/class/env_entry/set.c \
		srcs/class/env_entry/destructor.c \
		srcs/class/parser/constructor.c \
		srcs/class/parser/schema/constructor.c \
		srcs/class/parser/schema/find_in.c \
		srcs/class/parser/schema/get_occurence.c \
		srcs/class/parser/schema/schem_methods/commons/extract_name.c \
		srcs/class/parser/schema/schem_methods/execution/find_in.c \
		srcs/class/parser/schema/schem_methods/execution/generator.c \
		srcs/class/parser/schema/schem_methods/semicolon/generator.c \
		srcs/class/parser/schema/schem_methods/or/generator.c \
		srcs/class/parser/schema/schem_methods/and/generator.c \
		srcs/class/parser/schema/schem_methods/pipe/generator.c \
		srcs/class/parser/schema/schem_methods/simple_left/generator.c \
		srcs/class/parser/schema/schem_methods/simple_right/generator.c \
		srcs/class/parser/schema/schem_methods/double_right/generator.c \
		srcs/class/parser/schema/schem_methods/double_left/generator.c \
		srcs/class/parser/schema/destructor.c \
		srcs/class/parser/generate.c \
		srcs/class/parser/import.c \
		srcs/class/parser/destructor.c \
		srcs/class/command/constructor.c \
		srcs/class/parser/explode.c \
		srcs/class/parser/get_schema.c \
		srcs/class/command/run.c \
		srcs/class/command/research_path.c \
		srcs/class/command/is_relative.c \
		srcs/class/command/exec.c \
		srcs/class/command/semicolon/run.c \
		srcs/class/command/pipe/run.c \
		srcs/class/command/simple_left/run.c \
		srcs/class/command/simple_right/run.c \
		srcs/class/command/double_right/run.c \
		srcs/class/command/double_left/run.c \
		srcs/class/command/and/run.c \
		srcs/class/command/or/run.c \
		srcs/class/command/destructor.c \
		srcs/class/command/common/terminate.c \
		srcs/class/history_manager/add.c \
		srcs/class/history_manager/constructor.c \
		srcs/class/history_manager/destructor.c \
		srcs/class/history_manager/display.c \
		srcs/class/history_manager/clear.c \
		srcs/class/history_manager/init_option.c \
		srcs/class/history_manager/sort.c \
		srcs/class/history_manager/get.c \
		srcs/class/history_manager/insert.c \
		srcs/class/history_manager/import.c \
		srcs/class/history_manager/export.c \
		srcs/class/history_manager/merge.c \
		srcs/class/history_manager/run.c \
		srcs/class/history_manager/replacer/init.c \
		srcs/class/history_manager/replacer/run.c \
		srcs/class/history_manager/replacer/set.c \
		srcs/class/history_entry/construct.c \
		srcs/class/history_entry/export.c \
		srcs/class/history_entry/destructor.c \
		srcs/class/history_entry/display.c \
		srcs/class/alias_manager/constructor.c \
		srcs/class/alias_manager/display.c \
		srcs/class/alias_manager/get.c \
		srcs/class/alias_manager/add.c \
		srcs/class/alias_manager/destructor.c \
		srcs/class/alias_entry/constructor.c \
		srcs/class/alias_entry/display.c \
		srcs/class/alias_entry/destructor.c


OBJ	=	$(SRC:.c=.o)

CC	=	gcc

LIB	=	-lncurses

CFLAGS	+=	-W -Wall -Wextra -Iincludes

DEBUG	=	no

ifeq ($(DEBUG),yes)
	CFLAGS	+=	-g -ggdb3
endif

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIB)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
