/*
** strnkcmp.c for libc in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/libc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 31 14:39:00 2016 Buyumad Anas
** Last update Sun Jun  5 18:30:16 2016 Gauthier Cler
*/

#include	<stddef.h>
#include	"bool.h"

/*
** Strcmp like with an index at the beginning
** @params s1, s2, index, length
** @return success -> TRUE, failure -> FALSE
*/
t_bool		strnkcmp(char *s1, char *s2, size_t index, size_t length)
{
  size_t	iterator;
  size_t	key_iterator;

  iterator = index;
  key_iterator = 0;
  while (s1[iterator] && s2[key_iterator] && iterator < index + length)
    {
      if (s1[iterator] != s2[key_iterator])
	return (FALSE);
      iterator += 1;
      key_iterator += 1;
    }
  return (TRUE);
}
