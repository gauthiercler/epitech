/*
** palet.c for palet in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 15:57:35 2016 Gauthier Cler
** Last update Tue Jan 26 21:34:10 2016 Gauthier Cler
*/

#include			"tekpaint.h"

void				init_palet(t_prog	*prog)
{
  prog->palet.pinceau_r = true;
  prog->palet.pinceau_c = false;
  prog->palet.circle = false;
  prog->palet.pipette = false;
  prog->palet.line = false;
  prog->palet.size = 15;
  prog->palet.nb_clic = 0;
  prog->color[0].full = BLACK;
}

void                            pinceau(t_prog	*prog)
{
  const t_bunny_position        *pos;
  int				i;
  const bool   			*etat;

  etat = bunny_get_mouse_button();
  i = prog->palet.size;
  pos = bunny_get_mouse_position();
  if (etat[0] == 1 && pos[0].y < 850)
    {
      if (prog->palet.pinceau_r == true)
	{
	  while (i > 0)
	    {
	      tekcircle_pen(prog->pix, pos, i, prog->color);
	      i--;
	    }
	}
      else if (prog->palet.pinceau_c == true)
	teksquare(prog->pix, pos, prog->color, prog->palet.size);
    }
}

void				set_all_false(t_prog	*prog)
{
  prog->palet.pinceau_r = false;
  prog->palet.pinceau_c = false;
  prog->palet.circle = false;
  prog->palet.line = false;
  prog->palet.pipette = false;
}
