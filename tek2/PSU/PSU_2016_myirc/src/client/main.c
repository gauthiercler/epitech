/*
** main.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 22 11:15:47 2017 Gauthier Cler
** Last update Mon May 22 11:15:47 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"client/client.h"

int		main()
{
  if (!run_client())
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}