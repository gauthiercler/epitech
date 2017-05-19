/*
** tetriminos.c for tetriminos in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing
** 
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
** 
** Started on  Thu Feb 25 17:11:50 2016 Anas Buyumad
** Last update Thu Mar 17 18:03:56 2016 Gauthier Cler
*/

#include	"tetris.h"

int		check_tetrimino(char *filename, char *token)
{
  int		i;
  int		j;

  i = my_strlen(filename) - 1;
  j = my_strlen(token) - 1;
  while (j >= 0)
    {
      if (filename[i] != token[j])
	return (ERROR);
      i -= 1;
      j -= 1;
    }
  return (SUCCESS);
}

int		count_files(char *path)
{
  int		i;
  DIR		*fd;
  struct dirent *b;

  i = 0;
  if ((fd = opendir(path)) == NULL)
    return (ERROR);
  while ((b = readdir(fd)) != NULL)
    (check_tetrimino(b->d_name, ".tetrimino") == SUCCESS) ? i += 1 : 0;
  closedir(fd);
  return (i);
}

int		add_token_to_struct(t_token *token, int i)
{
  int		fd;
  char		*line;
  char		*tmp_strcat;

  if ((tmp_strcat = my_strcat("./tetriminos/", token[i].name)) == NULL)
    return (ERROR);
  if ((fd = open(tmp_strcat, O_RDONLY)) == -1)
    return (ERROR);
  if ((line = get_next_line(fd)) == NULL)
    return (ERROR);
  if (parse_info(token, line, i) == ERROR)
    return (ERROR);
  if (fill_map(token, i, fd) == ERROR)
    return (ERROR);
  close(fd);
  token[i].valid = true;
  return (SUCCESS);
}

int		fill_tokens(t_token *tokens, char *path)
{
  DIR		*fd;
  struct dirent	*b;
  int		i;

  i = 0;
  if ((fd = opendir(path)) == NULL)
    return (ERROR);
  while ((b = readdir(fd)) != NULL)
    if (check_tetrimino(b->d_name, ".tetrimino") == SUCCESS)
      {
	tokens[i].name = my_strdup(b->d_name);
	tokens[i].display_name = cut_ext(tokens[i].name);
        tokens[i].state = 1;
	if (add_token_to_struct(tokens, i) == ERROR)
	  tokens[i].valid = false;
	else if (clone_tetri(tokens, i) == ERROR)
	  return (ERROR);
	i += 1;
      }
  closedir(fd);
  return (SUCCESS);
}

int		load_tetriminos(t_init *setup)
{
  int		nb_tokens;

  nb_tokens = count_files("./tetriminos");
  if ((setup->tokens = malloc(sizeof(t_token) * nb_tokens + 1)) == NULL)
    return (ERROR);
  setup->nb_tokens = nb_tokens;
  setup->tokens[nb_tokens].name = NULL;
  if ((fill_tokens(setup->tokens, "./tetriminos")) == ERROR)
    return (ERROR);
  while (sort_ascii(setup->tokens, setup->nb_tokens) == ERROR)
    sort_ascii(setup->tokens, setup->nb_tokens);
  return (SUCCESS);
}
