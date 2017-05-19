/*
** delete_list.c for delete_list in /home/gogo/rendu/gfx_raytracer2/srcs/deletion/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri May 13 00:35:10 2016 Gauthier Cler
** Last update Sun May 22 10:33:12 2016 montag_v
*/

#include		"raytracer.h"

void			delete_list(t_list *list)
{
  t_list                *tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      bunny_free(list);
      list = tmp;
    }
}
