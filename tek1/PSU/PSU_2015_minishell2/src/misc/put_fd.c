/*
** my_putstr.c for my_putstr in /home/gogo/rendu/PSU_2015_minishell2/src/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 16 09:16:24 2016 Gauthier Cler
** Last update Tue Mar 29 16:29:49 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"mysh.h"

int		put_fd(int fd, char *str)
{
  write(fd, str, my_strlen(str));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
