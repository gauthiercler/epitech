/*
** main.c for main in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:06:40 2016 Gauthier Cler
** Last update Wed Apr 20 21:07:06 2016 Gauthier Cler
*/

#include		<unistd.h>
#include		"bmp.h"

t_bunny_response	handle_keys(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  (void)state;
  (void)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	main_loop(void *d)
{
  t_data		*data;

  data = d;
  bunny_blit(&data->window->buffer, &data->pix->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_data		data;

  if (ac == 2)
    {
      data.pix = load_bmp(av[1]);
      if (data.pix != NULL)
	{
	  data.window =
	    bunny_start(data.pix->clipable.clip_width,
			data.pix->clipable.clip_height, 0, "BmpLoader");
	  bunny_set_key_response(&handle_keys);
	  bunny_set_loop_main_function(&main_loop);
	  bunny_loop(data.window, 10, &data);
	}
    }
  return (0);
}
