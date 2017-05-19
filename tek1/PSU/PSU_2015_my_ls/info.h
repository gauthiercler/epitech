/*
** info.h for indo in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Nov 24 13:20:03 2015 Gauthier Cler
** Last update Sun Nov 29 18:22:57 2015 Gauthier Cler
*/

#ifndef INFO_H_
#define INFO_H_
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>

typedef struct s_list
{
  char	*name;
  int	size;
  int	rights;
  char	*droits;
  int	link;
  char	*link_name;
  char	*uid;
  char	*gid;
  int	blocks;
  int	time_int;
  char	*time;
  char	*name_folder;
} t_list;

typedef struct s_flags
{
  int	l;
  int	r;
  int	t;
  int	d;
  int	R;
} t_flags;

void disp_ls(t_list*, int);
void droits_types(t_list *, int);
void droits(t_list*, int);
void my_putchar(char);
void my_putstr(char*);
int my_strlen(char*);
char *my_strdup(char*);
void fill_info(struct stat, int, t_list*);
char *fusion(char*, char*);
int read_to_list(char*, t_list*, t_flags);
int nb_fichier(char*);
void sort_ascii(t_list*, int);
int my_strcmp(char*, char*);
t_flags get_flags(char**, t_flags);
t_flags get_flags_loop(int, int, char**, t_flags);
char *my_time(char*);
void disp_simple(t_list*, int);
char **check_av(int*, char**, int);
int nb_arg(char**, int);
void cases(t_list*, t_flags, int, int);
t_list *sort_time(t_list*, int);
int check_sort_time(t_list*, int);
void disp_blocks(int);
t_list *reverse_list(t_list*, int);
void error_name(char*);
int add_blocks(char, int, int);
t_list *add_link(char*, int, t_list*, int);

#endif
