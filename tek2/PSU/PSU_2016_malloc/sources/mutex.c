/*
** mutex.c for mutex in /home/gogo/rendu/tek2/PSU_2016_malloc/sources
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Jan 26 22:49:45 2017 Gauthier Cler
** Last update Fri Feb 10 16:48:08 2017 Gauthier Cler
*/

#include		"malloc.h"

void			mutex_lock()
{
  pthread_mutex_lock(&global.mutex);
  while (global.is_locked)
    pthread_cond_wait(&global.mutex_cond, &global.mutex);
  global.is_locked = true;
}

void			mutex_unlock()
{
  global.is_locked = false;
  pthread_cond_signal(&global.mutex_cond);
  pthread_mutex_unlock(&global.mutex);
}
