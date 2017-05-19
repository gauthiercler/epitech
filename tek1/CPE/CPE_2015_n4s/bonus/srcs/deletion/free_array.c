/*
** free_array.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/deletion/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 16:19:11 2016 Buyumad Anas
** Last update Fri May 27 00:01:28 2016 Gauthier Cler
*/

#include	<stdlib.h>

void		free_array(char **array)
{
  int		index;

  index = 0;
  while (array[index])
    {
      free(array[index]);
      index += 1;
    }
  free(array);
}
