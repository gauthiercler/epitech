/*
** set_buttons_state.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 30 15:03:44 2016 Buyumad Anas
** Last update Mon May  2 17:35:42 2016 Buyumad Anas
*/

#include	"amazing.h"

void		desactivate_other_choices(t_button buttons[NB_BUTTONS], int index)
{
  int		i;

  i = 0;
  while (i < NB_BUTTONS -2)
    {
      if (index >= 0 && index <= 1)
	{
	  if (i >= 0 && i <= 1 && i != index)
	    buttons[i].state = 1;
	}
      else if (index >= 2 && index <= 4)
	{
	  if (i >= 2 && i <= 4 && i != index)
	    buttons[i].state = 1;
	}
      i += 1;
    }
}

void		set_buttons_state(t_amazing *amazing, int index, int mode)
{
  int		i;

  i = 0;
  while (i < NB_BUTTONS)
    {
      if (mode == 1 && i == index && amazing->buttons[i].state != 3)
	{
	  amazing->buttons[i].state = 3;
	  printf("Setting %s state to 3.\n", amazing->buttons[i].name);
	  desactivate_other_choices(amazing->buttons, index);
	}
      else if (amazing->buttons[i].state == 3 && mode == 1 && i == index)
	amazing->buttons[i].state = 2;
      if (amazing->buttons[i].state == 2 && index != i && mode == 0)
	amazing->buttons[i].state = 1;
      if (amazing->buttons[i].state != 3 && mode == 0 && i == index)
	amazing->buttons[i].state = 2;
      i += 1;
    }
}
