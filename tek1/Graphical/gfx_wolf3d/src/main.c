/*
** main.c for main in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 21 11:32:31 2015 Gauthier Cler
** Last update Thu Jun  9 14:02:44 2016 Gauthier Cler
*/

#include	"wolf.h"

int		main(int ac, char **av, char **env)
{
  t_prog	prog;

  if (env[0] == NULL)
    return (0);
  if (ac != 2)
    return (0);
  prog.ini = bunny_load_ini(av[1]);
  if (prog.ini == NULL)
    return (0);
  prog.map.array = read_ini(&prog);
  prog.player.rot_speed = 0.05;
  prog.player.speed = 0.1;
  prog.win = bunny_start(600, 400, false, "Wolf3D");
  prog.pix = bunny_new_pixelarray(600, 400);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(prog.win, 60, &prog);
  bunny_delete_clipable(&prog.pix->clipable);
  bunny_stop(prog.win);
  bunny_free(prog.map.array);
  return (0);
}

void			handle_keys(t_prog *prog)
{
  const	bool 		*keys;

  keys = bunny_get_keyboard();
  (keys[BKS_UP] == true) ? key_up(prog) : 0;
  (keys[BKS_DOWN] == true) ? key_down(prog) : 0;
  (keys[BKS_LEFT] == true) ? key_left(prog) : 0;
  (keys[BKS_RIGHT] == true) ? key_right(prog) : 0;
  (keys[BKS_A] == true) ? prog->player.angle -= prog->player.rot_speed : 0;
  (keys[BKS_Z] == true) ? prog->player.angle += prog->player.rot_speed : 0;
}

t_bunny_response	main_loop(void *p)
{
  t_prog		*prog;
  int			x;

  prog = p;
  handle_keys(prog);
  x = 0;
  floor_and_sky(prog);
  prog->player.dir_x = -cos(prog->player.angle);
  prog->player.dir_y = sin(prog->player.angle);
  prog->player.field = cos(prog->player.angle);
  while (x < prog->pix->clipable.buffer.width)
    {
      init_ray(prog, x);
      calc_ray(prog);
      disp_line(prog, x);
      x++;
    }
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, 0);
  bunny_display(prog->win);
  return (GO_ON);
}

t_bunny_response        key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data)
{

  (void)data;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
