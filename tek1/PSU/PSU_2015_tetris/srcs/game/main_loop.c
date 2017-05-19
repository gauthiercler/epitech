/*
** main_loop.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/main_loop.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  10 19:19:29 2016 Anas Buyumad
** Last update Thu Mar 17 19:31:27 2016 Gauthier Cler
*/

#include	"tetris.h"

t_token	*select_token(t_init *setup)
{
  time_t   seed;
  int	selected;
  bool	select_done;

  srand((unsigned int)time(&seed) + rand() % 1000);
  select_done = false;
  while (!select_done)
  {
    selected = rand() % setup->nb_tokens;
    if (setup->tokens[selected].valid)
      select_done = true;
  }
  return (&setup->tokens[selected]);
}

int    tick_condition(t_falling *falling_piece,
                       t_falling *next_piece, bool *gen_next, t_init *setup)
{
  int	tmp;

  if (alter_piece(setup, falling_piece, LOWER_PIECE) == ERROR)
    {
      if (falling_piece->token->state % 2 == 0)
	{
	  tmp = falling_piece->token->width;
	  falling_piece->token->width = falling_piece->token->height;
	  falling_piece->token->height = tmp;
	}
      falling_piece->token->state = 1;
      falling_piece->token = next_piece->token;
      falling_piece->pos_x = (setup->map.width / 2)
        - (falling_piece->token->width / 2);
      falling_piece->pos_y = 0;
      if (check_obstacle(setup, falling_piece) == ERROR)
	return (ERROR);
      *gen_next = true;
    }
  return (SUCCESS);
}

void	init_main_loop(t_falling *falling_piece, t_falling *next_piece,
		       bool *gen_next, pid_t *pid)
{
  *pid = getpid();
  *gen_next = true;
  falling_piece->token = NULL;
  next_piece->token = NULL;
}

void    end_loop(t_init *setup, t_falling *falling_piece)
{
  char  buffer[100];
  int   read_count;

  tick[0] = 0;
  read_count = read(0, buffer, sizeof(buffer));
  buffer[read_count] = '\0';
  if (read_count > 0)
    key_input(buffer, setup, falling_piece);
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  signal(SIGWINCH, sighandler);
  check_completed_row(setup);
}

int	main_loop(t_init *setup)
{
  t_falling	falling_piece;
  t_falling     next_piece;
  bool          gen_next;
  pid_t		pid;

  init_main_loop(&falling_piece, &next_piece, &gen_next, &pid);
  display_board(setup->board, setup->map.width, setup->map.height,
                setup->windows.board);
  tick[0] = 1;
  set_term_settings(2);
  while (!setup->gameover)
    {
      (tick[0] == 1) ? fork_timer(60 - (setup->level * 5), pid) : 0;
      if (res_term(setup) == ERROR)
        return (ERROR);
      falling_piece_init(setup, &falling_piece, &next_piece, &gen_next);
      if (tick[0] == 1)
	if (tick_condition(&falling_piece, &next_piece, &gen_next, setup) == ERROR)
	  setup->gameover = true;
      end_loop(setup, &falling_piece);
    }
  curs_set(1);
  set_highscore(setup);
  return (SUCCESS);
}
