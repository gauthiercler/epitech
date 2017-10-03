/*
** chrono.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/chrono.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 15:25:51 2017 Antoine FORET
** Last update Thu Jun 22 15:25:51 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_CHRONO_H_
# define PSU_2016_ZAPPY_CHRONO_H_

typedef			struct s_chrono		t_chrono;

# include		<sys/time.h>

struct			s_chrono
{
  struct timeval	time;

  void			(*reset)(t_chrono *self);
  time_t		(*time_elapsed)(t_chrono *self);

  void			(*destroy)(t_chrono *self);
};

t_chrono		*new_chrono();
void			chrono_destroy(t_chrono *self);

void			chrono_reset(t_chrono *self);
time_t			chrono_time_elapsed(t_chrono *self);

#endif /* !PSU_2016_ZAPPY_CHRONO_H_ */
