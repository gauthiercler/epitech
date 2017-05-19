/*
** gen_start.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 21:02:27 2016 Buyumad Anas
** Last update Sun May 22 23:11:58 2016 Gauthier Cler
*/

#include	"perfection.h"

void		gen_start(t_perfect *perfect)
{
  t_cell	start;

  start.pos_x = START_X;
  start.pos_y = START_Y;
  add_elem(&perfect->list, &start, &start);
  perfect->map.cells[start.pos_x][start.pos_y] = 8;
}
