/*
** find_labels.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/labels/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 15:22:28 2016 Buyumad Anas
** Last update Fri Mar 25 22:04:35 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"asm.h"

int		find_labels(int fd, t_label **labels, int header_end)
{
  char		*line;
  int		nb_line;

  nb_line = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (is_label(labels, line, nb_line) == LABEL_ERROR)
	{
	  free(line);
	  return (LABEL_ERROR);
	}
      nb_line += 1;
      free(line);
    }
  lseek(fd, header_end, SEEK_SET);
  return (SUCCESS);
}
