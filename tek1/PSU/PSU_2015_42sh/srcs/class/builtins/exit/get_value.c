/*
** get_value.c for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/exit/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 14:33:13 2016 Buyumad Anas
** Last update Wed Jun  1 15:23:55 2016 Buyumad Anas
*/

#include	"class/exit.h"
#include	"libc.h"

/*
** Gets the exit value by handling the unsigned short int overflow
** @params string (value)
** @return size_t
*/
int		exit_get_value(char *string)
{
  int		value;

  value = get_number(string);
  while (value < 0)
    value = 256 - ((-1) * value);
  while (value > 255)
    value = value - 256;
  return (value);
}
