/*
** asm.h for asm in /home/gogo/rendu/CPE_2015_corewar/asm
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Mar 27 18:27:20 2016 Gauthier Cler
** Last update Thu Apr  7 14:11:00 2016 Gauthier Cler
*/

#ifndef ASM_H_
# define ASM_H_

/*
** -- ASM-Chars --
*/

#  include			<stdbool.h>

#  define COMMENT_CHAR		'#'
#  define LABEL_CHAR		':'
#  define DIRECT_CHAR		'%'
#  define SEPARATOR_CHAR	','
#  define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

/*
** -- ASM-Header --
*/

#  define NAME_CMD_STRING	".name"
#  define COMMENT_CMD_STRING	".comment"
#  define PROG_NAME_LENGTH	(128)
#  define COMMENT_LENGTH	(2048)

/*
** -- Magic-Number --
*/

#  define COREWAR_EXEC_MAGIC	0xea83f3

/*
** -- ASM-Sizes --
*/

#  define IND_SIZE		(2)
#  define REG_SIZE		(4)
#  define DIR_SIZE		REG_SIZE

/*
** -- VM-Sizes --
*/

#  define REG_NUMBER		(16)

/*
** -- Types --
*/

#  define BAD			(-1)
#  define INS			(0)
#  define REG			(1)
#  define IND			(2)
#  define DIR			(3)
#  define DLAB			(4)
#  define ILAB			(5)

/*
** -- Return Values --
*/

#  define SUCCESS		(0)
#  define ERROR			(1)
#  define LABEL_ERROR		(2)
#  define HEADER_ERROR		(3)

/*
** -- Get_next_line --
*/

#  define READ_SIZE		(4096)

/*
** -- ASM-Unions --
*/

typedef struct s_label		t_label;
typedef struct s_arg		t_arg;
typedef struct s_line		t_line;

typedef struct			s_label
{
  char				*name;
  int				line;
  int				address;
  t_label			*next;
}				t_label;

/*
** -- Linked List for lines. --
*/

typedef struct			s_arg
{
  char				*name;
  int				type;
  int				value;
  int				o_size;
  char				*label_name;
  int				address;
}				t_arg;

typedef struct			s_line
{
  bool				is_label;
  int				nb_args;
  int				nb_line;
  t_arg				*args;
  t_line			*next;
}				t_line;

typedef struct			s_header
{
   int				magic_number;
   char				prog_name[PROG_NAME_LENGTH + 1];
   int				prog_size;
   char				comment[COMMENT_LENGTH + 1];
}				t_header;

/*
** -- Main asm structure. --
*/

typedef struct			s_instruction
{
  char				*name;
  int				nb_args;
  char				**tab;
}				t_instruction;

typedef struct			s_asm
{
  t_label			*labels;
  t_line			*lines;
  t_instruction			instructions[17];
  t_header			header;
  int				header_end;
}				t_asm;

/*
** -- Functions --
*/

/*
** -- DEV --
** Please keep the functions prototypes organized in subcategories.
*/

/*
** -- Main Stuff --
*/

int				initialize_data(t_asm *data);
int				complex(char *filename);
int				macros_are_valid(void);

/*
** -- Files handling --
*/

int				get_fd(char *filename);

/*
** -- Labels finding --
*/

int				find_labels(int fd, t_label **labels,
					    int header_end);
int				is_label(t_label **labels, char *line,
					 int nb_line);
int				is_char_valid(char c);
int				get_label(t_label **labels, char *str,
					  int nb_line, int position);
int				add_label(t_label **labels, char *name,
					  int line);
void				display_labels(t_label *labels);
void				display_lines(t_line *lines);
int				check_label(t_label *labels, int nb_line);
int				does_label_exists(t_label *labels, char *label);
void				count_all_bytes(int *prog_size,
						t_line *lines, t_label *labels);

/*
** -- Processing --
*/

int				process_file(int fd, t_asm *data);
void				add_args_size(t_line *lines);
void				count_bytes(t_arg *arg, int index);
/*
** -- Line Assigner --
*/

int				line_assigner(t_label *labels,
					      t_instruction *instructions,
					      t_line *line);

/*
** -- Line Lexer --
*/

int				line_lexer(t_instruction *instructions,
					   t_line *line);

/*
** -- Misc --
*/

int				put_fd(int fd, char *str);
int				put_nb(int fd, int nb);
int				format(int fd, char *str, ...);
int				my_strlen(char *str);
int				my_strcmp(char *s1, char *s2);
char				*my_strdup(char *str);
char				*get_next_line(const int fd);
void				my_strncpy(char *src, char *dest, int nb);
void				my_strcpy(char *src, char *dest);
int				my_getnbr(char *str);

/*
** -- Deletion --
*/

void				delete_asm(t_asm *data);

/*
** -- Header --
*/

int				get_header(int fd, t_header *header,
					   int *header_end);
int				check_space(char *line, char separator, int i);
int				get_txt(char *line, char *champ_name, int size);
int				get_champ_name(char *line, char *champ_name);
int				get_champ_comment(char *line,
						  char *champ_comment);
int				clear_buffer(int fd, char *old_line,
					     int status);

/*
** -- Parser --
*/

int				parser(t_line *line, char *line_s);
int				parse_param(t_arg *param, char *line,
					    int *index, bool first);
void				skip_spacing(char *line, int *index);
int				remove_end(t_arg *param);

/*
** -- Arg Interpreter --
*/

int				get_type(t_instruction *inst, char *arg);
int				get_lab(char *arg);
int				get_value(t_instruction *instructions,
					  char *arg, int type);
int				get_label_name(t_arg *arg);

/*
** -- Compiler --
*/

int				compiler(t_asm *data, char *filename);
int				create_file(char *name);
int				compile_champ(int fd, t_asm *data);
int				compile_instruction(int fd, t_line *line);
int				compile_arg(t_arg *arg, t_label *labels,
					    int *tab);
int				compile_octects(int fd, int nb_octets,
						int value);
int				write_coding_octet(int fd,
						   unsigned char *binary_octet);
int				find_label_address(char *name, t_label *labels,
						   int *address);
int				reverse_integer(int number);

/*
** -- Init instructions --
*/

int				init_live(t_instruction *instruction);
int				init_ld(t_instruction *instruction);
int				init_st(t_instruction *instruction);
int				init_add(t_instruction *instruction);
int				init_sub(t_instruction *instruction);
int				init_and(t_instruction *instruction);
int				init_or(t_instruction *instruction);
int				init_xor(t_instruction *instruction);
int				init_zjmp(t_instruction *instruction);
int				init_ldi(t_instruction *instruction);
int				init_sti(t_instruction *instruction);
int				init_fork(t_instruction *instruction);
int				init_lld(t_instruction *instruction);
int				init_lldi(t_instruction *instruction);
int				init_lfork(t_instruction *instruction);
int				init_aff(t_instruction *instruction);

#endif /* !ASM_H_ */
