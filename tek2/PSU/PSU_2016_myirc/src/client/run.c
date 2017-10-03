/*
** run.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/run.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 29 16:38:01 2017 Gauthier Cler
** Last update Mon May 29 16:38:01 2017 Gauthier Cler
*/

#include	"client/misc.h"
#include	"client/client.h"

bool		operational = true;

bool		run_client()
{
  t_client	client;

  initialize_client(&client);
  while (operational)
  {
    initialize_watcher(&client);
    watch(&client.watcher);
    retrieve_commands(&client);
  }
  if (client.connected)
    close_connection(&client);
  return (true);
}