/*
** display_time.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/misc/display_time.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 17:58:36 2017 Gauthier Cler
** Last update Mon Jun 05 17:58:36 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<time.h>
#include	<unistd.h>
#include	"common/misc.h"
#include	"common/error.h"
#include	"client/structures.h"

void		display_time()
{
  time_t	rawtime;
  struct tm	*info;
  char		buffer[TIME_BUFFER_MAX_SIZE];

  if (time(&rawtime) == ((time_t)SYSCALL_FAIL))
    throw_error("time", __func__, &operational, CRITICAL);
  info = localtime(&rawtime);
  if (info == NULL)
    throw_error("localtime", __func__, &operational, CRITICAL);
  strftime(buffer, TIME_BUFFER_MAX_SIZE, "%H:%M:%S", info);
  write_in_fd(STDOUT_FILENO, "%s", buffer);
}