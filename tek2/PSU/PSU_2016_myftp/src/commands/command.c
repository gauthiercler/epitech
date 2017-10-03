/*
** command.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/command.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 09:25:47 2017 Gauthier Cler
** Last update Wed May 10 09:25:47 2017 Gauthier Cler
*/

#include				<memory.h>
#include				<stdlib.h>
#include				"misc.h"
#include				"commands.h"
#include				"socket.h"
#include				"macro.h"

static const struct s_command_tab	commands[NB_COMMANDS + 1] =
  {
    {"CDUP", &parent_directory},
    {"CWD", &change_directory},
    {"DELE", &delete},
    {"HELP", &help_message},
    {"LIST", &list_files},
    {"NOOP", &noop},
    {"PASV", &passive_mode},
    {"PASS", &password_auth},
    {"PORT", &active_mode},
    {"PWD", &print_directory},
    {"QUIT", &quit},
    {"RETR", &download_file},
    {"STOR", &upload_file},
    {"USER", &user_auth},
    {NULL, NULL}
};

char					*get_command_at_idx(size_t idx)
{
  if (idx > NB_COMMANDS)
    return (NULL);
  return ((char *)commands[idx].command_name);
}

static int				get_func_ptr(t_client *client)
{
  int					idx;

  if (client->args[0] == NULL)
    return (-1);
  idx = 0;
  while (commands[idx].command_name)
  {
    if (strcasecmp(commands[idx].command_name, client->args[0]) == 0)
      return (idx);
    idx += 1;
  }
  return (-1);
}

static char				**split(char *input)
{
  char					**tab;
  char					*arg;
  int					count;

  count = 0;
  tab = NULL;
  arg = strtok(input, " ");
  while (arg != NULL)
  {
    if ((tab = (char **)realloc(tab, (count + 2) * sizeof(*tab))) == NULL)
      return (NULL);
    tab[count] = strdup(arg);
    if (!tab[count])
      return (NULL);
    count += 1;
    arg = strtok(NULL, " ");
  }
  if ((tab = (char **)realloc(tab, (count + 1) * sizeof(*tab))) == NULL)
    return (NULL);
  tab[count] = NULL;
  return (tab);
}

bool					handle_command(t_client *client)
{
  int					command_idx;

  if (strlen(client->input) > 0)
  {
    client->args = split(client->input);
    if (client->args == NULL)
      return (false);
    command_idx = get_func_ptr(client);
    if (command_idx == -1)
      send_response(client, UNKNOWN_COMMAND);
    else if (!client->user.logged &&
	     strcasecmp(client->args[0], "USER") != 0 &&
	     strcasecmp(client->args[0], "PASS") != 0 &&
	     strcasecmp(client->args[0], "QUIT") != 0)
      send_response(client, LOGIN_USER_PASS);
    else
      commands[command_idx].func_ptr(client);
    free_tab(client->args);
    free(client->args);
  }
  return (true);
}