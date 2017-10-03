/*
** response.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 15:09:45 2017 Gauthier Cler
** Last update Wed May 10 15:09:45 2017 Gauthier Cler
*/

#include			<stdio.h>
#include			"ftp.h"
#include			"macro.h"

static const struct s_code_tab	return_codes[] =
  {
    {BEFORE_LIST, 150, "Here comes the directory listing"},
    {OK_SEND_DATA, 150, "Ok to send data"},
    {NOOP_OK, 200, "NOOP ok"},
    {PORT_OK, 200, "PORT command successful. Consider using PASV"},
    {HELP_OK, 214, "Help OK"},
    {QUIT, 221, "Goodbye"},
    {GREETINGS, 220, "Welcome to my_ftp"},
    {AFTER_LIST, 226, "Directory send OK"},
    {TRANSFER_COMPLETE, 226, "Transfer complete"},
    {ENTER_PASSIVE, 227, "Entering in Passive Mode"},
    {LOGIN_SUCCESS, 230, "Login successful"},
    {ALREADY_LOGGED_IN, 230, "Already logged in"},
    {CWD_OK, 250, "Directory successfully changed"},
    {DELETE_OK, 250, "Delete operation successful"},
    {SPECIFY_PASS, 331, "Please specify the password"},
    {DATA_NOT_ENABLED, 425, "Use PORT or PASV first"},
    {CONNECTION_FAILED, 425, "Failed to establish connection"},
    {UNKNOWN_COMMAND, 500, "Unknown command"},
    {ILLEGAL_PORT, 500, "Illegal PORT command"},
    {LOGIN_USER_FIRST, 503, "Login with USER first"},
    {LOGIN_USER_PASS, 530, "Please login with USER and PASS"},
    {CANT_SWITCH_GUEST, 530, "Can't change from guest user"},
    {BAD_LOGIN, 530, "Login incorrect"},
    {PERMISSION_DENIED, 530, "Permission denied"},
    {CWD_FAILED, 550, "Failed to change directory"},
    {FILE_OPEN_FAILED, 550, "Failed to open file"},
    {FILE_CREATE_FAILED, 553, "Could not create file"},
    {DELETE_FAILED, 550, "Delete operation failed"},
    {NULL_STATE, 0, NULL}
  };

static int			get_response_idx(enum e_action_state state)
{
  int				idx;

  idx = 0;
  while (return_codes[idx].state != NULL_STATE)
  {
    if (return_codes[idx].state == state)
      return (idx);
    idx += 1;
  }
  return (-1);
}

void				send_response(t_client *client,
						  enum e_action_state state)
{
  int				idx;

  idx = get_response_idx(state);
  if (idx != -1)
  {
    if (dprintf(client->socket.fd, "%d %s.%s", return_codes[idx].code,
	    return_codes[idx].message, CRLF) < 0)
      client->active = false;
  }
}
