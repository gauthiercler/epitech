/*
** count.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/count.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 11:24:18 2016 Antoine FORET
** Last update Sun Jun  5 18:34:40 2016 Gauthier Cler
*/

#include	<stddef.h>

/*
** Count number of entry in an array
** @params array to count
** @return size of the given array
*/
size_t		count(char **tab)
{
  size_t	size;

  if (tab == NULL)
    return (0);
  size = 0;
  while (tab[size] != NULL)
    size++;
  return (size);
}
