/*
** draw_button.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 22:38:07 2016 Buyumad Anas
** Last update Sun May  1 16:31:09 2016 Buyumad Anas
*/

#include	"amazing.h"

void		draw_button(t_amazing *amazing, t_button *button)
{
  t_position	pos;

  pos.x = button->hitbox.x;
  pos.y = button->hitbox.y;
  if (button->type == 1)
    {
      if (button->state == 1)
	blit(amazing->Screen, button->button_normal, &pos);
      else if (button->state == 2)
	blit(amazing->Screen, button->button_hover, &pos);
      else if (button->state == 3)
	blit(amazing->Screen, button->button_selected, &pos);
    }
  else
    blit(amazing->Screen, button->button_normal, &pos);
}

void		draw_buttons(t_amazing *amazing, t_button buttons[NB_BUTTONS])
{
  int		i;

  i = 0;
  while (i < NB_BUTTONS)
    {
      draw_button(amazing, &buttons[i]);
      i += 1;
    }
}
