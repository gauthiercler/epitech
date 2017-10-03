/*
** error.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/error.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 17:27:29 2017 Gauthier Cler
** Last update Sun Apr 02 17:27:29 2017 Gauthier Cler
*/

#include	"lem_ipc.h"

void		display_sdl_error(char *error)
{
  fprintf(stderr, "%s : %s\n", error, SDL_GetError());
  exit(EXIT_FAILURE);
}