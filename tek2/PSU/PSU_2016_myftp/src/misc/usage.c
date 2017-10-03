/*
** usage.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/usage.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 14:04:23 2017 Gauthier Cler
** Last update Mon May 08 14:04:23 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<libgen.h>

void		print_usage(const char *binary_name)
{
  fprintf(stderr, "Usage: ./%s port path\n", basename((char *)binary_name));
}