/*
** check_hitboxes.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 30 14:48:26 2016 Buyumad Anas
** Last update Sat Apr 30 15:02:03 2016 Buyumad Anas
*/

#include	"amazing.h"

int		touches(t_button *button, t_position *mouse_pos)
{
  if ((mouse_pos->x >= button->hitbox.x) &&
      (mouse_pos->x <= button->hitbox.x + button->hitbox.w) &&
      (mouse_pos->y >= button->hitbox.y) &&
      (mouse_pos->y <= button->hitbox.y + button->hitbox.h))
    return (SUCCESS);
  return (ERROR);
}

int		check_hitboxes(t_amazing *amazing, t_position *mouse_pos)
{
  int		i;

  i = 0;
  while (i < NB_BUTTONS)
    {
      if (touches(&amazing->buttons[i], mouse_pos) == SUCCESS)
	return (i);
      i += 1;
    }
  return (-1);
}
