/*
** is.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/is.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 13:27:53 2017 Montagne Valentin
** Last update Thu Jun 22 13:27:53 2017 Montagne Valentin
*/

#include			<sys/types.h>
#include			<stdbool.h>

bool				is_digits(char *str)
{
  unsigned int			i;

  i = 0;
  while (str[i])
  {
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (false);
    i += 1;
  }
  return (true);
}