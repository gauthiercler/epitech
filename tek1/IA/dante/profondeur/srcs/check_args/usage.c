/*
** usage.c for usage in /home/gogo/rendu/dante/profondeur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May  1 14:04:02 2016 Gauthier Cler
** Last update Sun May  1 14:13:36 2016 Gauthier Cler
*/

#include		"solver.h"

int			print_usage()
{
  format(2, "Usage: ./solver [map] [OPTIONS]\n");
  format(2, "--color : path in color\n");
  format(2, "--count : count step from start to end\n");
  return (ERROR);
}
