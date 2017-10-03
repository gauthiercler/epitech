/*
** nb_token_ahead.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/string_extended/nb_token_ahead.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 04 09:43:51 2017 Antoine FORET
** Last update Sun Jun 04 09:43:51 2017 Antoine FORET
*/

#include	"string_extended.h"

size_t		nb_token_ahead(const char *str, char token)
{
  size_t	nb_token;

  nb_token = 0;
  while (str[nb_token] == token && str[nb_token] != '\0')
    nb_token += 1;
  return (nb_token);
}