/*
** merge.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/merge.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 13:56:47 2016 Antoine FORET
** Last update Sun Jun  5 20:53:36 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<string.h>
#include	<malloc.h>
#include	"class/history_manager.h"
#include	"libc.h"

/*
** Check if a sting is a timestamp from file
** @params string to test
** @return success -> TRUE, failure -> FALSE
*/
static t_bool		is_timestamp(char *string)
{
  if (string[0] != '#' || string[1] != '+' || !is_numeric(&string[2]))
    return (FALSE);
  else
    return (TRUE);
}

/*
** Import an entry from file
** @params self, file descriptor
** @return success -> TRUE, failure -> FALSE
*/
static t_bool		import_entry(t_history_manager *self, int fd)
{
  char			*line;
  t_history_entry	*entry;
  time_t		timestamp;

  time(&timestamp);
  while ((line = get_next_line(fd)) != NULL && strcmp(purge(line), "") != 0)
    {
      if (is_timestamp(line))
	timestamp = get_number(&line[2]);
      else
	{
	  if (self->get_unique(self, timestamp, line) == NULL &&
	      (entry = new_history_entry(self->current_command, line)) != NULL)
	    {
	      entry->timestamp = timestamp;
	      self->insert(self, entry);
	    }
	  free(line);
	  return (TRUE);
	}
      free(line);
    }
  return (FALSE);
}

/*
** Sort entries by time desc and asign them the shortest id possible
** @params self
** @return void
*/
static void	smooth_ids(t_history_manager *self)
{
  unsigned int	id;

  id = 0;
  self->sort(self, FALSE, sort_by_time);
  while (id < self->size)
    {
      self->entries[id]->id = id;
      id++;
    }
}

/*
** Merge current history with a file
** @params self, path to the file to use
** @return void
*/
void		history_manager_merge(t_history_manager *self, const char *path)
{
  int			fd;

  if ((fd = open(path, O_RDONLY)) != -1)
    {
      while (import_entry(self, fd));
      close(fd);
      smooth_ids(self);
    }
}
