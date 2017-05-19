/*
** initialize.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/initialization/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 11:47:48 2016 Buyumad Anas
** Last update Sat Mar 26 16:20:56 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		initialize_header(t_header *header)
{
  int		i;
  char		*head;

  head = (char *)header;

  i = 0;
  while (i < (int)sizeof(t_header))
    {
      head[i] = '\0';
      i += 1;
    }
  i = 0;
  header->magic_number = reverse_integer(COREWAR_EXEC_MAGIC);
  while (i <= (PROG_NAME_LENGTH + 1))
    {
      header->prog_name[i] = '\0';
      i += 1;
    }
  i = 0;
  while (i <= (COMMENT_LENGTH + 1))
    {
      header->comment[i] = '\0';
      i += 1;
    }
  return (SUCCESS);
}

int		initialize_instructions(t_asm *data)
{
  if (init_xor(&data->instructions[7]) == ERROR)
    return (ERROR);
  if (init_zjmp(&data->instructions[8]) == ERROR)
    return (ERROR);
  if (init_ldi(&data->instructions[9]) == ERROR)
    return (ERROR);
  if (init_sti(&data->instructions[10]) == ERROR)
    return (ERROR);
  if (init_fork(&data->instructions[11]) == ERROR)
    return (ERROR);
  if (init_lld(&data->instructions[12]) == ERROR)
    return (ERROR);
  if (init_lldi(&data->instructions[13]) == ERROR)
    return (ERROR);
  if (init_lfork(&data->instructions[14]) == ERROR)
    return (ERROR);
  if (init_aff(&data->instructions[15]) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		initialize_data(t_asm *data)
{
  data->labels = NULL;
  data->lines = NULL;
  if (init_live(&data->instructions[0]) == ERROR)
    return (ERROR);
  if (init_ld(&data->instructions[1]) == ERROR)
    return (ERROR);
  if (init_st(&data->instructions[2]) == ERROR)
    return (ERROR);
  if (init_add(&data->instructions[3]) == ERROR)
    return (ERROR);
  if (init_sub(&data->instructions[4]) == ERROR)
    return (ERROR);
  if (init_and(&data->instructions[5]) == ERROR)
    return (ERROR);
  if (init_or(&data->instructions[6]) == ERROR)
    return (ERROR);
  if (initialize_instructions(data) == ERROR)
    return (ERROR);
  data->instructions[16].name = NULL;
  data->instructions[16].nb_args = 0;
  if (initialize_header(&data->header) == ERROR)
    return (ERROR);
  data->header.prog_size = 0;
  data->header_end = 0;
  return (SUCCESS);
}
