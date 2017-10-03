/*
** strip_extra_token.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/string_extended/strip_extra_token.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 04 10:36:36 2017 Antoine FORET
** Last update Sun Jun 04 10:36:37 2017 Antoine FORET
*/

#include	<stdbool.h>
#include	<string.h>
#include	"string_extended.h"

void		strip_extra_token(char *str, char token)
{
  unsigned int	idx;
  bool		accept;

  idx = 0;
  accept = false;
  while (str[idx] != '\0') {
    if (str[idx] == token && !accept)
      memmove(&str[idx], &str[idx + 1], strlen(&str[idx + 1]) + 1);
    else {
      if (str[idx] == token)
	accept = false;
      else
	accept = true;
      idx += 1;
    }
  }
}