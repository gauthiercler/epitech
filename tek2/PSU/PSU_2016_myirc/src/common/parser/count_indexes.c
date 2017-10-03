/*
** count_indexes.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/parser/count_indexes.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 15:34:43 2017 Anas Buyumad
** Last update Thu Jun 01 15:34:43 2017 Anas Buyumad
*/

#include	"common/parser.h"

uint16_t	count_indexes(char **array)
{
  uint16_t 	iterator;
  uint16_t 	nb_indexes;

  iterator = 0;
  nb_indexes = 0;
  while (array[iterator])
  {
    nb_indexes += 1;
    iterator += 1;
  }
  return (nb_indexes);
}