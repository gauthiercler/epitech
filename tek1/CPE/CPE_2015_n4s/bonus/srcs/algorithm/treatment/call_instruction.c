/*
** call_instruction.c for n4s in /home/gogo/rendu/CPE_2015_n4s/srcs/algorithm/treatment/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu May 26 17:48:10 2016 Gauthier Cler
** Last update Fri May 27 18:51:38 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

static int	check_answer(char **answer_tab)
{
  int		ret_value;

  ret_value = my_atoi(answer_tab[0]);
  if (ret_value == 1 || ret_value == 2)
    return (SUCCESS);
  format(2, "%s : %s\n", answer_tab[1], answer_tab[2]);
  free_array(answer_tab);
  return (ERROR);
}

int		call_instruction(t_data *data, char *instruction, float value,
				  int mode)
{
  char		*answer;

  if (mode == NO_MODE)
    format(1, "%s\n", instruction);
  else if (mode == FLOAT)
    format(1, "%s:%f\n", instruction, value);
  else
    format(1, "%s:%d\n", instruction, (int)value);
  answer = get_next_line(0);
  if (answer == NULL)
    return (ERROR);
  data->answer_tab = explode(answer, ':');
  free(answer);
  if (data->answer_tab == NULL)
    return (ERROR);
  if (check_answer(data->answer_tab) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
