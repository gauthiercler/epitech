/*
** redir_command.c for redir_command in /home/gogo/rendu/PSU_2015_minishell2/src/redir
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Apr  8 23:37:12 2016 Gauthier Cler
** Last update Tue Apr 19 00:11:50 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

void		clean_arg(t_redir *redir)
{
  char		*res;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (redir->arg2[j] == ' ' || redir->arg2[j] == '\t')
    j += 1;
  i = j;
  while (redir->arg2[i] != ' ' && redir->arg2[i] != '\t' && redir->arg2[i])
    i += 1;
  res = xmalloc(sizeof(char) * (i - j) + 1);
  i = j;
  j = 0;
  while (redir->arg2[i] != ' ' && redir->arg2[i] != '\t' && redir->arg2[i])
    {
      res[j] = redir->arg2[i];
      i += 1;
      j += 1;
    }
  res[j] = '\0';
  (redir->arg2 != NULL) ? free(redir->arg2) : 0;
  redir->arg2 = res;
}

char		*first_arg(char *str)
{
  char		*res;
  int		i;

  i = 0;
  while (str[0] == ' ' || str[0] == '\t')
    str += 1;
  while (str[i] != '<' && str[i] != '>')
    i += 1;
  res = xmalloc(sizeof(char) * i + 1);
  i = 0;
  while (str[i] != '<' && str[i] != '>')
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}

char		*last_arg(char *str, int *type)
{
  char		*res;
  int		i;
  int		j;

  i = 0;
  while (str[i] != '>' && str[i] != '<')
    i += 1;
  if (str[i] == '>' && str[i + 1] == '>')
    *type = DRIGHT;
  else if (str[i] == '>' && str[i + 1] != '>')
    *type = RIGHT;
  else if (str[i] == '<' && str[i + 1] == '<')
    *type = DLEFT;
  else
    *type = LEFT;
  (str[i] == '>' && str[i + 1] == '>') ? i += 1 : 0;
  (str[i] == '<' && str[i + 1] == '<') ? i += 1 : 0;
  res = xmalloc(sizeof(char) * (my_strlen(str) - i + 1));
  j = 0;
  while (str[++i])
    res[j++] = str[i];
  res[j] = '\0';
  return (res);
}

int		find_redir(char *instruction, t_redir *redir)
{
  char		**pipe;

  redir->arg1 = first_arg(instruction);
  redir->arg2 = last_arg(instruction, &redir->type);
  if (is_empty(redir->arg1) == ERROR)
    return (format(2, "Invalid null command.\n"));
  if (check_pipe(redir->arg2) == SUCCESS)
    return (format(2, "Ambiguous output redirect.\n"));
  if (check_redir(redir->arg1) == SUCCESS
      || check_redir(redir->arg2) == SUCCESS)
    return (format(2, "Missing name for redirect.\n"));
  clean_arg(redir);
  if (check_pipe(redir->arg1) == SUCCESS)
    {
      pipe = separator_to_tab(redir->arg1, '|');
      if (is_valid_pipe(pipe) == ERROR)
	{
	  (pipe != NULL) ? free_tab(pipe) : 0;
	  return (format(2, "Invalid null command.\n"));
	}
      (pipe != NULL) ? free_tab(pipe) : 0;
    }
  return (SUCCESS);
}

int		redir_command(char *instruction, t_env *env)
{
  t_redir	redir;

  if (find_redir(instruction, &redir) == ERROR)
    {
      (redir.arg1 != NULL) ? free(redir.arg1) : 0;
      (redir.arg2 != NULL) ? free(redir.arg2) : 0;
      return (ERROR);
    }
  if (redir.type == RIGHT)
    right_redir(&redir, env);
  if (redir.type == DRIGHT)
    dright_redir(&redir, env);
  if (redir.type == LEFT)
    left_redir(&redir, env);
  if (redir.type == DLEFT)
    dleft_redir(&redir, env);
  (redir.arg1 != NULL) ? free(redir.arg1) : 0;
  (redir.arg2 != NULL) ? free(redir.arg2) : 0;
  return (SUCCESS);
}
