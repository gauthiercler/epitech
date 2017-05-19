/*
** key_assesment.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/data_manipulation/key_assesment.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar  01 13:07:20 2016 Anas Buyumad
** Last update Wed Mar 16 08:13:10 2016 Gauthier Cler
*/

#include	"tetris.h"

void	assess_key(t_init *setup, int mode, char *key)
{
  if (mode == 1)
    setup->keymap.left = my_strdup(key);
  else if (mode == 2)
    setup->keymap.right = my_strdup(key);
  else if (mode == 3)
    setup->keymap.turn = my_strdup(key);
  else if (mode == 4)
    setup->keymap.drop = my_strdup(key);
  else if (mode == 5)
    setup->keymap.quit = my_strdup(key);
  else if (mode == 6)
    setup->keymap.pause = my_strdup(key);
}
