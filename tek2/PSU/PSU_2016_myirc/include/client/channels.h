/*
** channels.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/channels.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 19:06:48 2017 Gauthier Cler
** Last update Mon Jun 05 19:06:48 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_CHANNELS_H
# define PSU_2016_MYIRC_CHANNELS_H

# include	"common/structures.h"

void		add_channel(t_channel *channels, const char *name);
char		*get_max_channel_name(t_channel *channels);
void		update_channels_ids(t_channel *channels, int8_t max_value);
int8_t		remove_channel(t_channel *channels,
				     const char *channel_name);
int8_t		get_max_channel_id(t_channel *channels);

#endif /* !PSU_2016_MYIRC_CHANNELS_H */
