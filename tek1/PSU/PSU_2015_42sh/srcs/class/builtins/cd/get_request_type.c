/*
** get_request_type.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:30:29 2016 Gauthier Cler
** Last update Tue May 31 00:20:02 2016 Gauthier Cler
*/

#include	<string.h>
#include	"class/cd.h"

/*
** Get type of the cd request args
** @params request
** @return int EMPTY if no args, PREVIOUS for "-" and STRING for normal request
*/
int		cd_get_request_type(char *request)
{
  if (request == NULL)
    return (EMPTY);
  else if (strcmp(request, "-") == 0)
    return (PREVIOUS);
  return (STRING);
}
