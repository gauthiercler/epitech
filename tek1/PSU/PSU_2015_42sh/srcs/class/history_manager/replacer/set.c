/*
** set.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/replacer/set.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 19:02:30 2016 Antoine FORET
** Last update Sun Jun  5 20:51:32 2016 Gauthier Cler
*/

#include	"class/history_manager.h"

/*
** Set target for next replacement and indicate that an action is required
** @params self, target
** @return void
*/
void		history_replacer_set(t_history_replacer *self,
				     unsigned int target)
{
  self->id = target;
  self->updated = TRUE;
}
