/*
** is_alpha.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/libc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jun  3 00:58:29 2016 Gauthier Cler
** Last update Sun Jun  5 17:25:20 2016 Vincent Dusautoir
*/

#include	"libc.h"

/*
** Check if the char is alpha
** @params request
** @return success -> TRUE, failure -> FALSE
*/
t_bool		is_alpha_cd(char request)
{
  if ((request >= 'a' && request <= 'z') || request == '_')
    return (TRUE);
  if (request >= 'A' && request <= 'Z')
    return (TRUE);
  return (FALSE);
}
