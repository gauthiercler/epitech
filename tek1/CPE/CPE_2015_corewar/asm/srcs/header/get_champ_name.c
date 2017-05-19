/*
** get_champ_name.c for get_champ_name in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/get_champ_name
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Wed Mar 23 19:24:40 2016 valentin montagne
** Last update Fri Mar 25 19:32:41 2016 valentin montagne
*/

#include	"asm.h"

int		check_space(char *line, char separator, int i)
{
  while (line[i] != separator)
    {
      if (line[i] != ' ' && line[i] != '\t')
	return (HEADER_ERROR);
      i++;
    }
  return (SUCCESS);
}

int		find_name(char *line)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (check_space(line, '.', i))
    return (0);
  while (line[i])
    {
      while (line[i] == NAME_CMD_STRING[j])
	{
	  i++;
	  j++;
	}
      if (NAME_CMD_STRING[j] == 0 && (line[i] == ' ' || line[i] == '\t'))
	return (i);
      else
	j = 0;
      i++;
    }
  return (0);
}

int		get_txt(char *line, char *champ_name, int size)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (line[i] == '"')
    {
      i++;
      while (line[i] != '"')
	{
	  champ_name[j] = line[i];
	  i++;
	  j++;
	  if (j > size)
	    return (-1);
	}
    }
  champ_name[i - 1] = '\0';
  return (i + 1);
}

int		get_champ_name(char *line, char *champ_name)
{
  int		i;
  int		check;

  if (check_space(line, '\0', 0) == SUCCESS)
      return (ERROR);
  if ((i = find_name(line)) == 0)
    return (HEADER_ERROR);
  while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
    i++;
  if ((check = get_txt(line + i, champ_name, PROG_NAME_LENGTH)) < 0)
    return (HEADER_ERROR);
  i += check;
  if (line[i] == '\0')
    return (SUCCESS);
  while (line[i])
    {
      if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
	{
	  champ_name[0] = '\0';
	  return (HEADER_ERROR);
	}
      i++;
    }
  return (SUCCESS);
}
