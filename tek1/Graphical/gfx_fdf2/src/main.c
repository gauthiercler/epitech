/*
** main.c for fdf2 in /home/gauthier/rendu/gfx_fdf2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 10:13:39 2015 Gauthier Cler
** Last update Sun Dec 20 16:24:58 2015 Gauthier Cler
*/

#include	"fdf.h"

int			main(int ac, char **av)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_color		color[2];
  t_bunny_ini		*ini;

  if (ac > 1)
    ini = bunny_load_ini(av[1]);
  if (ini == NULL)
    return (0);
  win = bunny_start(1000, 1000, false, "fdf2");
  pix = bunny_new_pixelarray(1000, 1000);
  color[0].full = BLACK;
  full_pix(pix, color);
  color[0].full = 0xff003399;
  grid(pix, color, ini);
  color[0].full = WHITE;
  read_ini(pix, ini, color);
  bunny_blit(&win->buffer, &pix->clipable, 0);
  bunny_display(win);
  bunny_set_key_response(key);
  bunny_loop(win, 255, NULL);
  bunny_delete_clipable(&pix->clipable);
  bunny_stop(win);
  return (0);
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data)
{
  (void)data;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else
    return (GO_ON);
}
