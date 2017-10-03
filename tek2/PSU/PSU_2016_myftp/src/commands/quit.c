/*
** quit.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/quit.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:43:06 2017 Gauthier Cler
** Last update Wed May 10 10:43:06 2017 Gauthier Cler
*/

#include	"socket.h"

void		quit(t_client *client)
{
  client->active = false;
  send_response(client, QUIT);
}