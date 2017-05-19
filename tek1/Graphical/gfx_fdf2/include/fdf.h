/*
** fdf.h for fdf in /home/gauthier/rendu/gfx_fdf2/include
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 11:03:36 2015 Gauthier Cler
** Last update Sun Dec 20 20:40:47 2015 Gauthier Cler
*/

#ifndef MY_H_
# define MY_H_

#include <math.h>
#include <stdlib.h>
#include <lapin.h>

typedef struct s_surface
{
  int	x;
  int	y;
  int	z;
  int	u;
  int	v;
  int	radius;
} t_surface;

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *pos,
		t_color *color);

void	tekisoproject(t_bunny_position *out,
		      int x,
		      int y,
		      int z);

void	protection(t_bunny_pixelarray *pix,
		   t_bunny_position *pos,
		   t_color *color);

void	full_pix(t_bunny_pixelarray *pix,
		 t_color *color);

void	grid(t_bunny_pixelarray *pix,
	     t_color *color,
	     t_bunny_ini *ini);

void	read_ini(t_bunny_pixelarray *pix,
		 t_bunny_ini *ini,
		 t_color *color);

void	read_ini_line(t_bunny_pixelarray *pix,
		      t_bunny_ini *ini,
		      t_color *color,
		      const char *type);

void	read_ini_pixel(t_bunny_pixelarray *pix,
		       t_bunny_ini *ini,
		       t_color *color,
		       const char *type);

void	ini_line(t_bunny_pixelarray *pix,
		 t_bunny_ini *ini,
		 t_color *color);

void	ini_pixel(t_bunny_pixelarray *pix,
		  t_bunny_ini *ini,
		  t_color *color);

void	ini_fdf(t_bunny_pixelarray *pix,
		t_bunny_ini *ini,
		t_color *color);

int	loop_ini_fdf(t_bunny_ini *ini,
		     int i,
		     int *buff);

void	line_fdf(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

void	co_ini_fdf(t_bunny_position *pos,
		   t_bunny_position *save,
		   int *buff);

void	ini_sphere(t_bunny_pixelarray *pix,
		   t_bunny_ini *ini,
		   t_color *color);

void	ini_tore(t_bunny_pixelarray *pix,
		 t_bunny_ini *ini,
		 t_color *color);

void	ini_cylinder(t_bunny_pixelarray *pix,
		     t_bunny_ini *ini,
		     t_color *color);

void	ini_mobius(t_bunny_pixelarray *pix,
		   t_bunny_ini *ini,
		   t_color *color);

void	ini_cone(t_bunny_pixelarray *pix,
		 t_bunny_ini *ini,
		 t_color *color);

void	ini_coussin(t_bunny_pixelarray *pix,
		    t_bunny_ini *ini,
		    t_color *color);

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2);

int	my_getnbr(char *str);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data);

void	ini_polygon(t_bunny_pixelarray *pix,
		    t_bunny_ini *ini,
		    t_color *color);

#endif
