/*
** main_flames.c for flames in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Sun Dec  6 00:17:35 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:06:58 2015 Sylvain Chaugny
*/

#include		<lapin.h>
#include		"include/my_flames.h"

int			main()
{
  t_prog		prog;

  prog.win = bunny_start(800, 800, false, "coucou");
  prog.pix = bunny_new_pixelarray(800, 800);
  prog.pix->clipable.clip_x_position = 0;
  prog.pix->clipable.clip_y_position = 0;
  prog.pix->clipable.clip_width = 800;
  prog.pix->clipable.clip_height = 800;
  prog.pos.x = 0;
  prog.pos.y = 0;
  prog.height = prog.pix->clipable.buffer.height;
  prog.plus = 0;
  load_musics(&prog);
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(prog.win, 28, &prog);
  bunny_sound_stop(prog.music);
  bunny_delete_sound(prog.music);
  bunny_sound_stop(prog.psit);
  bunny_delete_sound(prog.psit);
  bunny_delete_clipable(&prog.pix->clipable);
  bunny_stop(prog.win);
  return (0);
}
