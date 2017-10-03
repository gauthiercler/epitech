/*
** channel_manager.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/channel_manager.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 02:18:58 2017 Anas Buyumad
** Last update Sun May 28 02:18:58 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_CHANNEL_MANAGER_H
# define PSU_2016_MYIRC_SERVER_CHANNEL_MANAGER_H

# define NO_CHANNEL	(-1)

# include		"server/structures.h"

t_channel		*get_channel_by_id(t_channel_mgr *manager,
					    uint8_t channel_id);
t_channel		*get_channel_by_name(t_channel_mgr *manager,
					      const char *name);
size_t			get_nb_active_channels(t_channel_mgr *manager);
int8_t			get_max_channel_id(t_channel_mgr *manager);
int8_t			get_available_channel_id(t_channel_mgr *manager);
bool			create_channel(t_channel_mgr *manager,
					   char *channel_name);
bool		remove_channel_by_id(t_channel_mgr *manager,
					 int8_t channel_id);
bool		remove_channel_by_name(t_channel_mgr *manager,
					   const char *channel_name);

#endif /* !PSU_2016_MYIRC_SERVER_CHANNEL_MANAGER_H */