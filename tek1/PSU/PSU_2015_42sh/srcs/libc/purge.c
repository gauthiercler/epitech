/*
** purge.c for libc in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/libc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 16:17:13 2016 Buyumad Anas
** Last update Sun Jun  5 18:30:41 2016 Gauthier Cler
*/

#include		"bool.h"

/*
** Get the first occurence
** @params str
** @return index of the first character
*/
static unsigned int	get_first_index(char *str)
{
  unsigned int		index;
  t_bool		check;

  index = 0;
  check = FALSE;
  while (check == FALSE)
    {
      if (str[index] != ' ' && str[index] != '\t')
	check = TRUE;
      else
	index++;
    }
  return (index);
}

/*
** Hide all chars after a # (comment)
** @params string to check
** @return updated string
*/
static char		*remove_comment(char *str)
{
  unsigned int		index;

  index = 0;
  while (str[index] != '\0')
    {
      if (str[index] == '#')
	{
	  str[index] = '\0';
	  return (str);
	}
      index++;
    }
  return (str);
}

/*
** Epur a string of tabs and spaces
** @params string
** @return void
*/
char			*purge(char *string)
{
  unsigned int		index;
  unsigned int		first_index;

  index = 0;
  first_index = get_first_index(string);
  while (string[first_index + index])
    {
      if (string[first_index + index] != ' ' &&
	  string[first_index + index] != '\t')
	string[index] = string[first_index + index];
      else
	{
	  string[index] = ' ';
	  while (string[index + first_index] != '\0' &&
		 (string[index + first_index] == ' ' ||
		 string[index + first_index] == '\t'))
	    first_index++;
	  first_index--;
	}
      index++;
    }
  if (index > 0 && string[index - 1] == ' ')
    string[index - 1] = '\0';
  string[index] = '\0';
  return (remove_comment(string));
}
