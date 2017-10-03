/*
** main.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/server/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 22 11:15:38 2017 Gauthier Cler
** Last update Mon May 22 11:15:38 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"server/args_handler.h"
#include	"server/server.h"

bool		operational = true;

int		main(int argc, const char *argv[])
{
  if (!handle_args(argc, argv) ||
    !run_server((uint16_t)atoi(argv[1])))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}