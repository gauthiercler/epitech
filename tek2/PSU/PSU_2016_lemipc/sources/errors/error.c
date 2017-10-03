/*
** error.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/errors/error.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 09:50:56 2017 Gauthier Cler
** Last update Wed Mar 22 09:50:56 2017 Gauthier Cler
*/

#include	<errno.h>
#include	<string.h>
#include	<stdio.h>
#include	"lem_ipc.h"

bool		custom_error(const char *error)
{
  fprintf(stderr, "%s\n", error);
  return (false);
}

bool		display_error(const char *error)
{
  fprintf(stderr, "%s: %s\n", error, strerror(errno));
  return (false);
}