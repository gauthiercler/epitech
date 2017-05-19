/*
** level.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/level.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar  01 17:26:11 2016 Anas Buyumad
** Last update Tue Mar 15 16:25:54 2016 Gauthier Cler
*/

#include	"tetris.h"

int	assess_level(t_init *setup, char *flag, int len)
{
  char	*level_str;
  int	level;
  int	i;

  i = 8;
  level_str = malloc(sizeof(char) * len + 1);
  while (flag[i])
    {
      level_str[i - 8] = flag[i];
      i += 1;
    }
  level_str[i - 8] = '\0';
  level = my_atoi(level_str);
  if (level >= 0)
    setup->level = level;
  else
    return (ERROR);
  return (SUCCESS);
}

int	parse_single_level(t_init *setup, char *flag)
{
  int	len;
  int	i;

  i = 8;
  while (flag[i])
    i += 1;
  len = i - 8;
  if (len == 0)
    return (ERROR);
  else
    assess_level(setup, flag, len);
  return (SUCCESS);
}

int	parse_duo_level(t_init *setup, char *arg)
{
  int	level;

  level = my_atoi(arg);
  if (level >= 0)
    setup->level = level;
  else
    return (ERROR);
  return (SUCCESS);
}

int	level_action(t_init *setup, int ac, char **av, int *i)
{
  int	status;

  if (my_strcmp(av[*i], "-l") == 0)
    {
      if (*i + 1 < ac)
	{
	  status = parse_duo_level(setup, av[*i + 1]);
	  *i += 1;
	  return (status);
	}
    }
  else if (my_strncmp(av[*i], "--level=", 8) == 0)
    {
      status = parse_single_level(setup, av[*i]);
      return (status);
    }
  else
    return (ERROR);
  return (SUCCESS);
}
