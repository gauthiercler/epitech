/*
** config.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/include/config.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 10:40:41 2017 Montagne Valentin
** Last update Thu Jun 22 10:40:41 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_CONFIG_H
# define PSU_2016_ZAPPY_CONFIG_H

typedef		struct s_spawn_rate	t_spawn_rate;
typedef		struct s_config		t_config;

# define				DEFAULT_AI_PORT		(8080)
# define				DEFAULT_GFX_PORT	(8081)
# define				DEFAULT_WIDTH		(15)
# define				DEFAULT_HEIGHT		(15)
# define				DEFAULT_FIRST_ID	(1)
# define				DEFAULT_MAX_LEVEL	(8)
# define				DEFAULT_NB_CLIENTS	(3)
# define				DEFAULT_NEEDED_WIN	(6)
# define				DEFAULT_TIME_HATCHING	(600)
# define				DEFAULT_TIME_LAYING	(42)
# define				DEFAULT_FOOD_HEALTH	(126)
# define				DEFAULT_FREQUENCY	(100)
# define				DEFAULT_SPAWN_PER_TICK	(10)
# define				DEFAULT_FOOD_RATE	(100)
# define				DEFAULT_LINEMATE_RATE	(100)
# define				DEFAULT_MENDIANE_RATE	(100)
# define				DEFAULT_PHIRAS_RATE	(100)
# define				DEFAULT_SIBUR_RATE	(100)
# define				DEFAULT_THUSTAME_RATE	(100)
# define				DEFAULT_DERAUMERE	(100)
# define				DEFAULT_SPAWN_DELAY	(3000)
# define				DEFAULT_SPAWN_REG_RATE	(5);
# define				DEFAULT_TIMEOUT		(10)
# define				BASE_TICK		(10)
# define				MAX_SPAWN		(50)
# define				PLAYER_BUFFER_SIZE	(4096 * 20)
# define				READ_SIZE		(256)
# define				WRITE_SIZE		(512)
# define				MIN_TIMEOUT		(7)

# include				<stdint.h>
# include				<stddef.h>

struct					s_spawn_rate
{
  float					food;
  float					linemate;
  float					deraumere;
  float					sibur;
  float					mendiane;
  float					phiras;
  float					thystame;
};

struct 					s_config
{
  uint16_t				ai_port;
  uint16_t				gfx_port;

  unsigned int				width;
  unsigned int				height;

  t_spawn_rate				spawn_rate;
  float					spawn_per_tick;
  unsigned int				spawn_delay;
  unsigned int				spawn_regular_rate;

  size_t				nb_win;
  size_t				max_level;
  unsigned int				nb_clients;
  unsigned int				frequency;
  unsigned int				food_time;
  unsigned int				time_laying;
  unsigned int				id_increment;
  unsigned int				time_hatching;
  char					**team_names;
};

#endif /* !PSU_2016_ZAPPY_CONFIG_H */
