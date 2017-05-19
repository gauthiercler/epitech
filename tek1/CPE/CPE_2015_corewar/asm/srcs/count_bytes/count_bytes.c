/*
** count_bytes.c for count_bytes in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/count_bytes
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Mar 23 11:26:43 2016 Gauthier Cler
** Last update Sun Mar 27 19:21:43 2016 Buyumad Anas
*/

#include	"asm.h"

int		set_sti(t_arg *arg)
{
  if (my_strcmp(arg[0].name, "sti") == SUCCESS)
    {
      arg[0].o_size = 1;
      arg[1].o_size = 1;
      (arg[2].type == REG) ? (arg[2].o_size = 1) : (arg[2].o_size = 2);
      (arg[3].type == REG) ? (arg[3].o_size = 1) : (arg[3].o_size = 2);
      return (SUCCESS);
    }
  return (ERROR);
}

int		set_ldi(t_arg *arg)
{
  if (my_strcmp(arg[0].name, "ldi") == SUCCESS ||
      my_strcmp(arg[0].name, "lldi") == SUCCESS)
    {
      arg[0].o_size = 1;
      (arg[1].type == REG) ? (arg[1].o_size = 1) : (arg[1].o_size = 2);
      (arg[2].type == REG) ? (arg[2].o_size = 1) : (arg[2].o_size = 2);
      arg[3].o_size = 1;
      return (SUCCESS);
    }
  return (ERROR);
}

void		count_bytes(t_arg *arg, int index)
{
  if (set_sti(arg) == SUCCESS)
    return ;
  else if ((my_strcmp(arg[0].name, "zjmp") == SUCCESS) ||
	   (my_strcmp(arg[0].name, "fork") == SUCCESS) ||
	   (my_strcmp(arg[0].name, "lfork") == SUCCESS))
    {
      arg[0].o_size = 1;
      arg[1].o_size = 2;
    }
  else if (set_ldi(arg) == SUCCESS)
    return ;
  else if (arg[index].type == REG || arg[index].type == INS)
    arg[index].o_size = 1;
  else if (arg[index].type == IND || arg[index].type == ILAB)
    arg[index].o_size = IND_SIZE;
  else if (arg[index].type == DIR || arg[index].type == DLAB)
    arg[index].o_size = DIR_SIZE;
  else
    arg[index].o_size = 0;
}
