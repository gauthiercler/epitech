/*
** is_label.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/labels/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 15:56:47 2016 Buyumad Anas
** Last update Sun Mar 27 18:57:54 2016 Gauthier Cler
*/

#include	"asm.h"

int		is_char_valid(char c)
{
  int		i;

  i = 0;
  while (LABEL_CHARS[i])
    {
      if (c == LABEL_CHARS[i])
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}

int		is_label(t_label **labels, char *line, int nb_line)
{
  int		i;

  i = 0;
  while (line[i])
    {
      if (line[i] != ' ' && line[i] != '\t'
	  && (is_char_valid(line[i]) == ERROR))
	return (ERROR);
      if (is_char_valid(line[i]) == SUCCESS)
	{
	  if (get_label(labels, line, nb_line, i) == LABEL_ERROR)
	    return (LABEL_ERROR);
	  else
	    return (SUCCESS);
	}
      i += 1;
    }
  return (SUCCESS);
}
