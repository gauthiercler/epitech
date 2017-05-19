/*
** complex.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 26 17:36:27 2016 Anas Buyumad
** Last update Sun Mar 27 18:16:49 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"asm.h"

int		complex(char *filename)
{
  int		fd;
  t_asm		data;

  if (macros_are_valid() == ERROR)
    return (ERROR);
  if ((fd = get_fd(filename)) == -1)
    return (ERROR);
  if (initialize_data(&data) == ERROR)
    return (format(2, "Couldn't perform malloc.\n"));
  if ((get_header(fd, &data.header, &data.header_end) == HEADER_ERROR))
    return (HEADER_ERROR);
  lseek(fd, data.header_end, SEEK_SET);
  if (find_labels(fd, &data.labels, data.header_end) == LABEL_ERROR)
    return (LABEL_ERROR);
  if (process_file(fd, &data) == ERROR)
    return (ERROR);
  add_args_size(data.lines);
  count_all_bytes(&data.header.prog_size, data.lines, data.labels);
  if (compiler(&data, filename) == ERROR)
    return (ERROR);
  close(fd);
  format(1, "%s has been successfully compiled.\n", filename);
  delete_asm(&data);
  return (SUCCESS);
}
