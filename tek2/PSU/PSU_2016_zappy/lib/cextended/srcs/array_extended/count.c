/*
** count.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Extended/C/srcs/array_extended/count.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 10 09:03:23 2017 Antoine FORET
** Last update Wed May 10 09:03:23 2017 Antoine FORET
*/

#include	"array_extended.h"

size_t		count(const void **array)
{
  size_t	size;

  size = 0;
  if (array == NULL)
    return (0);
  while (array[size] != NULL)
    size += 1;
  return (size);
}