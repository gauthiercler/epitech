/*
** load_decor.c for load_decor in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Thu Apr 14 14:23:06 2016 valentin montagne
** Last update Sun Apr 17 23:52:34 2016 Gauthier Cler
*/

#include	"adventure.h"

int		load_loop(t_elem *elems,
			  t_bunny_ini *ini,
			  char **names,
			  int nb)
{
  int		i;

  i = 1;
  while (i < nb)
    {
      if (load_elem(ini, &elems[i], names[i - 1]) == ERROR)
	return (format(2, "load_decor : Couldn't load elems : %s\n",
		       names[i - 1]));
      i++;
    }
  elems[i].name = NULL;
  return (SUCCESS);
}

int		load_loop_d(t_elem *elems,
			  t_bunny_ini *ini,
			  char **names,
			  int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if (load_elem(ini, &elems[i], names[i]) == ERROR)
	return (format(2, "Couldn't load elems : %s\n",
		       names[i]));
      i++;
    }
  elems[i].name = NULL;
  return (SUCCESS);
}

int             find_scope_d(t_bunny_ini *ini,
			     char *what,
			     char **scope,
			     int nb)
{
  int           i;

  i = 0;
  while (i < nb)
    {
      if ((scope[i] =
           (char *)bunny_ini_get_field(ini, what, "names_d", i)) == NULL)
        return (format(2, "find_scope : Couldn't read the file .ini\n"));
      i++;
    }
  return (SUCCESS);
}

int		load_decor_dynamics(t_decor *decor,
				    t_bunny_ini *ini,
				    char *scope)
{
  int		nb;
  char		**names;

  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, "nb_elems_d", 0))) < 0)
    return (format(2, "%s Error nb_elems_d < 0\n", scope));
  if ((names = bunny_malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  names[nb] = NULL;
  if (find_scope_d(ini, scope, names, nb) == ERROR)
    return (format(2, "load_decor : Couldn't find scope : %s\n", scope));
  if ((decor->dynamics = bunny_malloc(sizeof(t_elem) * (nb + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if (load_loop_d(decor->dynamics, ini, names, nb) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		load_decor(t_decor *decor, t_bunny_ini *ini, char *scope)
{
  int		nb;
  char		**names;

  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, "nb_elems", 0))) < 0)
    return (format(2, "%s Error nb_elems < 0\n", scope));
  if ((names = bunny_malloc(sizeof(char *) * (nb))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  names[nb - 1] = NULL;
  if (find_scope(ini, scope, names, nb - 1) == ERROR)
    return (format(2, "load_decor : Couldn't find scope : %s\n", scope));
  if ((decor->elems = bunny_malloc(sizeof(t_elem) * (nb + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  decor->elems[0].ratio = my_atoi(bunny_ini_get_field(ini, scope, "ratio", 0));
  decor->elems[0].name =
    my_strdup(bunny_ini_get_field(ini, scope, "background", 0));
  decor->elems[0].pos.x = 0;
  decor->elems[0].pos.y = 0;
  decor->elems[0].exists = true;
  decor->elems[0].tick = 0;
  decor->elems[0].exists = true;
  if (load_loop(decor->elems, ini, names, nb) == ERROR)
    return (ERROR);
  if (load_decor_dynamics(decor, ini, scope) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
