/*
** export.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/export.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 11:25:19 2016 Antoine FORET
** Last update Sun Jun  5 20:52:16 2016 Gauthier Cler
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	"config.h"
#include	"class/history_manager.h"

/*
** Export entries to a file pointed by path
** @params self, path
** @return void
*/
void		history_manager_export(t_history_manager *self,
				       const char *path)
{
  int		fd;
  unsigned int	index;

  if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, RIGHTS)) != -1)
    {
      self->sort(self, FALSE, sort_by_id);
      index = 0;
      while (index < self->size)
	{
	  self->entries[index]->export(self->entries[index], fd);
	  index++;
	}
      close(fd);
    }
}
