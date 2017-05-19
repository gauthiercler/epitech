/*
** load_faces.c for load_faces in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Thu May 12 16:41:29 2016 montag_v
** Last update Sun May 22 10:19:41 2016 montag_v
*/

#include		"raytracer.h"

static void		fill_vector(t_position data_vector, t_position *vector)
{
  vector->x = data_vector.x;
  vector->y = data_vector.y;
  vector->z = data_vector.z;
}

static void		find_vector(t_vector_data *data,
				    t_position *vector,
				    int pos,
				    int mode)
{
  int			new_pos;

  new_pos = (data->count[mode]) - (pos);
  if (mode == V)
    fill_vector(data->vector[new_pos], vector);
  if (mode == VT)
    fill_vector(data->vectort[new_pos], vector);
  if (mode == VN)
    fill_vector(data->vectorn[new_pos], vector);
}

static void		fill_triangle(t_triangle *triangle,
				      t_vector_data *data,
				      char **tab,
				      int color)
{
  char			**pos;
  int			j;

  j = 0;
  while (j < 3)
    {
      pos = my_wordtab(tab[j + 1], '/');
      find_vector(data, &triangle->vector[j], my_atoi(pos[0]), V);
      find_vector(data, &triangle->vectort[j],
		  my_atoi(pos[1]), VT);
      find_vector(data, &triangle->vectorn[j],
		  my_atoi(pos[2]), VN);
      triangle->index_color = color;
      j += 1;
      freetab(pos);
    }
}

static void		links_mtl(t_raytracer *ray, char *find, int *color)
{
  int			i;

  i = 0;
  while (ray->mtl[i].name != NULL)
    {
      if (my_strcmp(ray->mtl[i].name, find) == SUCCESS)
	*color = i;
      i += 1;
    }
}

void			load_faces(t_object *obj,
				   t_raytracer *ray,
				   t_vector_data *data,
				   t_list *list)
{
  int			color;
  int			i;

  i = 0;
  color = 0;
  while (list != NULL)
    {
      if (my_strcmp(list->tab[0], "f") == SUCCESS)
	{
	  fill_triangle(&obj->infos.triangle[i], data, list->tab, color);
	  i += 1;
	}
      else if (my_strcmp(list->tab[0], "usemtl") == SUCCESS)
	links_mtl(ray, list->tab[1], &color);
      list = list->next;
    }
}
