/*
** main.c for main.c in /home/gogo/rendu/gfx_tekgui
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Fri Feb 26 15:06:10 2016 Gauthier Cler
** Last update Tue Mar  1 22:28:45 2016 Gauthier Cler
*/

#include		"../include/tekgui.h"

int                     main(int ac, char **av)
{
   t_prog                prog;

  if (ac < 2)
    return (write(1, "Need INI\n", 9));
  if (tekgui_init(&prog, av[1], "../bmp/font.bmp") == 1)
    return (0);
  tekgui_display(prog.pix, prog.gui);
  tekgui_loop(&prog);
  return (0);
}
