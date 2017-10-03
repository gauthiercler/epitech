/*
** noop.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/noop.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:41:39 2017 Gauthier Cler
** Last update Wed May 10 10:41:40 2017 Gauthier Cler
*/

#include	"socket.h"

void		noop(t_client *client)
{
  send_response(client, NOOP_OK);
}