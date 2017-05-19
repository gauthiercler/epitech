/*
** gen_start.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 21:02:27 2016 Buyumad Anas
** Last update Mon May 23 13:15:40 2016 Gauthier Cler
*/

#include	"perfection.h"

void		gen_start(t_perfect *perfect)
{
  t_cell	start;

  start.pos_x = 0;
  start.pos_y = 0;
  add_elem(&perfect->list, &start, &start);
  perfect->map.cells[start.pos_x][start.pos_y] = 8;
}
