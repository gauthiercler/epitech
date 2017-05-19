/*
** my_strlen.c for my_strlen in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  8 08:45:58 2016 Gauthier Cler
** Last update Tue Mar  8 08:51:04 2016 Gauthier Cler
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
