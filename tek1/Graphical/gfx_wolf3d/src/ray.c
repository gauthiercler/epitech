/*
** ray.c for ray in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 28 14:01:04 2015 Gauthier Cler
** Last update Tue Jan 12 22:16:12 2016 Gauthier Cler
*/

#include	"wolf.h"

void		init_ray(t_prog *prog, int x)
{
  float		pos_x_screen;

  pos_x_screen = x * 2 / (float)prog->pix->clipable.buffer.width - 1;
  prog->ray.dir_x = prog->player.dir_x + prog->player.dir_y * pos_x_screen;
  prog->ray.dir_y = prog->player.dir_y + prog->player.field * pos_x_screen;
  prog->map.x = (int)prog->player.pos_x;
  prog->map.y = (int)prog->player.pos_y;
}

void		calc_ray(t_prog *prog)
{
  float		delta_x;
  float		delta_y;

  delta_x = sqrt(1 + pow(prog->ray.dir_y, 2) / pow(prog->ray.dir_x, 2));
  delta_y = sqrt(1 + pow(prog->ray.dir_x, 2) / pow(prog->ray.dir_y, 2));
  check_ray_dir(prog, delta_x, delta_y);
  loop_ray(prog, delta_x, delta_y);
}

void			disp_line(t_prog *prog, int x)
{
  float			wall_d;
  t_bunny_position	pos[2];
  int			length;
  t_color	        color[2];

  wall_d = check_side(prog);
  if (wall_d < 0)
    wall_d = -(wall_d);
  length = prog->pix->clipable.buffer.height / wall_d;
  pos[0].x = x;
  pos[1].x = x;
  pos[0].y = -length / 2 + prog->pix->clipable.buffer.height / 2;
  pos[1].y = length / 2 + prog->pix->clipable.buffer.height / 2;
  if (prog->map.array[prog->map.x][prog->map.y] == 2)
    color[0].full = GREEN;
  else
    color[0].full = RED;
  if (prog->side.dir == 1)
    color[0].full += 2000;
  tekline(prog->pix, pos, color);
}

float	check_side(t_prog *prog)
{
  int	side;
  float	wall_n;
  float	wall_w;

  (void)side;
  if (prog->ray.dir_y >= 0)
    side = 0;
  else
    side = 1;
  wall_n = (prog->map.y - prog->player.pos_y + side) / prog->ray.dir_y;
  if (prog->ray.dir_x >= 0)
    side = 0;
  else
    side = 1;
  wall_w = (prog->map.x - prog->player.pos_x + side) / prog->ray.dir_x;
  if (prog->side.dir >= 1)
    return (wall_n);
  else
    return (wall_w);
}

void			floor_and_sky(t_prog *prog)
{
  t_color		color[2];
  t_bunny_position	pos[2];
  int			y;

  y = 0;
  pos[0].x = 0;
  pos[1].x = prog->pix->clipable.buffer.width;
  color[0].full = 0xFFBF00;
  while (y < prog->pix->clipable.buffer.height / 2)
    {
      pos[0].y = y;
      pos[1].y = y;
      tekline(prog->pix, pos, color);
      y++;
    }
  color[0].full = 0xC0C0C0;
  while (y < prog->pix->clipable.buffer.height)
    {
      pos[0].y = y;
      pos[1].y = y;
      tekline(prog->pix, pos, color);
      y++;
    }
}
