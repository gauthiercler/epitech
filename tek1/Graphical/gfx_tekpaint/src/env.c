/*
** env.c for check_env in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 26 16:25:20 2016 Gauthier Cler
** Last update Tue Jan 26 21:37:12 2016 Gauthier Cler
*/

#include	"tekpaint.h"

int		check_env(char	**ae)
{
  int		i;

  i = 0;
  while (ae[i])
    {
      if (my_strcmp_ae(ae[i], "DISPLAY=:0") == 1)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
