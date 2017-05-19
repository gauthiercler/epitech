/*
** read_to_list.c for read_to_list in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Wed Nov 25 23:52:32 2015 Gauthier Cler
** Last update Sun Nov 29 18:23:10 2015 Gauthier Cler
*/

#include "info.h"

char	*my_strdup(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str);
  res = malloc(sizeof(char) * j + 1);
  res[j] = '\0';
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  return (res);
}

void	fill_info(struct stat c, int i, t_list *file)
{
  struct passwd	*d;
  struct group	*e;
  int	tmp;

  file[i].size = c.st_size;
  file[i].rights = c.st_mode;
  file[i].link = c.st_nlink;
  file[i].time_int = c.st_mtime;
  file[i].time = my_time(ctime(&c.st_mtime));
  d = getpwuid(c.st_uid);
  e = getgrgid(c.st_gid);
  file[i].uid = my_strdup(d->pw_name);
  file[i].gid = my_strdup(e->gr_name);
}

char	*fusion(char *s1, char *s2)
{
  char	*str;
  int	i;
  int	j;

  str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
  str[my_strlen(s1) + my_strlen(s2) + 2] = '\0';
  i = 0;
  j = 0;
  while (s1[j])
    {
      str[i] = s1[j];
      j++;
      i++;
    }
  j = 0;
  str[i] = '/';
  i++;
  while (s2[j])
    {
      str[i] = s2[j];
      j++;
      i++;
    }
  return (str);
}

int	read_to_list(char *av, t_list *file, t_flags flags)
{
  struct dirent	*b;
  struct stat	c;
  char	*str;
  DIR	*a;
  int	i;
  int	blocks;

  blocks = 0;
  i = 0;
  a = opendir(av);
  b = readdir(a);
  while (b != NULL)
    {
      file[i].name = b->d_name;
      str = fusion(av, b->d_name);
      lstat(str, &c);
      fill_info(c, i, file);
      blocks = add_blocks(file[i].name[0], blocks, c.st_blocks);
      file = add_link(str, c.st_size, file, i);
      b = readdir(a);
      i++;
    }
  file[0].blocks = blocks;
  file[0].name_folder = av;
  return (i);
}

void	disp_blocks(int blocks)
{
  my_putstr("total ");
  my_put_nbr(blocks);
  my_putchar('\n');
}
