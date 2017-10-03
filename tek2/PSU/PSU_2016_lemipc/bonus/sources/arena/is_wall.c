/*
** is_wall.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/sources/arena/is_wall.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Mar 31 17:35:34 2017 Gauthier Cler
** Last update Fri Mar 31 17:35:34 2017 Gauthier Cler
*/

#include	<string.h>
#include	"lem_ipc.h"

bool		is_wall(char cell)
{
  if (strchr(ARENA_WALL, cell) == NULL)
    return (false);
  return (true);
}