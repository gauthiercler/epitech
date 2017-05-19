/*
** sample.c for sample in /home/gogo/rendu/gfx_scroller/srcs/sample
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar 20 19:14:52 2016 Gauthier Cler
** Last update Sun Mar 20 20:10:25 2016 Gauthier Cler
*/

#include		"megalovania.h"

int			play_song(t_bunny_effect *music, t_midi *midi)
{
  static int		i = 0;

  if (midi[i].pitch < 0)
    return (SUCCESS);
  else
    {
      bunny_sound_stop(&music->sound);
      bunny_sound_pitch(&music->sound, midi[i].pitch / 220);
      bunny_sound_play(&music->sound);
      usleep(midi[i].length * 575);
      i += 1;
    }
  return (ERROR);
}

t_midi                  *load_ini(char *path)
{
  t_bunny_ini           *ini;
  int                   count;
  t_midi                *tab;
  int                   i;

  count = 0;
  ini = bunny_load_ini(path);
  while (bunny_ini_get_field(ini, "track1", "duration", count) != NULL)
    count += 1;
  tab = bunny_malloc(sizeof(t_midi) * count + 1);
  i = 0;
  while (i < count)
    {
      tab[i].pitch = atof(bunny_ini_get_field(ini, "track1", "frequency", i));
      tab[i].length = atoi(bunny_ini_get_field(ini, "track1", "duration", i));
      i += 1;
    }
  tab[i].pitch = -1;
  return (tab);
}
