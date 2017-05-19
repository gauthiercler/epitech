/*
** compile_instruction.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 21:33:41 2016 Buyumad Anas
** Last update Sun Mar 27 18:42:10 2016 Gauthier Cler
*/

#include	"asm.h"

int		set_identification(unsigned char *binary_octet,
				   int type, int index)
{
  if (type == REG)
    {
      binary_octet[index] = '0';
      binary_octet[index + 1] = '1';
    }
  else if (type == IND || type == ILAB)
    {
      binary_octet[index] = '1';
      binary_octet[index + 1] = '1';
    }
  else if (type == DIR || type == DLAB)
    {
      binary_octet[index] = '1';
      binary_octet[index + 1] = '0';
    }
  return (SUCCESS);
}

int		compile_coding_octet(int fd, t_line *line)
{
  unsigned char	binary_octet[8];
  int		index;
  int		i;

  i = 1;
  index = 0;
  binary_octet[0] = '0';
  binary_octet[1] = '0';
  binary_octet[2] = '0';
  binary_octet[3] = '0';
  binary_octet[4] = '0';
  binary_octet[5] = '0';
  binary_octet[6] = '0';
  binary_octet[7] = '0';
  while (i < line->nb_args)
    {
      set_identification(binary_octet, line->args[i].type, index);
      i += 1;
      index += 2;
    }
  write_coding_octet(fd, binary_octet);
  return (SUCCESS);
}

int		compile_instruction(int fd, t_line *line)
{
  if (line->nb_args > 0)
    compile_octects(fd, 1, line->args[0].value + 1);
  if (line->args[0].value != 0 && line->args[0].value != 8 &&
      line->args[0].value != 11 && line->args[0].value != 14)
    compile_coding_octet(fd, line);
  return (SUCCESS);
}
