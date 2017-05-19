/*
** isolate_tab.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/isolate_tab.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 16:00:31 2016 Antoine FORET
** Last update Tue May 31 16:00:31 2016 Antoine FORET
*/

#include	<stddef.h>

/*
** Isolate a part of an array at the given size
** @params array to update, size of the first subarray
** @return void
*/
void		isolate_tab(char **tab, unsigned int size)
{
  tab[0] = tab[size + 1];
  tab[size + 1] = NULL;
}
