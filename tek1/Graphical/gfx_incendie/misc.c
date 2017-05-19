/*
** misc.c for misc in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Sun Dec  6 00:16:38 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:08:04 2015 Sylvain Chaugny
*/
#include <lapin.h>
#include "include/my_flames.h"

void			fill_black(t_bunny_pixelarray *pix)
{
  unsigned int		*pixel;
  int			i;

  i = 0;
  pixel = (unsigned int *)pix->pixels;
  while (i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      pixel[i] = BLACK;
      i++;
    }
}

void			load_musics(t_prog *prog)
{
  prog->music = bunny_load_music("sounds/22571.ogg");
  prog->psit = bunny_load_effect("sounds/psit.ogg");
  bunny_sound_play(prog->music);
}
