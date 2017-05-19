/*
** parse_param.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/parser/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 26 21:44:00 2016 Buyumad Anas
** Last update Thu Apr  7 12:39:07 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		get_first_length(char *line, int *index)
{
  int		length;
  int		i;

  length = 0;
  i = *index;
  while (line[i] && (line[i] != ' ' && line[i] != '\t')
	 && line[i] != COMMENT_CHAR)
    {
      i += 1;
      length += 1;
    }
  return (length);
}

int		get_param_length(char *line, int *index)
{
  int		length;
  int		i;

  length = 0;
  i = *index;
  while (line[i] && (line[i] != SEPARATOR_CHAR)
	 && line[i] != COMMENT_CHAR)
    {
      i += 1;
      length += 1;
    }
  return (length);
}

void		copy_into(char *str, char *dest, int *index, int length)
{
  int		i;

  i = 0;
  while (i < length && str[i])
    {
      dest[i] = str[*index + i];
      i += 1;
    }
  dest[i] = '\0';
}

int		parse_param(t_arg *param, char *line, int *index, bool first)
{
  int		length;

  length = -1;
  if (line[*index] == ' ' || line[*index] == '\t')
    skip_spacing(line, index);
  if (first)
    length = get_first_length(line, index);
  else
    length = get_param_length(line, index);
  if ((param->name = malloc(sizeof(char) * (length + 1))) == NULL)
    return (format(2, "Couldn't perform malloc."));
  copy_into(line, param->name, index, length);
  if (first)
    *index += length;
  else
    *index += length + 1;
  return (SUCCESS);
}
