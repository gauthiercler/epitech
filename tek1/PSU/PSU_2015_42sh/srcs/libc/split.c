/*
** split.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/split.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:57:05 2016 Antoine FORET
** Last update Sun Jun  5 18:30:25 2016 Gauthier Cler
*/

#include	"bool.h"
#include	"libc.h"

/*
** Split ref into two substring which starts are stored in saver tab
** @params ref string, saver
** @return success -> true, failure -> false
*/
t_bool		split(char *ref, char **saver, char *separator)
{
  unsigned int	index;

  index = 0;
  saver[0] = ref;
  while (saver[0][index] != '\0')
    {
      if (in_string(saver[0][index], separator))
	{
	  saver[1] = &saver[0][index];
	  return (TRUE);
	}
      index++;
    }
  saver[1] = &saver[0][index];
  return (TRUE);
}
