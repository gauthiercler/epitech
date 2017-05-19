/*
** debug_display.c for debug_display in /tmp/PSU_2015_tetris/srcs/debug
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 17:49:04 2016 Gauthier Cler
** Last update Thu Mar 17 18:09:43 2016 Gauthier Cler
*/

#include	"tetris.h"

int		is_end(char *str, int i)
{
  while (str[i])
    {
      if (str[i] != ' ')
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

void            display_token(t_token *tokens, int i)
{
  int           j;
  int           x;

  j = 0;
  while (j < (int)tokens[i].height)
    {
      x = 0;
      while (tokens[i].pos_1[j][x])
      {
        if (is_end(tokens[i].pos_1[j], x) == ERROR)
          write(1, &tokens[i].pos_1[j][x], 1);
        x += 1;
      }
      write(1, "\n", 1);
      j += 1;
    }
}

void		display_tetri_debug(t_init *setup)
{
  int		i;

  i = 0;
  while (setup->tokens[i].name != NULL)
    {
      my_putstr("Tetriminos : Name ");
      my_putstr(setup->tokens[i].display_name);
      if (setup->tokens[i].valid == false)
	my_putstr(" : Error\n");
      else
	{
	  my_putstr(" : Size ");
	  my_put_nbr(setup->tokens[i].width);
	  write(1, "*", 1);
	  my_put_nbr(setup->tokens[i].height);
	  my_putstr(" : Color ");
	  my_put_nbr(setup->tokens[i].color);
	  my_putstr(" :\n");
	  display_token(setup->tokens, i);
	}
      i += 1;
    }
}

void		debug_display_2(t_init *setup)
{
  char          buffer[2];

  my_putstr("Level : ");
  my_put_nbr(setup->level);
  write(1, "\n", 1);
  my_putstr("Size : ");
  my_put_nbr(setup->map.height);
  my_putchar('*');
  my_put_nbr(setup->map.width);
  write(1, "\n", 1);
  my_putstr("Tetriminos : ");
  my_put_nbr(setup->nb_tokens);
  write(1, "\n", 1);
  display_tetri_debug(setup);
  my_putstr("Press a key to start Tetris\n");
  while (read(0, buffer, 1) == 0)
    buffer[0] = buffer[0];
}

void		debug_display(t_init *setup)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  display_debug_keys(setup->keymap.left);
  write(1, "\n", 1);
  my_putstr("Key Right : ");
  display_debug_keys(setup->keymap.right);
  write(1, "\n", 1);
  my_putstr("Key Turn : ");
  display_debug_keys(setup->keymap.turn);
  write(1, "\n", 1);
  my_putstr("Key Drop : ");
  display_debug_keys(setup->keymap.drop);
  write(1, "\n", 1);
  my_putstr("Key Quit : ");
  display_debug_keys(setup->keymap.quit);
  write(1, "\n", 1);
  my_putstr("Key Pause : ");
  display_debug_keys(setup->keymap.pause);
  write(1, "\n", 1);
  my_putstr("Next : ");
  if (setup->blind_mode == false)
    my_putstr("Yes\n");
  else
    my_putstr("No\n");
  debug_display_2(setup);
}
