/*
** responses.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/responses.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 21:04:31 2017 Gauthier Cler
** Last update Sun Jun 04 21:04:31 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_RESPONSES_H
# define PSU_2016_MYIRC_RESPONSES_H

# include			"structures.h"

typedef struct s_response_type	t_response_type;

struct				s_response_type
{
  char				*key;
  void				(*ptr)(t_client *client);
};

void				display_response(t_client *client);
void				clean_response(t_response *response);
void				ping_response(t_client *client);
bool				assess_response(t_client *client);
void				joined_channel(t_client *client);
void				leaved_channel(t_client *client);
void				received_message(t_client *client);
void				changed_username(t_client *client);
void				welcome_message(t_client *client);
void				list_user(t_client *client);

#endif /* !PSU_2016_MYIRC_RESPONSES_H */