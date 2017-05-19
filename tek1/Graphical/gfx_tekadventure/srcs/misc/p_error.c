/*
** p_error.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 14:45:54 2016 Buyumad Anas
** Last update Wed Apr 13 14:57:13 2016 Buyumad Anas
*/

#include	"adventure.h"

void		*p_error(char *message)
{
  format(2, message);
  return (NULL);
}
