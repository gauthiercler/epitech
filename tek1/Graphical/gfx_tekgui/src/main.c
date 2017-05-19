/*
** main.c for main in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:16:37 2016 Gauthier Cler
** Last update Sun Feb 28 20:23:45 2016 Gauthier Cler
*/

#include	"tekgui.h"

int			tekgui_init(t_prog *prog, char *ini, char *font)
{
  bunny_set_maximum_ram(15728640);
  if ((prog->pix = bunny_new_pixelarray(1000, 1000)) == NULL)
    return (1);
  if ((prog->gui = tekgui_load(ini)) == NULL)
    return (1);
  if ((prog->win = bunny_start(1000, 1000, 0, "TekGUI")) == NULL)
    return (1);
  if ((prog->font = load_bitmap(font)) == NULL)
    return (1);
  full_pix(prog->pix, WHITE);
  return (0);
}

int			 tekgui_loop(t_prog *prog)
{
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_text_response(text);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(prog->win, 60, prog);
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_stop(prog->win);
  return (EXIT_ON_SUCCESS);
}

t_bunny_response	main_loop(void *data)
{
  t_prog		*prog;

  prog = data;
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, 0);
  bunny_display(prog->win);
  return (GO_ON);
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data)
{
  t_prog		*prog;

  prog = data;
  (void)prog;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
