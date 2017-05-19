/*
** func_ptr.c for cpp_d02m in /home/gogo/rendu/tek2/cpp_d02m/ex03/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 11:40:38 2017 Gauthier Cler
** Last update Thu Jan  5 12:22:06 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	"func_ptr.h"
#include	"func_ptr_enum.h"

void	print_normal(char *str)
{
  printf("%s\n", str);
}

void	print_reverse(char *str)
{
  for (int i = strlen(str) - 1; i >= 0; --i)
    printf("%c", str[i]);
  printf("\n");
}

void	print_upper(char *str)
{
  for (unsigned int i = 0; i < strlen(str); i++)
    printf("%c", toupper(str[i]));
  printf("\n");
}

void	print_42(char *str)
{
  (void)str;
  printf("42\n");
}

void	do_action(t_action action, char *str)
{
  t_ptr ptr_action[4] =
  {
  {PRINT_NORMAL, &print_normal},
  {PRINT_REVERSE, &print_reverse},
  {PRINT_UPPER, &print_upper},
  {PRINT_42, &print_42},
  };

  for (unsigned int i = 0; i < 4; i++)
    {
      if (ptr_action[i].action_enum == action){
	  ptr_action[i].action(str);
	  break;
	}
    }
}
