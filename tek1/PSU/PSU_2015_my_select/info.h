/*
** info.h for info in /home/cler_g/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Fri Dec  4 15:04:32 2015 Gauthier Cler
** Last update Sat Dec 12 16:01:14 2015 Gauthier Cler
*/

#ifndef INFO_H_
#define INFO_H_

#include <sys/ioctl.h>
#include <curses.h>
#include <stdlib.h>

typedef struct s_info
{
  char	*name;
  int	x;
  int	y;
  bool	highlight;
} t_info;

typedef struct s_var
{
  int	cor;
  int	x;
  int	y;
} t_var;

typedef struct s_cursor
{
  int	x;
  int	y;
} t_cursor;

int	my_select(int, char**);
t_info	*fill_struct(int, char**, t_info*, struct winsize);
char	*my_strdup(char*);
t_var	init_fill_struct(t_var);
void	disp_struct(t_info*, int);
int	loop_select(t_info*, struct winsize, int, SCREEN*);
int	pos_arg_name(t_info*, t_cursor);
void	key_down(t_info*, t_cursor, struct winsize, int);
void	key_down_else(t_info*, t_cursor, struct winsize, int);
void	key_up(t_info*, t_cursor, struct winsize, int);
void	key_up_else(t_info*, t_cursor, struct winsize, int);
void	key_space(t_info*, t_cursor, struct winsize, int);
void	space_end_high(t_info*, int);
void	space_end(t_info*, int);
void	space_high(t_info*, int);
void	space(t_info*, int);
void	exit_condition(t_info*, int, int);
void	disp_arg(t_info*,int);
int	key_delete(t_info*, t_cursor, SCREEN*, int);
void	delete_next(t_info*, int, int, int);

#endif
