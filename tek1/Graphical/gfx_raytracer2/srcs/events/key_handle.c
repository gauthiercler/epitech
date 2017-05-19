/*
** key_handle.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 10 13:35:53 2016 Buyumad Anas
** Last update Fri May 20 14:26:33 2016 Gauthier Cler
*/

#include	"raytracer.h"

t_bunny_response	handle_keys(t_bunny_event_state state,
				    t_bunny_keysym	key,
				    void		*p)
{
  t_raytracer	*data;

  data = p;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_S && state == GO_DOWN)
    if (save_to_file(data->pix) == ERROR)
      return (EXIT_ON_ERROR);
  return (GO_ON);
}
