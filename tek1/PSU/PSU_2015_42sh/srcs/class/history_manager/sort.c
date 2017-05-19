/*
** sort.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/sort.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 22:25:17 2016 Antoine FORET
** Last update Sun Jun  5 20:55:56 2016 Gauthier Cler
*/

#include	"libc.h"

/*
** Sorter for history manager sort method. Use a time based sort.
** @params current testing entry, next entry, sort by time asc
** @return have to switch TRUE / FALSE
*/
t_bool		sort_by_time(t_history_entry *current, t_history_entry *next,
			     t_bool asc)
{
  t_bool	result;

  result = ((current->timestamp < next->timestamp) ? TRUE : FALSE);
  if (current->timestamp == next->timestamp && current->id < next->id)
    result = TRUE;
  if (!asc)
    result = (t_bool)!result;
  return (result);
}

/*
** Sorter for history manager sort method. Use an id based sort.
** @params current testing entry, next entry, sort by id asc
** @return have to switch TRUE / FALSE
*/
t_bool		sort_by_id(t_history_entry *current, t_history_entry *next,
			   t_bool asc)
{
  t_bool	result;

  result = ((current->id < next->id) ? TRUE : FALSE);
  if (!asc)
    result = (t_bool)!result;
  return (result);
}

/*
** Sort all entries using the checker function to determine if have to switch
** @params self, sort by param asc, checker function
** @return void
*/
void		history_manager_sort_by(t_history_manager *self, t_bool asc,
					t_bool (*checker)(
						t_history_entry *current,
						t_history_entry *next,
						t_bool asc))
{
  int		index;
  t_bool	updated;
  int		size;

  updated = TRUE;
  size = self->size - 1;
  while (updated)
    {
      updated = FALSE;
      index = 0;
      while (index < size)
	{
	  if (checker(self->entries[index], self->entries[index + 1], asc))
	    {
	      swap((void *)&self->entries[index],
		   (void *)&self->entries[index + 1]);
	      updated = TRUE;
	    }
	  index++;
	}
    }
}
