/*
** main.c for main in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May  4 15:46:01 2016 montag_v
** Last update Sun May 22 10:30:50 2016 montag_v
*/

#include	<X11/Xlib.h>
#include	"raytracer.h"

float		xcos[360];
float		xsin[360];

static int	raytracer(char *filename)
{
  t_raytracer	raytracer;

  init_trigo();
  load_tab_funct(&raytracer);
  raytracer.win =
    bunny_start(SCREEN_WIDTH, SCREEN_HEIGHT, false, "Raytracer 2");
  raytracer.pix = bunny_new_pixelarray(SCREEN_WIDTH, SCREEN_HEIGHT);
  if (load_ini(&raytracer, filename) == ERROR)
    return (format(2, "Couldn't Load the Scene File.\n"));
  full_pix(raytracer.pix, BLACK);
  if (render_screen(&raytracer) == ERROR)
    return (ERROR);
  bunny_set_key_response(&handle_keys);
  bunny_blit(&raytracer.win->buffer, &raytracer.pix->clipable, 0);
  bunny_display(raytracer.win);
  bunny_loop(raytracer.win, 60, &raytracer);
  delete_raytracer(&raytracer);
  return (SUCCESS);
}

static int	display_usage()
{
  format(1, "Usage : ./raytracer2 [scene.ini]\n");
  return (SUCCESS);
}

int		main(int ac, char **av, char **ae)
{
  bunny_set_maximum_ram(2147483647);
  XInitThreads();
  if (ae[0] == NULL || ac != 2)
    return (display_usage());
  else if (NB_THREADS <= 0)
    return (format(2, "Invalid number of threads\n"));
  else
    raytracer(av[1]);
  return (SUCCESS);
}
