/*
** line_editor.h for 42sh in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 15:59:22 2016 Gauthier Cler
** Last update Sun Jun  5 21:26:04 2016 Gauthier Cler
*/

#ifndef LINE_EDITOR_H_
# define LINE_EDITOR_H_

# include		<stdbool.h>
# include		<stddef.h>
# include		<termios.h>

# ifndef NB_SEQUENCES
#  define NB_SEQUENCES	(9)
# endif

# ifndef L_KEY_LEFT
#  define L_KEY_LEFT	(0)
# endif

# ifndef L_KEY_RIGHT
#  define L_KEY_RIGHT	(1)
# endif

# ifndef L_KEY_UP
#  define L_KEY_UP	(2)
# endif

# ifndef L_KEY_DOWN
#  define L_KEY_DOWN	(3)
# endif

# ifndef L_BACKSPACE
#  define L_BACKSPACE	(4)
# endif

# ifndef L_TAB
#  define L_TAB		(5)
# endif

# ifndef L_ERASE
#  define L_ERASE	(6)
# endif

# ifndef L_CLEAR
#  define L_CLEAR	(7)
# endif

# ifndef L_EOT
#  define L_EOT		(8)
# endif

# ifndef S_TAB
#  define S_TAB		("\011")
# endif

# ifndef S_ERASE
#  define S_ERASE	("\013")
# endif

# ifndef S_CLEAR
#  define S_CLEAR	("\014")
# endif

# ifndef S_EOT
#  define S_EOT		("\004")
# endif

typedef			struct s_line_editor t_line_editor;
typedef			struct s_terminal_cf t_terminal_cf;
typedef			struct s_shell t_shell;
typedef			struct s_keys t_keys;

t_line_editor		*new_line_editor(char **env);
bool			line_editor_build_sequences(t_line_editor *self,
						    char **env);
char			*line_editor_run(t_line_editor *, t_shell *);
void			line_editor_destruct(t_line_editor *);
bool			line_editor_set_terminal(t_line_editor *);
bool			line_editor_unset_terminal(t_line_editor *);
bool			line_editor_get_input(t_line_editor *, t_shell *);
bool			line_editor_generate_input(t_line_editor *self);
size_t			line_editor_assess_sequence(t_line_editor *self,
						    unsigned char *input,
						    t_shell *);
bool			line_editor_add_character(t_line_editor *self,
						  unsigned char character);
bool			line_editor_remove_character(t_line_editor *);
bool			line_editor_insert_character(t_line_editor *self,
						     unsigned char character);
bool			line_editor_delete_end_of_line(t_line_editor *);
char			*line_editor_get_sequence(char *);
int			line_editor_print_sequence(int);
bool			line_editor_load_cursor_coordinates(t_line_editor *);
bool			line_editor_load_terminal_size(t_line_editor *self);
bool			line_editor_parse_coordinates(char *, int *);
bool			line_editor_handle_right(t_line_editor *self,
						 t_shell *);
bool			line_editor_handle_left(t_line_editor *self, t_shell *);
bool			line_editor_handle_up(t_line_editor *self, t_shell *);
bool			line_editor_handle_down(t_line_editor *self, t_shell *);
bool			line_editor_handle_backspace(t_line_editor *self,
						     t_shell *);
bool			line_editor_handle_erase(t_line_editor *self,
						 t_shell *);
bool			line_editor_handle_clear(t_line_editor *self,
						 t_shell *);
t_shell			*shell_prompt(t_shell *self);

struct			s_keys
{
  char			*sequence;
  bool			(*handle)(t_line_editor *self, t_shell *);
};

struct			s_terminal_cf
{
  struct termios	oldattr;
  struct termios	newattr;
};

struct			s_line_editor
{
  char			*(*run)(t_line_editor *, t_shell *);
  void			(*destruct)(t_line_editor *);
  bool			(*build_sequences)(t_line_editor *, char **);
  bool			(*set_terminal)(t_line_editor *);
  bool			(*unset_terminal)(t_line_editor *);
  bool			(*get_input)(t_line_editor *, t_shell *);
  bool			(*generate_input)(t_line_editor *);
  size_t		(*assess_sequence)(t_line_editor *, unsigned char *,
					   t_shell *);
  bool			(*insert_new_character)(t_line_editor *, unsigned char);
  bool			(*add_character)(t_line_editor *, unsigned char);
  bool			(*remove_character)(t_line_editor *);
  bool			(*delete_end_of_line)(t_line_editor *);
  char			*(*get_sequence)(char *);
  int			(*print_sequence)(int);
  bool			(*load_cursor_coordinates)(t_line_editor *);
  bool			(*load_terminal_size)(t_line_editor *);
  bool			(*parse_coordinates)(char *sequence, int *coords);
  t_keys		keys[NB_SEQUENCES + 1];
  char			*input;
  size_t		input_index;
  bool			reload_cursor;
  size_t		cursor_coords[2];
  bool			reload_terminal;
  size_t		terminal_size[2];
  t_terminal_cf		terminal_cf;
};

#endif
