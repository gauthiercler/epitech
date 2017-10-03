/*
** error.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/error.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun May 14 19:30:54 2017 Gauthier Cler
** Last update Sun May 14 19:30:54 2017 Gauthier Cler
*/

#include	<stdbool.h>
#include	<stdio.h>

bool		display_error(const char *caller, const char *error)
{
  fprintf(stderr, "in {%s} => ", caller);
  perror(error);
  return (false);
}