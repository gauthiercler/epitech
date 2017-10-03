/*
** not_connected.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/not_connected.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 16:06:03 2017 Gauthier Cler
** Last update Wed May 31 16:06:03 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"common/misc.h"

void		not_connected_message()
{
  write_in_fd(STDOUT_FILENO, "Not connected to server\n");
}