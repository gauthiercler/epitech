/*
** backup_pos.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 22:29:18 2016 Buyumad Anas
** Last update Sun Apr 17 23:30:29 2016 Gauthier Cler
*/

#include	"adventure.h"

void		backup_pos(t_character *character)
{
  character->save_pos.x = character->position.x;
  character->save_pos.y = character->position.y;
  character->position.x = 500;
  character->position.y = 500;
}
