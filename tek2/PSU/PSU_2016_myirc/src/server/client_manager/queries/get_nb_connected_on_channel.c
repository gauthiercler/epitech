/*
** get_nb_connected_on_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/get_nb_connected_on_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 05 16:00:55 2017 Anas Buyumad
** Last update Mon Jun 05 16:00:55 2017 Anas Buyumad
*/

#include	"server/client_manager.h"

uint16_t	get_nb_connected_on_channel(t_client_mgr *manager,
					    int8_t channel_id)
{
  size_t	iterator;
  uint16_t 	nb_connected;

  iterator = 0;
  nb_connected = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (is_connected_to_channel(&manager->clients[iterator], channel_id))
	nb_connected += 1;
    }
    iterator += 1;
  }
  return (nb_connected);
}