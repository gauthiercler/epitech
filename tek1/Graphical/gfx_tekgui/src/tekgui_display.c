/*
** tekgui_display.c for tekgui_display in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Feb 16 09:45:19 2016 Gauthier Cler
** Last update Sun Feb 28 21:28:12 2016 Gauthier Cler
*/

#include	"tekgui.h"

void		tekgui_display(t_bunny_pixelarray *pix,
			       t_tekgui *gui)
{
  int		i;

  i = 0;
  while (gui[i].name != NULL)
    {
      (my_strcmp(gui[i].type, "form") == 1) ? draw_form(pix, gui[i]) : 0;
      (my_strcmp(gui[i].type, "text_box") == 1) ? draw_form(pix, gui[i]) : 0;
      (my_strcmp(gui[i].type, "button") == 1) ? draw_form(pix, gui[i]) : 0;
      (my_strcmp(gui[i].type, "picture") == 1) ? blit_to_pix(pix, gui[i]) : 0;
      i += 1;
    }
}
