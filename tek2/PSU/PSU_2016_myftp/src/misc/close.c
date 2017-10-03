/*
** close_fd.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/close_fd.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 22:48:05 2017 Gauthier Cler
** Last update Mon May 08 22:48:05 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdbool.h>
#include	"misc.h"
#include	"macro.h"

bool		close_filestream(FILE *stream)
{
  if (fclose(stream) == EOF)
    return (display_error(__func__, "fclose"));
  return (true);
}

bool		close_fd(int fd)
{
  if (close(fd) == CALL_ERROR)
    return (display_error(__func__, "close"));
  return (true);
}