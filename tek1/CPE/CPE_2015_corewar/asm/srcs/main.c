/*
** main.c for main in /home/gogo/rendu/CPE_2015_corewar/asm/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Mar 21 10:58:09 2016 Gauthier Cler
** Last update Sat Mar 26 11:40:03 2016 Gauthier Cler
*/

#include	"asm.h"

int		main(int ac, char **av)
{
  int		index;

  index = 1;
  if (ac < 2)
    return (put_fd(2, "Please provide a source file.\n"));
  while (index < ac)
    {
      complex(av[index]);
      index += 1;
    }
  return (SUCCESS);
}
