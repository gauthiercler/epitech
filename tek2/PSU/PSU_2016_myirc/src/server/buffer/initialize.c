/*
** initialize.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/buffer/initialize.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 23:06:53 2017 Anas Buyumad
** Last update Thu May 25 23:06:53 2017 Anas Buyumad
*/

#include		"server/structures.h"

void			initialize_buffer(t_cmd_buffer *buffer)
{
  buffer->head = buffer->buffer;
  buffer->tail = buffer->buffer;
}