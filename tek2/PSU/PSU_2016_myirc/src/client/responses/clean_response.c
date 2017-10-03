/*
** clean_response.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/clean_response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 21:33:11 2017 Gauthier Cler
** Last update Sun Jun 04 21:33:12 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"client/structures.h"

void		clean_response(t_response *response)
{
  if (response->args)
  {
    free(response->args);
    response->args = NULL;
  }
}