/*
** input.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/input.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 09 22:25:33 2017 Gauthier Cler
** Last update Tue May 09 22:25:33 2017 Gauthier Cler
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"ftp.h"

void			free_tab(char **tab)
{
  if (tab)
  {
    while (*tab)
    {
      free(*tab);
      *tab = NULL;
      tab += 1;
    }
  }
}

void			free_ptr(char **input)
{
  if (*input != NULL)
  {
    free(*input);
    *input = NULL;
  }
}

int			get_client_input(t_client *client)
{
  ssize_t		read_ret;
  int			idx;

  read_ret = getline(&client->input, &client->message_length,
		     client->stream_fd);
  if (read_ret <= 0)
    return (0);
  idx = 0;
  while (client->input[idx] &&
	 client->input[idx] != '\r' && client->input[idx] != '\n')
    idx += 1;
  client->input[idx] = '\0';
  return (1);
}