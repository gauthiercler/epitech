/*
** print_error.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/print_error.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 12:42:52 2017 Montagne Valentin
** Last update Thu Jun 22 12:42:52 2017 Montagne Valentin
*/

#include				<stdarg.h>
#include				<stdio.h>
#include 				"parser.h"

void					print_usage(char *binary_name)
{
  printf("[USAGE] %s\n", binary_name);
  printf("[ARGS]\n");
  printf("\t-p\tDefine the server's port.\n");
  printf("\t-x\tDefine the map's width.\n");
  printf("\t-y\tDefine the map's height.\n");
  printf("\t-n\tDefine all the team names.\n");
  printf("\t-c\tDefine the max nb of players in a team.\n");
  printf("\t-f\tDefine the frequency of the server.\n");
  printf("\t-X\tUse -X to set the rate for the spawn (-F for food...).\n");
  printf("\t-g\tDefine the port of the graphical client.\n");
  printf("\t-h\tDisplay this help.\n\n");
}
t_error					print_error(t_error error,
						     char *msg, ...)
{
  va_list				list;

  fprintf(stderr, "%s", "[PARSING-ARGS] ");
  va_start(list, msg);
  vfprintf(stderr, msg, list);
  va_end(list);
  return (error);
}
