/*
** load_menu.c for load_menu in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Fri Apr 15 14:31:27 2016 valentin montagne
** Last update Sun Apr 17 16:31:57 2016 Gauthier Cler
*/

#include	<lapin.h>
#include	"adventure.h"

int		load_menu(t_menu *menu)
{
  if ((menu->bg = bunny_load_picture("./ressources/Menu/menu.png")) == NULL)
    return (ERROR);
  if ((menu->play = bunny_load_picture("./ressources/Menu/Play.png")) == NULL)
    return (ERROR);
  if ((menu->exit = bunny_load_picture("./ressources/Menu/exit.png")) == NULL)
    return (ERROR);
  if ((menu->music = bunny_load_music("./ressources/music/menu.ogg")) == NULL)
    return (ERROR);
  menu->play_music = true;
  return (SUCCESS);
}
