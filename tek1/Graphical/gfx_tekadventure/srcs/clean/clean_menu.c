/*
** clean_menu.c for clean_menu in /home/gogo/rendu/gfx_tekadventure
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 16 18:29:31 2016 Gauthier Cler
** Last update Sat Apr 16 18:38:37 2016 Gauthier Cler
*/

#include	"adventure.h"

void		clean_menu(t_menu *menu)
{
  bunny_delete_clipable(menu->bg);
  bunny_delete_clipable(menu->play);
  bunny_delete_clipable(menu->exit);
}
