/*
** tekgui_load.c for tekgui_load in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 15 13:19:35 2016 Gauthier Cler
** Last update Sun Feb 28 22:06:25 2016 Gauthier Cler
*/

#include	"tekgui.h"

int		fill_tab(t_tekgui *tab, int i, char *tmp, t_bunny_ini *ini)
{
  tab[i].name = my_strdup(tmp);
  tab[i].type = my_strdup(bunny_ini_get_field(ini, tmp, "type", 0));
  tab[i].pos.x = my_atoi(bunny_ini_get_field(ini, tmp, "pos", 0));
  tab[i].pos.y = my_atoi(bunny_ini_get_field(ini, tmp, "pos", 1));
  tab[i].size.x = my_atoi(bunny_ini_get_field(ini, tmp, "size", 0));
  tab[i].size.y = my_atoi(bunny_ini_get_field(ini, tmp, "size", 1));
  tab[i].parent = my_strdup(bunny_ini_get_field(ini, tmp, "parent", 0));
  tab[i].color.argb[0] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 0));
  tab[i].color.argb[1] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 1));
  tab[i].color.argb[2] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 2));
  tab[i].txt_clr.argb[0] = my_atoi(bunny_ini_get_field(ini, tmp, "tcolor", 0));
  tab[i].txt_clr.argb[1] = my_atoi(bunny_ini_get_field(ini, tmp, "tcolor", 1));
  tab[i].txt_clr.argb[2] = my_atoi(bunny_ini_get_field(ini, tmp, "tcolor", 2));
  if (bunny_ini_get_field(ini, tmp, "link", 0) != NULL)
    {
      if ((tab[i].pix = load_bitmap((char *)
				    bunny_ini_get_field(ini, tmp, "link", 0))) == NULL)
	return (1);
    }
  else
    tab[i].pix = NULL;
  fill_text_tab(tab, i);
  tab[i].action = my_strdup(bunny_ini_get_field(ini, tmp, "action", 0));
  return (0);
}

void		fill_text_tab(t_tekgui *tab, int i)
{
  tab[i].text_on = false;
  tab[i].text_pos[0].x = tab[i].pos.x + 2;
  tab[i].text_pos[0].y = tab[i].pos.y + 1;
  tab[i].text_pos[1].x = tab[i].pos.x + tab[i].size.x;
  tab[i].text_pos[1].y = tab[i].pos.y + tab[i].size.y;
  tab[i].text_pos[2].x = tab[i].pos.x + 1;
  tab[i].text_pos[2].y = tab[i].txt_clr.full;
}

t_tekgui       	*tekgui_load(const char *file)
{
  t_tekgui	*tab;
  t_bunny_ini	*ini;
  int		i;
  int		nb_scope;
  char		*tmp;

  i = 0;
  if ((ini = bunny_load_ini(file)) == NULL)
    return (NULL);
  nb_scope = my_atoi(bunny_ini_get_field(ini, "nb_scope", "nb", 0));
  if ((tab = bunny_malloc(sizeof(t_tekgui) * nb_scope + 1)) == NULL)
    return (NULL);
  while (i < nb_scope)
    {
      tmp = my_strdup(bunny_ini_get_field(ini, "nb_scope", "elem", i));
      if (fill_tab(tab, i, tmp, ini) == 1)
	return (NULL);
      i += 1;
    }
  tab[i].name = NULL;
  bunny_delete_ini(ini);
  return (tab);
}
