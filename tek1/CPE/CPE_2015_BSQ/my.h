/*
** my.h for my in /home/cler_g/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Mon Nov 30 23:38:40 2015 Gauthier Cler
** Last update Wed Dec  9 00:41:46 2015 Gauthier Cler
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_info
{
  int	x;
  int	y;
  int	taille;
} t_info;

typedef struct s_max
{
  int	x;
  int	y;
} t_max;

int	my_strlen(char*);
int	my_getnbr(char*);
int	minus(int, int);
void	bsq(char*);
int	nb_col(char*);
int	nb_line(char*);
char	**tab_init(char**, int, int);
char	**fill_tab(char**, char*, int);
void	disp_tab(char**);
t_info	check_square(char**, t_info, int, int);
int	check_loop(char**, int, int, int);
t_max	taille_max(char**, t_max);
void	fill_square(char**, t_info);
void	find_square(char**);
t_info	check_square(char**, t_info, int, int);
int	check_loop(char**, int, int, int);
int	loop_x(char**, int, int, int);
int	loop_y(char**, int, int ,int);
void	loop_free(char**, int);

#endif
