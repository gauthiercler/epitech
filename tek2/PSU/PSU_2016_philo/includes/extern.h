/*
** extern.h for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/includes/extern.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 07 10:01:53 2017 Gauthier Cler
** Last update Tue Mar 07 10:01:53 2017 Gauthier Cler
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

# include	<pthread.h>

int		RCFStartup(int ac, char **av);
void		RCFCleanup();
int		lphilo_eat();
int		lphilo_sleep();
int		lphilo_think();
int		lphilo_take_chopstick(const pthread_mutex_t *mutex_id);
int		lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* __LIBRICEFEREE_EXTERN__ */