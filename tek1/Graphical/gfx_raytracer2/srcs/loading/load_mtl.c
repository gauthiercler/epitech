/*
** load_mtl.c for load_mtl in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Fri May 20 14:00:54 2016 montag_v
** Last update Sat May 21 12:47:26 2016 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"raytracer.h"

static void	fill_mtl(t_mtl *mtl, char *line)
{
  char		**data;

  data = my_str_to_wordtab(line);
  mtl->color.argb[0] *= my_atof(data[1]);
  mtl->color.argb[1] *= my_atof(data[2]);
  mtl->color.argb[2] *= my_atof(data[3]);
  freetab(data);
}

static int	load_colors(t_mtl *mtl, char *filename)
{
  char		*line;
  int		fd;
  int		i;

  if ((fd = open(filename, O_RDONLY)) == -1)
    return (format(2, "Error couldn't load mtl from %s\n", filename));
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (my_strncmp(line, "newmtl ", 7) == SUCCESS)
	mtl[i].name = my_strdup(line + 7);
      else if (my_strncmp(line, "Kd ", 3) == SUCCESS)
	{
	  fill_mtl(&mtl[i], line);
	  i += 1;
	}
      if (line != NULL)
	bunny_free(line);
    }
  mtl[i].name = NULL;
  return (SUCCESS);
}

int		load_mtl(t_raytracer *ray, char *filename)
{
  char		*line;
  int		nb_mtl;
  int		fd;
  int		i;

  nb_mtl = 0;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (format(2, "Error couldn't load mtl from %s\n", filename));
  while ((line = get_next_line(fd)) != NULL)
    {
      if (my_strncmp(line, "newmtl ", 7) == SUCCESS)
	  nb_mtl += 1;
      if (line != NULL)
	bunny_free(line);
    }
  if (nb_mtl == 0)
    return (format(2, "Error Material Count < 0\n"));
  if ((ray->mtl = bunny_malloc(sizeof(t_mtl) * (nb_mtl + 1))) == NULL)
    return (format(2, "Couldn't malloc\n"));
  i = 0;
  while (i < nb_mtl)
    ray->mtl[i++].color.full = WHITE;
  load_colors(ray->mtl, filename);
  return (SUCCESS);
}
