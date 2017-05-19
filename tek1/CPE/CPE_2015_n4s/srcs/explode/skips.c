/*
** skips.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/explode/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 15:46:10 2016 Buyumad Anas
** Last update Mon May 23 15:46:12 2016 Buyumad Anas
*/

#include	"ia.h"

void		skip_purge(char *string, int *index)
{
  while (string[*index] && (string[*index] == ' ' || string[*index] == '\t'))
    *index += 1;
}

void		skip_explode(char *string, int *index, char delimiter)
{
  while (string[*index] && string[*index] == delimiter)
    *index += 1;
}
