/*
** io.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/io.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 21:02:07 2016 Antoine FORET
** Last update Mon May 30 21:02:07 2016 Antoine FORET
*/

#include	"io.h"

/*
** Define the passed io values
** @params target io, new in, new out
** @return void
*/
void		set_io(t_io *io, int in, int out)
{
  io->in = in;
  io->out = out;
}
