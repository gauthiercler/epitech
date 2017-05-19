/*
** display.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/display.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:14:47 2016 Antoine FORET
** Last update Sat Jun 04 19:14:47 2016 Antoine FORET
*/

#include	"class/history_manager.h"

/*
** Display current history based on active options
** @params self, fd to use
** @return void
*/
void		history_manager_display(t_history_manager *self, int fd)
{
  unsigned int	index;

  index = self->size - 1;
  self->sort(self, self->options.reverse, sort_by_id);
  if (self->options.to_show == -1)
    self->options.to_show = self->size;
  while (self->options.to_show > 0)
  {
    self->entries[index]->display(self->entries[index], self->options.simple,
				  fd);
    index--;
    self->options.to_show--;
  }
}

