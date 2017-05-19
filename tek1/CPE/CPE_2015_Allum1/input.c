/*
** input.c for input in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 10 13:44:00 2016 Gauthier Cler
** Last update Sun Feb 21 23:05:31 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<time.h>
#include	<stdlib.h>
#include	"alu.h"

int		player_input(int *alu)
{
  char		*input;
  int		line;
  int		matches;

  my_putstr("Line: ");
  if ((input = get_next_line(0)) == NULL)
    return (1);
  if (is_num(input) == 0)
    return (er("Error: invalid input (positive number expected)\n", alu));
  line = my_atoi(input);
  if (line < 1 || line > 4)
    return (er("Error: this line is out of range\n", alu));
  if (alu[line - 1] == 0)
    return (er("Error: this line is empty\n", alu));
  my_putstr("Matches: ");
  if ((input = get_next_line(0)) == NULL)
    return (1);
  if (is_num(input) == 0)
    return (er("Error: invalid input (positive number expected)\n", alu));
  matches = my_atoi(input);
  if (matches > alu[line - 1])
    return (er("Error: not enough matches on this line\n", alu));
  if (matches == 0)
    return (er("Error: you have to remove at least one match\n", alu));
  return (player_match_operation(alu, line, matches));
}

int	player_match_operation(int *alu, int line, int matches)
{
  alu[line - 1] -= matches;
  disp_remove("Player", matches, line);
  return (0);
}

int	er(char *str, int *alu)
{
  my_putstr(str);
  if (player_input(alu) == 1)
    return (1);
  return (0);
}

void 	disp_remove(char *str, int matches, int line)
{
  matches += 48;
  line += 48;
  my_putstr(str);
  my_putstr(" removed ");
  write(1, &matches, 1);
  my_putstr(" match(es) from line ");
  write(1, &line, 1);
  write(1, "\n", 1);
}

void		ia_input(int *allu, int *turn)
{
  int		line;
  int		matches;
  time_t	seed;

  my_putstr("AI's turn...\n");
  srand((unsigned int)time(&seed));
  line = rand() % 4;
  while (allu[line] == 0)
    line = rand() % 4;
  srand((unsigned int)time(&seed));
  matches = 1 + rand() % allu[line];
  allu[line] -= matches;
  disp_remove("AI", matches, line + 1);
  *turn = PLAYER;
}
