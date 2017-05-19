/*
** p_error.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:51:26 2016 Buyumad Anas
** Last update Tue Apr 26 15:51:36 2016 Buyumad Anas
*/

#include		<stdlib.h>
#include		"perfection.h"

void			*p_error(char *str)
{
  format(2, "%s", str);
  return (NULL);
}
