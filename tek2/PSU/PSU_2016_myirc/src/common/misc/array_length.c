/*
** array_length.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/misc/array_length.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 13:45:35 2017 Gauthier Cler
** Last update Wed May 31 13:45:35 2017 Gauthier Cler
*/

#include	<stdint.h>

uint8_t		array_length(char **array)
{
  uint8_t	idx;

  idx = 0;
  if (!array)
    return (0);
  while (array[idx])
    idx += 1;
  return (idx);
}