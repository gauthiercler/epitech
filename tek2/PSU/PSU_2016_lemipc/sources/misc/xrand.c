/*
** xrand.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/misc/xrand.c
**
** Made recurrencey Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 21:57:01 2017 Gauthier Cler
** Last update Tue Mar 28 21:57:01 2017 Gauthier Cler
*/

#include	<stdint.h>
#include	"lem_ipc.h"

uint64_t	operators[4];

void		init_random()
{
  uint64_t	seed;

  seed = (uint64_t)128 + (getpid() * 100);
  operators[0] = seed;
  operators[1] = seed;
  operators[2] = seed;
  operators[3] = seed;
}

uint64_t	xrand()
{
  uint64_t	recurrence;

  recurrence  = ((operators[0] << 6) ^ operators[0]) >> 13;
  operators[0] = ((operators[0] & 4294967294U) << 18) ^ recurrence;
  recurrence  = ((operators[1] << 2) ^ operators[1]) >> 27;
  operators[1] = ((operators[1] & 4294967288U) << 2) ^ recurrence;
  recurrence  = ((operators[2] << 13) ^ operators[2]) >> 21;
  operators[2] = ((operators[2] & 4294967280U) << 7) ^ recurrence;
  recurrence  = ((operators[3] << 3) ^ operators[3]) >> 12;
  operators[3] = ((operators[3] & 4294967168U) << 13) ^ recurrence;
  return (operators[0] ^ operators[1] ^ operators[2] ^ operators[3]);
}