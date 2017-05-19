/*
** init_generation.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/initialisation/init_generation.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Feb  25 17:18:18 2016 Anas Buyumad
** Last update Thu Mar 17 20:20:18 2016 Anas Buyumad
*/

#include	"tetris.h"

void	init_environment(t_init *setup)
{
  setup->level = 1;
  setup->rows = 0;
  setup->score = 0;
  setup->highscore = 0;
  setup->map.width = 10;
  setup->map.height = 20;
  setup->blind_mode = false;
  setup->windows.main_screen = NULL;
  setup->windows.board = NULL;
  setup->windows.next_piece = NULL;
  setup->windows.misc = NULL;
  setup->gameover = false;
  setup->linebroken = false;
}

void	init_data(t_init *setup, char *env_name)
{
  int	ret;

  setupterm(env_name, 1, &ret);
  if (ret <= 0)
    exit(0);
  setup->tokens = NULL;
  putp(tigetstr("smkx"));
  setup->keymap.left = my_strdup(tigetstr("kcub1"));
  setup->keymap.right = my_strdup(tigetstr("kcuf1"));
  setup->keymap.turn = my_strdup(tigetstr("kcuu1"));
  setup->keymap.drop = my_strdup(tigetstr("kcud1"));
  setup->keymap.quit = my_strdup("q");
  setup->keymap.pause = my_strdup(" ");
}

t_init		*gen_setup(char *term)
{
  t_init	*setup;

  if ((setup = malloc(sizeof(t_init))) == NULL)
    return (NULL);
  init_environment(setup);
  init_data(setup, term);
  return (setup);
}
