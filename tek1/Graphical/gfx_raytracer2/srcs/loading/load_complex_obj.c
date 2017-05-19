/*
** load_complex_obj.c for load_complex_obj in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May 11 19:29:19 2016 montag_v
** Last update Sat May 21 13:36:12 2016 montag_v
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"raytracer.h"

static void		fill_list(t_list **list,
				  int fd)
{
  char			**tab;
  char			*str;

  while ((str = get_next_line(fd)) != NULL)
    {
      tab = my_str_to_wordtab(str);
      add_liste(list, tab);
      bunny_free(str);
    }
}

static void		count_line(t_list *list, int *count)
{
  count[V] = 0;
  count[VN] = 0;
  count[VT] = 0;
  count[F] = 0;
  while (list != NULL)
    {
      if (my_strcmp(list->tab[0], "v") == SUCCESS)
	count[V] += 1;
      else if (my_strcmp(list->tab[0], "vn") == SUCCESS)
	count[VN] += 1;
      else if (my_strcmp(list->tab[0], "vt") == SUCCESS)
	count[VT] += 1;
      else if (my_strcmp(list->tab[0], "f") == SUCCESS)
	count[F] += 1;
      list = list->next;
    }
}

static t_position	fill_vector(int *inc, float x, float y, float z)
{
  t_position		vector;

  vector.x = x;
  vector.y = y;
  vector.z = z;
  (*inc) += 1;
  return (vector);
}

static void		find_vector(t_list	*list,
				    t_position *vector,
				    t_position *vectorn,
				    t_position *vectort)
{
  int		v;
  int		vn;
  int		vt;

  v = 0;
  vn = 0;
  vt = 0;
  while (list != NULL)
    {
      if (my_strcmp(list->tab[0], "v") == SUCCESS)
	vector[v] =
	  fill_vector(&v, my_atof(list->tab[1]),
		      my_atof(list->tab[2]), my_atof(list->tab[3]));
      else if (my_strcmp(list->tab[0], "vn") == SUCCESS)
	vectorn[vn] =
	  fill_vector(&vn, my_atof(list->tab[1]),
		      my_atof(list->tab[2]), my_atof(list->tab[3]));
      else if (my_strcmp(list->tab[0], "vt") == SUCCESS)
	vectort[vt] =
	  fill_vector(&vt, my_atof(list->tab[1]),
		      my_atof(list->tab[2]), my_atof(list->tab[3]));
      list = list->next;
    }
}

int			load_complex_obj(t_bunny_ini *ini,
					 char *scope,
					 t_raytracer *ray,
					 t_object *obj)
{
  t_list		*list;
  t_vector_data		data;
  int			fd;

  if ((fd = open((char *)bunny_ini_get_field(ini, scope, "path", 0), O_RDONLY))
      == -1)
    return (format(2, "Error can't open file in the path of %s\n", scope));
  load_color(ini, scope, &obj->infos.color);
  list = NULL;
  fill_list(&list, fd);
  count_line(list, data.count);
  format(1, "Nb of faces : %d\n", data.count[F]);
  if (init_data(&data, obj) == ERROR)
    return (ERROR);
  if (load_mtl(ray,
	       (char *)bunny_ini_get_field(ini, scope, "pathmtl", 0)) == ERROR)
    return (ERROR);
  obj->infos.nb_triangle = data.count[F];
  find_vector(list, data.vector, data.vectorn, data.vectort);
  load_faces(obj, ray, &data, list);
  delete_list(list);
  return (SUCCESS);
}
