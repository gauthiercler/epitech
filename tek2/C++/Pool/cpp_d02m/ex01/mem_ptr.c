/*
** mem_ptr.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02m/ex01/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 10:26:10 2017 Gauthier Cler
** Last update Thu Jan  5 10:57:57 2017 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  *res = malloc(strlen(str1) + strlen(str2) + 1);
  if (!*res)
    return ;
  if (strcpy(*res, str1) == NULL)
    return ;
  if (strcat(*res, str2) == NULL)
    return ;
}

void	add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &str_op->res);
}
