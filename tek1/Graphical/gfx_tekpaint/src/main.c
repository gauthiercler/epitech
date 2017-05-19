/*
** main.c for main in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan  5 16:33:32 2016 Gauthier Cler
** Last update Tue Jan 26 21:44:31 2016 Gauthier Cler
*/

#include			"tekpaint.h"

int				main(int	ac,
				     char	**av,
				     char	**env)
{
  t_prog			prog;

  if (check_env(env) == ERROR)
    return (ERROR);
  if (ac == 1)
    prog.pix = load_white();
  else if ((check_arg(&prog, av[1])) == ERROR)
    prog.pix = load_white();
  init_palet(&prog);
  if ((prog.p_palet = load_bitmap("./bmp/menu/palet.bmp")) == NULL)
    {
      my_putstr("Erreur lors du chargement de la palette\n");
      return (ERROR);
    }
  prog.win = bunny_start(1392, 1000, false, "Tekpaint");
  init_loop(prog);
  return (SUCCESS);
}

t_bunny_response		main_loop(void	*p)
{
  t_prog			*prog;
  t_bunny_position		pos[2];

  pos[0].x = 0;
  pos[0].y = 850;
  prog = p;
  pinceau(prog);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, 0);
  bunny_blit(&prog->win->buffer, &prog->p_palet->clipable, pos);
  bunny_display(prog->win);
  return (GO_ON);
}

t_bunny_response		click(t_bunny_event_state	state,
				      t_bunny_mousebutton	key,
				      void			*data)
{
  t_prog			*prog;
  const t_bunny_position	*pos;

  prog = data;
  pos = bunny_get_mouse_position();
  if ((pos[0].x >= 0 && pos[0].x <= 1900) &&
      (pos[0].y >= 850 && pos[0].y <= 1000) && key == BMB_LEFT
      && state == GO_DOWN)
    selec(pos, prog);
  else if (key == BMB_LEFT && state == GO_DOWN)
    {
      if (prog->palet.circle == true)
	circle(prog, state, key);
      else if (prog->palet.line == true)
	line(prog, state, key);
      else if (prog->palet.pipette == true)
	prog->color[0].full = get_color(prog->pix, pos);
    }
  return (GO_ON);
}

t_bunny_response		key(t_bunny_event_state	state,
				    t_bunny_keysym	key,
				    void		*data)
{
  t_prog			*prog;

  (void)prog;
  prog = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_Z && state == GO_DOWN)
    if (pix_to_cactus(prog->pix, "test") == ERROR)
      my_putstr("Erreur lors de la sauvegarde du fichier cactus\n");
  return (GO_ON);
}

int				init_loop(t_prog	prog)
{
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(prog.win, 255, &prog);
  bunny_delete_clipable(&prog.pix->clipable);
  bunny_delete_clipable(&prog.p_palet->clipable);
  bunny_stop(prog.win);
  return (SUCCESS);
}
