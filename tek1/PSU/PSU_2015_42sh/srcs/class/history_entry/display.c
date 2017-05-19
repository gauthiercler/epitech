/*
** display.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_entry/display.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:27:09 2016 Antoine FORET
** Last update Sun Jun  5 20:51:05 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	<time.h>
#include	"class/history_entry.h"

/*
** Display value from the history entry. simple and complex format managed
** @params self, mode, fd to use
** @return void
*/
void		history_entry_display(t_history_entry *self, t_bool simple,
				      int fd)
{
  struct tm	*time;

  if (!simple)
    {
      time = localtime(&self->timestamp);
      dprintf(fd, "%6d\t%02d:%02d\t",
	      self->id, time->tm_hour, time->tm_min);
    }
  dprintf(fd, "%s\n", self->command);
}
