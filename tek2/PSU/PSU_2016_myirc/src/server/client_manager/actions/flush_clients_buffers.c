/*
** flush_clients_buffers.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/flush_clients_buffers.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 12:49:43 2017 Anas Buyumad
** Last update Sun Jun 04 12:49:43 2017 Anas Buyumad
*/

#include	"server/client_manager.h"
#include	"server/parser.h"

void		flush_clients_buffers(t_cmd_buffer *buffer,
					  t_client_mgr *manager)
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (!ring_buffer_is_empty(&manager->clients[iterator].ring_buffer))
	build_buffer_command(buffer, &manager->clients[iterator]);
    }
    iterator += 1;
  }
}