/*
** split.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/parser/split.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 09:51:43 2017 Gauthier Cler
** Last update Wed May 31 09:51:43 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<memory.h>

char          	**split(char *input, char *delimiters)
{
  char 		**tab;
  char 		*arg;
  int  		count;

  count = 0;
  tab = NULL;
  arg = strtok(input, delimiters);
  while (arg != NULL)
  {
    if ((tab = (char **)realloc(tab, (count + 2) * sizeof(*tab))) == NULL)
      return (NULL);
    tab[count] = arg;
    count += 1;
    arg = strtok(NULL, delimiters);
  }
  if ((tab = (char **)realloc(tab, (count + 1) * sizeof(*tab))) == NULL)
    return (NULL);
  tab[count] = NULL;
  return (tab);
}
