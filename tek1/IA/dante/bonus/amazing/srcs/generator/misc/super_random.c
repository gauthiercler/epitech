/*
** super_random.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 16:17:40 2016 Buyumad Anas
** Last update Tue Apr 26 16:48:36 2016 Buyumad Anas
*/

#include	<time.h>
#include	"perfection.h"

void		init_random(void)
{
  time_t	time_seed;
  srand((unsigned int)time(&time_seed));
  xrandom.alpha = rand();
  xrandom.beta = rand();
  xrandom.gamma = rand();
  xrandom.omega = rand();
}

unsigned int	super_random(void)
{
  uint32_t	value;

  value  = ((xrandom.alpha << 6) ^ xrandom.alpha) >> 13;
  xrandom.alpha = ((xrandom.alpha & 4294967294U) << 18) ^ value;
  value  = ((xrandom.beta << 2) ^ xrandom.beta) >> 27;
  xrandom.beta = ((xrandom.beta & 4294967288U) << 2) ^ value;
  value  = ((xrandom.gamma << 13) ^ xrandom.gamma) >> 21;
  xrandom.gamma = ((xrandom.gamma & 4294967280U) << 7) ^ value;
  value  = ((xrandom.omega << 3) ^ xrandom.omega) >> 12;
  xrandom.omega = ((xrandom.omega & 4294967168U) << 13) ^ value;
  return (xrandom.alpha ^ xrandom.beta ^ xrandom.gamma ^ xrandom.omega);
}
