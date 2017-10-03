/*
** response_type.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/includes/response_type.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 15:59:20 2017 Montagne Valentin
** Last update Mon Jun 26 15:59:20 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_RESPONSE_TYPE_H
# define PSU_2016_ZAPPY_RESPONSE_TYPE_H

typedef enum 				e_command_type
{
  MAP_SIZE,
  CELL_CONTENT,
  MAP_CONTENT,
  TEAM_NAMES,
  PLAYER_POSITION,
  PLAYER_LVL,
  PLAYER_INVENTORY,
  NEED_TIME,
  TIME_MODIFICATION,

  FORWARD,
  RIGHT,
  LEFT,
  LOOK,
  INVENTORY,
  BROADCAST,
  CONNECT_NBR,
  FORK,
  EJECT,
  TAKE_OBJ,
  DROP_OBJ,
  INCANTATION,

  UNKNOWN
}					t_command_type;

#endif /* !PSU_2016_ZAPPY_RESPONSE_TYPE_H */
