/*
** up_tab.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/up_tab.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 16:10:57 2016 Antoine FORET
** Last update Sun Jun  5 18:35:08 2016 Gauthier Cler
*/

#include	<stddef.h>

/*
** Up some values in an upper index
** @params array to affect, size of the movement
** @return void
*/
void		up_tab(char **tab, unsigned int offset)
{
  unsigned int	index;
  char		*tmp;

  index = offset;
  while (tab[index] != NULL)
    {
      tmp = tab[index];
      tab[index] = tab[index - offset];
      tab[index - offset] = tmp;
      index++;
    }
}
