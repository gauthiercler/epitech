/*
** free_array.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/misc/free_array.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 10 13:37:54 2017 Anas Buyumad
** Last update Sat Jun 10 13:37:54 2017 Anas Buyumad
*/

#include	<stdlib.h>

void		free_array(char **array)
{
  size_t	iterator;

  iterator = 0;
  if (array)
  {
    while (array[iterator])
    {
      if (array[iterator])
	free(array[iterator]);
      iterator += 1;
    }
    free(array);
  }
  array = NULL;
}