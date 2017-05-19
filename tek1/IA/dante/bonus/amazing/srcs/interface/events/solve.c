/*
** solve.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May  3 15:42:15 2016 Buyumad Anas
** Last update Sun May 22 19:16:16 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"amazing.h"

void		solve(t_amazing *amazing)
{
  draw_buttons(amazing, amazing->buttons);
  SDL_Flip(amazing->Screen);
  if (amazing->generated && amazing->solver_type != -1)
    {
      printf("Solving with type %d\n.", amazing->solver_type);
      if (amazing->solver_type == 0)
	solver(amazing);
      else if (amazing->solver_type == 1)
	solver_b(amazing);
      else if (amazing->solver_type == 2)
	solvera(amazing);
    }
  else
    printf("Please gen a maze first or select solver type.\n");
  amazing->buttons[6].state = 1;
}
