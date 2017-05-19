/*
** generate.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May  2 16:55:55 2016 Buyumad Anas
** Last update Sun May 22 23:12:14 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"amazing.h"

int		check_marguments(t_amazing *amazing)
{
  if (amazing->width <= 0)
    return (ERROR);
  else if (amazing->height <= 0)
    return (ERROR);
  else if (amazing->gen_mode != 1 && amazing->gen_mode != 0)
    return (ERROR);
  else if (amazing->gen_type != 1 && amazing->gen_type != 0)
    return (ERROR);
  return (SUCCESS);
}

void		generate(t_amazing *amazing)
{
  draw_buttons(amazing, amazing->buttons);
  SDL_Flip(amazing->Screen);
  if (check_marguments(amazing) == ERROR)
    printf("Can't start Gen.\n");
  else
    {
      printf("Starting gen.\n");
      amazing->generated = true;
      gen_map(&amazing->perfect.map);
      amazing->perfect.start_x = amazing->perfect.map.width / 2;
      amazing->perfect.start_y = amazing->perfect.map.height / 2;
      perfection(amazing);
      draw_maze(amazing);
      SDL_Flip(amazing->Screen);
    }
  amazing->buttons[5].state = 1;
}
