/*
** keys.c for keys in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec 29 01:18:27 2015 Gauthier Cler
** Last update Sun Jan  3 22:12:24 2016 Gauthier Cler
*/

#include	"wolf.h"

void	key_up(t_prog *prog)
{
  int	pos;

  pos = prog->player.pos_x + prog->player.dir_x * prog->player.speed;
  if (prog->map.array[pos][(int)prog->player.pos_y] == 0)
    prog->player.pos_x += prog->player.dir_x * prog->player.speed;
  pos = prog->player.pos_y + prog->player.dir_y * prog->player.speed;
  if (prog->map.array[(int)prog->player.pos_x][pos] == 0)
    prog->player.pos_y += prog->player.dir_y * prog->player.speed;
}

void	key_down(t_prog *prog)
{
  int	pos;

  pos = prog->player.pos_x - prog->player.dir_x * prog->player.speed;
  if (prog->map.array[pos][(int)prog->player.pos_y] == 0)
    prog->player.pos_x -= prog->player.dir_x * prog->player.speed;
  pos = prog->player.pos_y - prog->player.dir_y *prog->player.speed;
  if (prog->map.array[(int)prog->player.pos_x][pos] == 0)
    prog->player.pos_y -= prog->player.dir_y * prog->player.speed;
}

void	key_left(t_prog *prog)
{
  int	pos;

  pos = prog->player.pos_x - prog->player.dir_y * prog->player.speed;
  if (prog->map.array[pos][(int)prog->player.pos_y] == 0)
    prog->player.pos_x -= prog->player.dir_y * prog->player.speed;
  pos = prog->player.pos_y - prog->player.field * prog->player.speed;
  if (prog->map.array[(int)prog->player.pos_x][pos] == 0)
    prog->player.pos_y -= prog->player.field * prog->player.speed;

}

void	key_right(t_prog *prog)
{
  int	pos;

  pos = prog->player.pos_x + prog->player.dir_y * prog->player.speed;
  if (prog->map.array[pos][(int)prog->player.pos_y] == 0)
    prog->player.pos_x += prog->player.dir_y * prog->player.speed;
  pos = prog->player.pos_y + prog->player.field * prog->player.speed;
  if (prog->map.array[(int)prog->player.pos_x][pos] == 0)
    prog->player.pos_y += prog->player.field * prog->player.speed;

}
