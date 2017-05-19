/*
** main.c for main in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 29 09:56:41 2016 Gauthier Cler
** Last update Fri Mar 18 10:04:52 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"raytracer.h"

int		main(int ac, char **av, char **ae)
{
  t_prog	prog;

  if (ae[0] == NULL)
    return (0);
  if (ac < 2)
    return (write(1, "Select an ini file\n", 19));
  prog.win = bunny_start(1000, 1000, false, "RAYTRACER");
  prog.pix = bunny_new_pixelarray(1000, 1000);
  if ((prog.object = load_ini(av[1], &prog.nb_objects)) == NULL)
    return (0);
  if (load_infos(av[1], &prog.options, &prog.eye_ori, &prog.lum) == ERROR)
    return (0);
  full_pix(prog.pix, BLACK);
  render(&prog);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(prog.win, 255, &prog);
  bunny_delete_clipable(&prog.pix->clipable);
  bunny_stop(prog.win);
  return (SUCCESS);
}

t_bunny_response                main_loop(void  *p)
{
  t_prog                        *prog;

  prog = p;
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, 0);
  bunny_display(prog->win);
  return (GO_ON);
}

bool				control_bool(bool var)
{
  if (var == false)
    return (true);
  return (false);
}

t_bunny_response                key(t_bunny_event_state state,
				    t_bunny_keysym      key,
				    void                *data)
{
  t_prog				*prog;

  prog = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_SPACE && state == GO_DOWN)
    prog->options.shadow = control_bool(prog->options.shadow);
  if (key == BKS_P && state == GO_DOWN)
    prog->options.plane = control_bool(prog->options.plane);
  if (key == BKS_UP && state == GO_DOWN)
    prog->options.lum_coef += 1;
  if (key == BKS_DOWN && state == GO_DOWN)
    (prog->options.lum_coef > 1) ? prog->options.lum_coef -= 1 : 0;
  if (key == BKS_LEFT && state == GO_DOWN)
    (prog->options.size > 0) ? prog->options.size += 0.1 : 0;
  if (key == BKS_RIGHT && state == GO_DOWN)
    (prog->options.size > 0.1) ? prog->options.size -= 0.1 : 0;
  if (state == GO_DOWN)
    render(prog);
  return (GO_ON);
}
