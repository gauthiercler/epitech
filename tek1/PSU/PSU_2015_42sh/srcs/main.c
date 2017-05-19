/*
** main.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 17:30:50 2016 Vincent Dusautoir
** Last update Mon May 30 21:38:03 2016 Antoine FORET
*/

#include	"libc.h"
#include	"class/shell.h"

int		main(int ac, char **av, char **arge)
{
  t_shell	*shell;
  int		status;

  shell = new_shell(ac, av, arge);
  status = 256;
  if (shell != NULL && status >= 256)
    {
      status = shell->run(shell);
      shell->destruct(shell);
    }
  return (status);
}
