/*
** initialization.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/loop/initialization.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 12:46:22 2016 Anas Buyumad
** Last update Tue Mar 22 11:44:36 2016 Gauthier Cler
*/

#include	"megalovania.h"

void		burn_pix(t_data *data)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (data->planets[i].planet != NULL)
	bunny_delete_clipable(&data->planets[i].planet->clipable);
      i += 1;
    }
  i = 0;
  while (i < 4)
    {
      if (data->ship[i] != NULL)
	bunny_delete_clipable(&data->ship[i]->clipable);
      i += 1;
    }
  i = 0;
  while (i < 8)
    {
      if (data->peanut[i] != NULL)
	bunny_delete_clipable(&data->peanut[i]->clipable);
      i += 1;
    }
}

void		burn(t_data *data)
{
  if (data->window != NULL)
    bunny_stop(data->window);
  if (data->pix != NULL)
    bunny_delete_clipable(&data->pix->clipable);
  if (data->font != NULL)
    bunny_delete_clipable(&data->font->clipable);
  if (data->music != NULL)
    bunny_delete_sound(&data->music->sound);
  burn_pix(data);
}

int		load_planets_end(t_data *data)
{
  if ((data->planets[2].planet =
       bunny_load_pixelarray("ressources/mars.png")) == NULL)
    return (ERROR);
  data->planets[2].pos_x = -600.0;
  data->planets[2].pos_y = 450.0;
  data->planets[2].speed = 10;
  data->planets[2].dim = 300;
  if ((data->planets[3].planet =
       bunny_load_pixelarray("ressources/earth.png")) == NULL)
    return (ERROR);
  data->planets[3].pos_x = -600.0;
  data->planets[3].pos_y = 600.0;
  data->planets[3].speed = 15.0;
  data->planets[3].dim = 600;
  return (SUCCESS);
}

int		load_planets_start(t_data *data)
{
  if ((data->sans = bunny_load_pixelarray("ressources/Sans.png")) == NULL)
    return (ERROR);
  if ((data->planets[0].planet =
       bunny_load_pixelarray("ressources/StarboundPlanetSprite.png")) == NULL)
    return (ERROR);
  data->planets[0].pos_x = -650.0;
  data->planets[0].pos_y = 400.0;
  data->planets[0].speed = 4.0;
  data->planets[0].dim = 200;
  if ((data->planets[1].planet =
       bunny_load_pixelarray("ressources/SaturnV2.png")) == NULL)
    return (ERROR);
  data->planets[1].pos_x = -150.0;
  data->planets[1].pos_y = 200.0;
  data->planets[1].speed = 2.5;
  data->planets[1].dim = 100;
  return (SUCCESS);
}

int			initialize()
{
  t_data		data;

  if (load_planets_start(&data) == ERROR)
    return (ERROR);
  if (load_planets_end(&data) == ERROR)
    return (ERROR);
  if ((data.music = bunny_load_music("ressources/music.ogg")) == NULL)
    return (ERROR);
  if (load_jelly(&data) == ERROR)
    return (ERROR);
  if (load_ship(&data) == ERROR)
    return (ERROR);
  load_sprite_attribute(&data);
  data.window = bunny_start_style(1920, 1080, 9, "Megalovania");
  data.pix = bunny_new_pixelarray(1920, 1080);
  load_sans(&data);
  bunny_set_key_response(&key_handle);
  bunny_set_loop_main_function(&loading_loop);
  if ((data.midi = load_ini("./ressources/darude.bsf")) == NULL)
    return (ERROR);
  if ((data.music_load = bunny_load_effect("./ressources/beep.ogg")) == NULL)
    return (ERROR);
  big_loop(&data);
  return (SUCCESS);
}
