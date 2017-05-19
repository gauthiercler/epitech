/*
** main.c for main in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Feb  9 23:05:48 2016 Gauthier Cler
** Last update Sun Feb 21 23:25:56 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"alu.h"

void		loop_check_allu(int allu, int count)
{
  int		i;

  i = 0;
  while (i++ < count)
    if (i <= allu)
      write(1, "|", 1);
    else
      write(1, " ", 1);
}

void		draw_game(int *allu)
{
  my_putstr("*********\n*   ");
  loop_check_allu(allu[0], 1);
  my_putstr("   *\n*  ");
  loop_check_allu(allu[1], 3);
  my_putstr("  *\n* ");
  loop_check_allu(allu[2], 5);
  my_putstr(" *\n*");
  loop_check_allu(allu[3], 7);
  my_putstr("*\n*********\n");
}

int	allu_alive(int *allu)
{
  if (allu[0] > 0 || allu[1] > 0 || allu[2] > 0 || allu[3] > 0)
    return (1);
  else
    return (0);
}

void	init_alu(int *allu)
{
  allu[0] = 1;
  allu[1] = 3;
  allu[2] = 5;
  allu[3] = 7;
}

int		main()
{
  int		allu[4];
  int		turn;

  turn = PLAYER;
  init_alu(allu);
  while (allu_alive(allu) == 1)
    {
      draw_game(allu);
      write(1, "\n", 1);
      if (turn == PLAYER)
	{
	  my_putstr("Your turn:\n");
	  if (player_input(allu) == 1)
	    return (0);
	  turn = IA;
	}
      else
	ia_input(allu, &turn);
    }
  draw_game(allu);
  if (turn == PLAYER)
    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
  else
    my_putstr("You lost, too bad..\n");
}
