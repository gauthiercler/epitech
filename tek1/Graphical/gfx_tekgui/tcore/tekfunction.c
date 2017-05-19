/*
** tekfunction.c for tekfunction in /home/gogo/rendu/gfx_tekgui/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:23:40 2016 Gauthier Cler
** Last update Fri Feb 26 08:52:02 2016 Gauthier Cler
*/

#include	"tekgui.h"

void	*tekfunction(const char *funcname)
{
  void	*hand;
  char	*error;
  void	*fonc;

  if ((hand = dlopen(NULL, RTLD_LAZY)) == NULL)
    return (NULL);
  if ((fonc = dlsym(hand, funcname)) == NULL)
    return (NULL);
  if ((error = dlerror()) != NULL)
    return (NULL);
  return (fonc);
}
