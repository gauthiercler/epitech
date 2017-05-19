/*
** main.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/main.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 12:37:38 2016 Anas Buyumad
** Last update Tue Mar 22 11:47:49 2016 Gauthier Cler
*/

#include	"megalovania.h"

int		main(int ac, char **av, char **ae)
{

  (void)ac;
  (void)av;
  if (ae[0] == NULL)
    return (0);
  srand(time(NULL));
  initialize();
  return (0);
}
