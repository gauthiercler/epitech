/*
** compiler.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 20:55:24 2016 Buyumad Anas
** Last update Sun Mar 27 16:59:41 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"asm.h"

int		compiler(t_asm *data, char *filename)
{
  int		fd;

  fd = create_file(filename);
  if (fd == -1)
    return (format(2, "Couldn't create the binary file.\n"));
  data->header.prog_size = reverse_integer(data->header.prog_size);
  write(fd, &data->header, sizeof(data->header));
  compile_champ(fd, data);
  close(fd);
  return (SUCCESS);
}
