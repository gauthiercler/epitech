/*
** sorting.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/sorting.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 14:23:57 2017 Gauthier Cler
** Last update Tue Feb 21 14:23:57 2017 Gauthier Cler
*/

#include	<stddef.h>
#include	<string.h>
#include	<stdlib.h>
#include	"nm.h"

static void	strip_string(char *string, char symbol)
{
  char		*write_ptr;
  int		iterator;

  iterator = 0;
  write_ptr = string;
  while (string[iterator])
  {
    *write_ptr = string[iterator];
    if (*write_ptr != symbol)
      write_ptr += 1;
    iterator += 1;
  }
  *write_ptr = '\0';
}

int		compare_64(const void *first, const void *second)
{
  char		*first_s;
  char		*second_s;
  int		ret;

  first_s = strdup(((t_sym_64 *)first)->name);
  second_s = strdup(((t_sym_64 *)second)->name);
  if (!first_s || !second_s)
    exit(1);
  strip_string(first_s, '_');
  strip_string(second_s, '_');
  ret = strcasecmp(first_s, second_s);
  if (ret == 0 && strlen(((t_sym_64 *)first)->name)
		  < strlen(((t_sym_64 *)second)->name))
    ret = 1;
  free(first_s);
  free(second_s);
  return (ret);
}

int		compare_32(const void *first, const void *second)
{
  char		*first_s;
  char		*second_s;
  int		ret;

  if (strcmp(((t_sym_32 *)first)->name, ((t_sym_32 *)second)->name) == 0)
    return (0);
  first_s = strdup(((t_sym_32 *)first)->name);
  second_s = strdup(((t_sym_32 *)second)->name);
  if (!first_s || !second_s)
    exit(1);
  strip_string(first_s, '_');
  strip_string(second_s, '_');
  ret = strcasecmp(first_s, second_s);
  if (ret == 0 && strlen(((t_sym_32 *)first)->name)
		  < strlen(((t_sym_32 *)second)->name))
    ret = 1;
  free(first_s);
  free(second_s);
  return (ret);
}