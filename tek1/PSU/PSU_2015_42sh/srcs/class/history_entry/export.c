/*
** export.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_entry/export.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 11:36:40 2016 Antoine FORET
** Last update Sun Jun 05 11:36:40 2016 Antoine FORET
*/

#include	<stdio.h>
#include	"class/history_entry.h"

/*
** Print into a file describe by fd its values
** @params self, fd to use
** @return void
*/
void		history_entry_export(t_history_entry *self, int fd)
{
  dprintf(fd, "#+%d\n%s\n", (unsigned int)self->timestamp, self->command);
}

