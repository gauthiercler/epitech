/*
** import.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/import.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 13:00:08 2016 Antoine FORET
** Last update Sun Jun  5 20:53:00 2016 Gauthier Cler
*/

#include		<string.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		"class/history_manager.h"
#include		"libc.h"

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
	  if ((entry = new_history_entry(self->current_command, line)) != NULL)
	    {
	      entry->timestamp = timestamp;
	      self->insert(self, entry);
	    }
	  return (TRUE);
	}
    }
  return (FALSE);
}

/*
** Import entries from file pointed by path
** @params self, file's path
*/
void			history_manager_import(t_history_manager *self,
						   const char *path)
{
  int			fd;

  if ((fd = open(path, O_RDONLY)) != -1)
    {
      while (import_entry(self, fd));
      close(fd);
    }
}
