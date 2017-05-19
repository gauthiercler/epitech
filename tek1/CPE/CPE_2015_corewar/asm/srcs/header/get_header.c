/*
** get_header.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/header/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 16:26:17 2016 Buyumad Anas
** Last update Sun Mar 27 19:24:46 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int		recup_comment_name(char *line, t_header *header,
				   bool *found_comment)
{
  int		status;

  status = get_champ_comment(line, header->comment);
  if (status == HEADER_ERROR)
    {
      format(2, "Incorrect Header Comment.\n");
      return (HEADER_ERROR);
    }
  else if (status == ERROR)
    return (ERROR);
  else if (status == SUCCESS)
    {
      *found_comment = true;
      return (SUCCESS);
    }
  return (SUCCESS);
}

int		recup_header_name(char *line, t_header *header,
				  bool *found_name)
{
  int		status;

  status = get_champ_name(line, header->prog_name);
  if (status == HEADER_ERROR)
    {
      format(2, "Incorrect Header Name.\n");
      return (HEADER_ERROR);
    }
  else if (status == ERROR)
    return (ERROR);
  else if (status == SUCCESS)
    {
      *found_name = true;
      return (SUCCESS);
    }
  return (SUCCESS);
}

int		header_return(bool found_name, bool found_comment)
{
  if (found_name && found_comment)
    return (SUCCESS);
  format(2, "Incorrect Header.\n");
  return (HEADER_ERROR);
}

int		get_header(int fd, t_header *header, int *header_end)
{
  char		*line;
  int		status;
  bool		found_name;
  bool		found_comment;

  found_name = false;
  found_comment = false;
  while ((line = get_next_line(fd)) != NULL)
    {
      *header_end += my_strlen(line) + 1;
      if (found_name && !found_comment)
	{
	  status = recup_comment_name(line, header, &found_comment);
	  if (status == SUCCESS || status == HEADER_ERROR)
	    return (clear_buffer(fd, line, status));
	}
      if (!found_name)
	{
	  if (recup_header_name(line, header, &found_name) == HEADER_ERROR)
	    return (clear_buffer(fd, line, HEADER_ERROR));
	}
      free(line);
    }
  return (header_return(found_name, found_comment));
}
