/*
** main.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/main.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb  22 17:44:56 2016 Anas Buyumad
** Last update Thu Mar 17 14:43:32 2016 Anas Buyumad
*/

#include  "tetris.h"

int	tick[2];

t_init  *startup(int ac, char **av, char *term)
{
  t_init  *setup;

  setup = gen_setup(term);
  set_term_settings(0);
  if (load_tetriminos(setup) == ERROR)
    return (NULL);
  if (help_mode(av) == SUCCESS)
    {
      set_term_settings(1);
      return (NULL);
    }
  if (lexer(ac, av) == ERROR)
    {
      help_display(av[0]);
      set_term_settings(1);
      return (NULL);
    }
  if (flags_parser(setup, ac, av) == ERROR)
    return (NULL);
  if (debug_mode(av) == SUCCESS)
    debug_display(setup);
  return (setup);
}

char		*find_term(char **ae)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  while (ae[i])
    {
      if (my_strncmp(ae[i], "TERM=", 5) == SUCCESS)
	{
	  res = malloc(sizeof(char) * (my_strlen(ae[i]) - 4));
	  res[my_strlen(ae[i]) - 4] = '\0';
	  while (j < my_strlen(ae[i]) - 4)
	    {
	      res[j] = ae[i][j + 5];
	      j += 1;
	    }
	  return (res);
	}
      i += 1;
    }
  return (NULL);
}

int		main(int ac, char **av, char **ae)
{
  t_init	*setup;
  char		*term_name;

  if ((term_name = find_term(ae)) == NULL)
    return (0);
  setup = startup(ac, av, term_name);
  signal(SIGUSR1, sighandler);
  signal(SIGWINCH, sighandler);
  if (setup != NULL)
    if (setup->nb_tokens > 0)
      start_game(setup);
  if (setup != NULL)
    {
      set_term_settings(1);
      putp(tigetstr("clear"));
    }
  return (0);
}
