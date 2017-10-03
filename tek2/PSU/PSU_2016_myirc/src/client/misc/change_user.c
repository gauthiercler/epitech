/*
** change_user.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/misc/change_user.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 20:54:39 2017 Gauthier Cler
** Last update Mon Jun 05 20:54:39 2017 Gauthier Cler
*/

#include	<memory.h>
#include	"client/structures.h"

void		change_user(t_client *client, const char *name)
{
  memset(client->name, 0, CLIENT_NAME_SIZE + 1);
  memcpy(client->name, name, strlen(name));
}