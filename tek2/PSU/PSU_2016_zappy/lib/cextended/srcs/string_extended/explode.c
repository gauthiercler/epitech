/*
** explode.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cextended/srcs/string_extended/explode.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun May 21 10:56:08 2017 Antoine FORET
** Last update Sun May 21 10:56:08 2017 Antoine FORET
*/

#include	<malloc.h>
#include	<memory.h>
#include	"string_extended.h"

static size_t	nb_words(const char *str, const char delimiter)
{
  size_t	size;
  unsigned int	idx;

  size = 1;
  idx = 0;
  while (str[idx] != '\0')
  {
    if (str[idx] == delimiter)
      size += 1;
    idx += 1;
  }
  return (size);
}

void		manage_work_str(char **array, char *str, const char delimiter)
{
  unsigned int	idx;

  idx = 0;
  array[0] = str;
  while (str[idx] != '\0' && str[idx] != delimiter)
    idx += 1;
  if (str[idx] == '\0')
    return ;
  str[idx] = '\0';
  manage_work_str(&array[1], &str[idx + 1], delimiter);
}

char		**explode(const char *str, const char delimiter)
{
  char		*work_str;
  char		**array;
  size_t	word_count;

  word_count = nb_words(str, delimiter) + 1;
  array = malloc(sizeof(char *) * word_count);
  work_str = strdup(str);
  if (array == NULL || work_str == NULL)
    return (NULL);
  manage_work_str(array, work_str, delimiter);
  array[word_count - 1] = NULL;
  return (array);
}