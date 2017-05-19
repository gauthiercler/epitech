/*
** click_actions.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May  2 16:16:26 2016 Buyumad Anas
** Last update Sat May 21 19:34:59 2016 Buyumad Anas
*/

#include	"amazing.h"

void		display_status(t_amazing *amazing)
{
  if (amazing->gen_type == 0)
    printf("Type of generator : Backtrack.\n");
  else if (amazing->gen_type == 1)
    printf("Type of generator : Prim.\n");
  if (amazing->solver_type == 0)
    printf("Type of solver : Depth.\n");
  else if (amazing->solver_type == 1)
    printf("Type of solver : Breadth.\n");
  else if (amazing->solver_type == 2)
    printf("Type of solver : A-Star.\n");
}

static void	set_types_next(t_amazing *amazing, int index)
{
  if (index == 3)
    {
      if (amazing->solver_type != 1)
	amazing->solver_type = 1;
      else
	amazing->solver_type = -1;
    }
  else if (index == 4)
    {
      if (amazing->solver_type != 2)
	amazing->solver_type = 2;
      else
	amazing->solver_type = -1;
    }
}

static void	set_types(t_amazing *amazing, int index)
{
  if (index == 0)
    {
      if (amazing->gen_type != 0)
	amazing->gen_type = 0;
      else
	amazing->gen_type = -1;
    }
  else if (index == 1)
    {
      if (amazing->gen_type != 1)
	amazing->gen_type = 1;
      else
	amazing->gen_type = -1;
    }
  else if (index == 2)
    {
      if (amazing->solver_type != 0)
	amazing->solver_type = 0;
      else
	amazing->solver_type = -1;
    }
  else
    set_types_next(amazing, index);
}

void		click_actions(t_amazing *amazing, int index)
{
  set_types(amazing, index);
  if (index == 5)
    generate(amazing);
  else if (index == 6)
    solve(amazing);
  else if (index == 7)
    amazing->width += 1;
  else if (index == 8 && amazing->width > 1)
    amazing->width -= 1;
  else if (index == 9)
    amazing->height += 1;
  else if (index == 10 && amazing->height > 1)
    amazing->height -= 1;
  if (index == 7 || index == 8 || index == 9 || index == 10)
    {
      amazing->perfect.map.width = amazing->width;
      amazing->perfect.map.height = amazing->height;
      gen_map(&amazing->perfect.map);
      draw_amazing(amazing);
      SDL_Flip(amazing->Screen);
    }
  display_status(amazing);
  if (index == -1)
    printf("Nothing touched.\n");
}
