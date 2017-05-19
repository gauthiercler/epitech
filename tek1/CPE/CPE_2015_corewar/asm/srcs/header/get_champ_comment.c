/*
** get_champ_comment.c for get_champ_comment in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/get_champ_name
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Thu Mar 24 13:18:39 2016 valentin montagne
** Last update Fri Mar 25 19:21:33 2016 valentin montagne
*/

#include        "asm.h"

int             find_comment(char *line)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  if (check_space(line, '.', i))
    return (0);
  while (line[i])
    {
      while (line[i] == COMMENT_CMD_STRING[j])
        {
          i++;
          j++;
        }
      if (COMMENT_CMD_STRING[j] == 0
          && (line[i] == ' ' || line[i] == '\t'))
        return (i + 1);
      else
        j = 0;
      i++;
    }
  return (0);
}

int             get_champ_comment(char *line, char *champ_comment)
{
  int           i;
  int		check;

  if (check_space(line, '\0', 0) == 0)
    return (ERROR);
  if ((i = find_comment(line)) == 0)
    return (HEADER_ERROR);
  while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
    i++;
  if ((check = get_txt(line + i, champ_comment, COMMENT_LENGTH)) < 0)
    return (HEADER_ERROR);
  i += check;
  if (line[i] == '\0')
    return (SUCCESS);
  while (line[i])
    {
      if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
        {
          champ_comment[0] = '\0';
          return (HEADER_ERROR);
        }
      i++;
    }
  return (SUCCESS);
}
