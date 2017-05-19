/*
** display_usage.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/usage/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:45:56 2016 Buyumad Anas
** Last update Sat May 21 19:13:28 2016 Buyumad Anas
*/

#include	"perfection.h"

void		display_usage(void)
{
  format(2, "Usage : ./perfection [width] [height] [mode] ");
  format(2, "[filename] [type] [debug].\n");
  format(2, "Mode => 1 for perfect maze, 0 for imperfect maze.\n");
  format(2, "Filename => Name of the Output file.\n");
  format(2, "Type => Type of Generation. 0/1 for Backtrack/Prim.\n");
  format(2, "Debug => 1 or 0 for activation.\n");
}
