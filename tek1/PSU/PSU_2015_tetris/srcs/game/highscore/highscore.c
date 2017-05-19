/*
** highscore.c for highscore.c in /home/gogo/rendu/PSU_2015_tetris/srcs/game/highscore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Thu Mar 17 19:31:48 2016 Gauthier Cler
** Last update Fri Mar 18 23:59:08 2016 Gauthier Cler
*/

#include	"tetris.h"

void		my_put_fd(char c, int fd)
{
  write(fd, &c, 1);
}

void		my_put_nbr_fd(int nb, int fd)
{
  int		i;
  int		j;
  int		k;

  i = 1;
  if (nb < 0)
    {
      nb = -(nb);
      write(fd, "-", 1);
    }
  while (nb / i >= 10)
    i = i * 10;
  while (i > 0)
    {
      j = (nb / i);
      k = j % 10;
      my_put_fd(k + '0', fd);
      i = i / 10;
    }
}

int		set_highscore(t_init *setup)
{
  int		fd;
  char		buffer[10];
  int		score;

  if ((fd = open("./.score", O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    return (ERROR);
  if (read(fd, buffer, sizeof(buffer)) < 0)
    return (ERROR);
  score = my_atoi(buffer);
  close(fd);
  if (score < (int)setup->score)
    {
      if ((fd = open("./.score", O_TRUNC | O_RDWR)) == -1)
	return (ERROR);
      my_put_nbr_fd(setup->score, fd);
      close(fd);
    }
  return (SUCCESS);
}

int		load_highscore(t_init *setup)
{
  int		fd;
  char		buffer[10];
  
  if ((fd = open("./.score", O_RDONLY)) == -1)
    return (ERROR);
  if (read(fd, buffer, sizeof(buffer)) < 0)
    return (ERROR);
  setup->highscore = my_atoi(buffer);
  close(fd);
  return (SUCCESS);
}

