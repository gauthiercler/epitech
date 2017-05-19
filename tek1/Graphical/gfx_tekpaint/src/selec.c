/*
** selec.c for selec in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 25 14:24:18 2016 Gauthier Cler
** Last update Tue Jan 26 21:22:28 2016 Gauthier Cler
*/

#include       		"tekpaint.h"

void		       	selec(const t_bunny_position	*pos,
			      t_prog			*prog)
{
  t_color	       	color[2];

  color[0].full = WHITE;
  if ((pos[0].x >= 41 && pos[0].x <= 137) &&
      (pos[0].y >= 879 && pos[0].y <= 925))
    pix_to_cactus(prog->pix, "save");
  if ((pos[0].x >= 41 && pos[0].x <= 137) &&
      (pos[0].y >= 927 && pos[0].y <= 975))
    full_pix(prog->pix, color);
  if ((pos[0].x > 164 && pos[0].x <= 258) &&
      (pos[0].y >= 879 && pos[0].y <= 975))
    {
      set_all_false(prog);
      prog->palet.pinceau_r = true;
    }
  if ((pos[0].x > 288 && pos[0].x <= 382) &&
      (pos[0].y >= 879 && pos[0].y <= 975))
    {
      set_all_false(prog);
      prog->palet.pinceau_c = true;
    }
  selec2(pos, prog);
  selec3(pos, prog);
}

void		       	selec2(const t_bunny_position	*pos,
			       t_prog			*prog)
{
  if ((pos[0].x > 412 && pos[0].x <= 506) &&
      (pos[0].y >= 879 && pos[0].y <= 975))
    {
      set_all_false(prog);
      prog->palet.pipette = true;
    }
  if ((pos[0].x > 534 && pos[0].x <= 628) &&
      (pos[0].y >= 879 && pos[0].y <= 975))
    {
      set_all_false(prog);
      prog->palet.line = true;
    }
  if ((pos[0].x > 659 && pos[0].x <= 753) &&
      (pos[0].y >= 879 && pos[0].y <= 975))
    {
      set_all_false(prog);
      prog->palet.circle = true;
    }
}

void		       	selec3(const t_bunny_position	*pos,
			       t_prog			*prog)
{
  if ((pos[0].x > 783 && pos[0].x <= 877) &&
      (pos[0].y >= 879 && pos[0].y <= 975) && prog->palet.size > 1)
    prog->palet.size -= 1;
  if ((pos[0].x > 907 && pos[0].x <= 1001) &&
      (pos[0].y >= 879 && pos[0].y <= 975) && prog->palet.size < 200)
    prog->palet.size += 1;
  if ((pos[0].x > 1023 && pos[0].x <= 1082) &&
      (pos[0].y >= 865 && pos[0].y <= 922))
    sepia_filter(prog->pix);
  if ((pos[0].x > 1091 && pos[0].x <= 1150) &&
      (pos[0].y >= 865 && pos[0].y <= 922))
    grey_filter(prog->pix);
  if ((pos[0].x > 1157 && pos[0].x <= 1216) &&
      (pos[0].y >= 865 && pos[0].y <= 922))
    negative_filter(prog->pix);
  if ((pos[0].x > 1023 && pos[0].x <= 1082) &&
      (pos[0].y >= 931 && pos[0].y <= 990))
    inverse_filter(prog->pix);
  if ((pos[0].x > 1091 && pos[0].x <= 1150) &&
      (pos[0].y >= 931 && pos[0].y <= 990))
    pixel_filter(prog->pix);
  selec4(pos, prog);
}

void		       	selec4(const t_bunny_position	*pos,
	       		       t_prog			*prog)
{
  t_bunny_position	res[2];

  if ((pos[0].x > 1241 && pos[0].x <= 1392) &&
      (pos[0].y >= 850 && pos[0].y <= 1000))
    {
      res[0].x = pos[0].x;
      res[0].y = pos[0].y - 850;
      prog->color[0].full = get_color(prog->p_palet, res);
    }
}
