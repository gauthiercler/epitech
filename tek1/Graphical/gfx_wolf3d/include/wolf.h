/*
** wolf.h for wolf in /home/gauthier/rendu/gfx_wolf3d/include
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 21 11:36:18 2015 Gauthier Cler
** Last update Tue Jan 12 22:13:32 2016 Gauthier Cler
*/

#ifndef WOLF_H_
# define WOLF_H_

#include <math.h>
#include <stdlib.h>
#include <lapin.h>
#include <unistd.h>

typedef struct		s_map
{
  int			**array;
  int			width;
  int			height;
  int			x;
  int			y;
} t_map;

typedef struct		s_player
{
  float       		pos_x;
  float			pos_y;
  float			dir_x;
  float			dir_y;
  float			field;
  float			angle;
  float			rot_speed;
  float			speed;
} t_player;

typedef struct		s_ray
{
  float			dir_x;
  float			dir_y;
} t_ray;

typedef struct		s_side
{
  float			dis_x;
  float			dis_y;
  int			dir;
} t_side;

typedef struct		s_prog
{
  t_map			map;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_ini		*ini;
  t_player	       	player;
  t_ray			ray;
  t_side		side;
} t_prog;

typedef struct		s_atof
{
  float			decimal;
  float			res;
} t_atof;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);

void			protection(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);

void			go(t_bunny_position *curspos,
			   double angle,
			   t_bunny_position *newpos,
			   int move);

double			vecnorm(t_bunny_position *coord0,
				t_bunny_position *coord1);

int			**read_ini(t_prog *prog);

void			fill_map(t_prog *prog, int **map);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data);

t_bunny_response	main_loop(void *p);

int			my_atoi(const char *str);

float			my_atof(const char *str);

void			init_ray(t_prog *prog, int x);

void			calc_ray(t_prog *prog);

void			check_ray_dir(t_prog *prog, float delta_x, float delta_y);

void			loop_ray(t_prog *prog, float delta_x, float delta_y);

void			disp_line(t_prog *prog, int x);

float			check_side(t_prog *prog);

void			key_up(t_prog *prog);

void			key_down(t_prog *prog);

void			key_left(t_prog *prog);

void			key_right(t_prog *prog);

void			floor_and_sky(t_prog *prog);

#endif
