/*
** open_cor.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 20:53:33 2016 Buyumad Anas
** Last update Sun Mar 27 16:58:27 2016 Buyumad Anas
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"asm.h"

char		*get_cor_file(char *name)
{
  char		*cor_name;
  int		length;
  int		i;

  i = 0;
  length = my_strlen(name);
  if ((cor_name = malloc(sizeof(char *) * (length + 5))) == NULL)
    return (NULL);
  while (i < length - 2)
    {
      cor_name[i] = name[i];
      i += 1;
    }
  cor_name[i] = '.';
  cor_name[i + 1] = 'c';
  cor_name[i + 2] = 'o';
  cor_name[i + 3] = 'r';
  cor_name[i + 4] = '\0';
  return (cor_name);
}

int		create_file(char *name)
{
  int		fd;
  char		*cor_name;

  if ((cor_name = get_cor_file(name)) == NULL)
    return (ERROR);
  fd = open(cor_name, O_CREAT | O_WRONLY | O_TRUNC,
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  free(cor_name);
  return (fd);
}
