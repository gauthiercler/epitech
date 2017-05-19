/*
** tetris.h for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/include/tetris.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb  22 18:05:19 2016 Anas Buyumad
** Last update Fri Mar 18 23:58:47 2016 Gauthier Cler
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include	<ncurses.h>
# include	<dirent.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h>
# include	<stdio.h>
# include	<sys/ioctl.h>
# include	<termios.h>
# include	<term.h>
# include	<time.h>
# include	"macro.h"

extern int tick[2];

typedef struct	s_keymap
{
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
}		t_keymap;

typedef struct	s_map
{
  unsigned int	width;
  unsigned int	height;
}		t_map;

typedef struct	s_token
{
  char		*name;
  char		*display_name;
  char		**pos_1;
  char		**pos_2;
  char		**pos_3;
  char		**pos_4;
  unsigned int	color;
  unsigned int	width;
  unsigned int	height;
  unsigned int	state;
  bool		valid;
}		t_token;

typedef struct	s_falling
{
  t_token	*token;
  int		pos_x;
  int		pos_y;
}		t_falling;

typedef struct	s_windows
{
  WINDOW	*main_screen;
  WINDOW	*board;
  WINDOW	*next_piece;
  WINDOW	*misc;
}		t_windows;

typedef struct	s_init
{
  unsigned int	level;
  unsigned int	rows;
  unsigned int	score;
  unsigned int	highscore;
  t_map		map;
  bool		blind_mode;
  t_keymap	keymap;
  t_token	*tokens;
  int		**board;
  unsigned int	nb_tokens;
  bool		gameover;
  bool		linebroken;
  t_windows	windows;
}		t_init;

/*
**	Initialization.
*/

t_init		*gen_setup();
void		set_term_settings(int reset);
void		set_informations(t_init *setup);

/*
**	Tetriminos.
*/

int		load_tetriminos(t_init *setup);
int		fill_map(t_token *token, int i, int fd);
int		parse_info(t_token *token, char *line, int i);
int		clone_tetri(t_token *token, int i);
int		copy_4(t_token *token, int i);
int             sort_ascii(t_token *tokens, int nb_tokens);
char		*cut_ext(char *name);

/*
**	Flags Parsing.
*/

int		help_display(char *binary_name);
int		help_mode(char **av);
int		debug_mode(char **av);
void		display_debug_keys(char *str);
int		flags_parser(t_init *setup, int ac, char**av);
int		parse_action_duo(t_init *setup, char *flag, char *arg);
int		parse_action_single(t_init *setup, char *arg);
void		assess_key(t_init *setup, int mode, char *key);
int		command_action_keys(t_init *setup, int ac, char **av, int *i);
int		level_action(t_init *setup, int ac, char **av, int *i);
int		map_action(t_init *setup, char *arg);
void            debug_display(t_init *setup);
int		lexer(int ac, char **av);

/*
**	Game & Ncurse start.
*/

int		set_highscore(t_init *setup);
int		load_highscore(t_init *setup);
int		start_game(t_init *setup);
int		start_screen(t_init *setup);
int		start_color_pairs();
int		start_error(int error);
int		burn_screen(t_init *setup);
int		res_term(t_init *setup);
void		draw_window_outline(WINDOW *window, char *name);
void		im_hidden(int *i, int *x, int *y);
int		set_windows(t_init *setup);
int		**initiate_board(int width, int height);
void		display_board(int **board, int width, int height,
				  WINDOW *board_win);
int		main_loop(t_init *setup);

/*
**	Piece Init and Handling.
*/

int		init_falling_piece(t_init *setup, t_falling *falling_piece);
t_token		*select_token(t_init *setup);
int		alter_piece(t_init *setup, t_falling *falling_piece, int action);
void		action_piece(t_falling *falling_piece, int action);
void		display_next_piece(t_falling *next_piece, WINDOW *next_win);
int		init_falling_piece(t_init *setup, t_falling *falling_piece);
int		falling_piece_init(t_init *setup, t_falling *falling_piece,
				       t_falling *next_piece, bool *gen_next);
int		check_obstacle(t_init *setup, t_falling *falling_piece);

/*
**	Piece Checkings
*/

int		select_piece_part(t_token *token, int x, int y, int state);
int		call_checker(t_init *setup, t_falling *falling_piece, int action);
int		lower_check(t_init *setup, t_falling *falling_piece);
int		rotate_check(t_init *setup, t_falling *falling_piece);
int		left_check(t_init *setup, t_falling *falling_piece);
int		right_check(t_init *setup, t_falling *falling_piece);
void		check_completed_row(t_init *setup);

/*
**	Fork and Timer.
*/

void		sighandler(int sig);
void		fork_timer(int time, pid_t daddy_pid);

/*
**	Key Input.
*/

void		key_input(char *buffer, t_init *setup, t_falling *falling_piece);
void		pause_loop(char *pause, char *quit);

/*
**	Misc.
*/

char		*get_next_line(const int fd);
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int count);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void		my_putchar(char c);
char		*my_strdup(char *str);
int		my_atoi(char *str);
char		*my_strcat(char *str1, char *str2);

#endif
