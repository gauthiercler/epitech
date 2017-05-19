/*
** error.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/error/error.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 07 19:05:53 2017 Gauthier Cler
** Last update Tue Mar 07 19:05:53 2017 Gauthier Cler
*/

#include	<stdbool.h>
#include	<errno.h>
#include	<string.h>
#include	<stdio.h>

bool		custom_error(const char *error)
{
  fprintf(stderr, "%s\n", error);
  return (false);
}

bool		display_error()
{
  fprintf(stderr, "%s\n", strerror(errno));
  return (false);
}