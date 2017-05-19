/*
** philo.h for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/includes/philo.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Mar 06 17:51:13 2017 Gauthier Cler
** Last update Mon Mar 06 17:51:13 2017 Gauthier Cler
*/

#ifndef PSU_2016_PHILO_PHILO_H
# define PSU_2016_PHILO_PHILO_H

# include			<pthread.h>
# include			<stdbool.h>
# include			"extern.h"

typedef struct s_node		t_node;
typedef struct s_philo		t_philo;
typedef struct s_stick		t_stick;
typedef struct s_arg		t_arg;
typedef enum e_node_type	t_node_type;
typedef union u_node_data	t_node_data;

enum				e_node_type
{
  PHILO = 0,
  STICK,
};

union				u_node_data
{
  t_stick			*stick;
  t_philo			*philo;
};

struct				s_node
{
  t_node_type			node_type;
  t_node_data			data;
  t_node			*prev;
  t_node			*next;
};

struct				s_arg
{
  size_t			eat_value;
  size_t			philo_value;
};

struct				s_philo
{
  pthread_t			handle;
  size_t			max_portions;
  bool				handed_side;
};

struct				s_stick
{
  pthread_mutex_t		mutex;
};

extern bool			active_simulation;
extern pthread_barrier_t	barrier;

bool				display_error();
bool				custom_error(const char *error);
bool				create_list(const size_t nb_philo,
						t_node **list,
						size_t eat_value);
void				clean_list(t_node **list);
void				*simulation(void *arg);
bool				start_simulation(t_node *list);
void				philo_sleep(t_node *node);
void				philo_think(t_node *node);
void				philo_eat(t_node *node);
void				philo_pick_right(t_node *node);
void				philo_pick_left(t_node *node);
void				philo_release_right(t_node *node);
void				philo_release_left(t_node *node);
void				init_opt(t_arg *arg);
bool				get_opt(int ac, char **av, t_arg *arg);

#endif /* !PSU_2016_PHILO_PHILO_H */
