/*
** destroy_tab.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/destroy_tab.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 12:41:05 2016 Antoine FORET
** Last update Sun Jun  5 18:34:46 2016 Gauthier Cler
*/

#include	<stdlib.h>

/*
** Free memory used by an array
** @params array to free
** @return void
*/
void		destroy_array(char **tab)
{
  unsigned int	index;

  index = 0;
  if (tab != NULL)
    {
      while (tab[index] != NULL)
	free(tab[index++]);
      free(tab);
    }
}
