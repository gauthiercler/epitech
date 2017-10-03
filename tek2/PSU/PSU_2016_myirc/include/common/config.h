/*
** config.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/common/config.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 17:13:21 2017 Anas Buyumad
** Last update Thu May 25 17:13:22 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_COMMON_CONFIG_H
# define PSU_2016_MYIRC_COMMON_CONFIG_H

# define CHANNEL_NAME_SIZE	(200)
# define CLIENT_NAME_SIZE	(9)
# define MAX_CLIENT_CHANNELS	(10)
# define SYSCALL_FAIL		(-1)
# define RING_BUFFER_SIZE	(512)
# define MSG_MAX_SIZE		(512)
# define TIME_BUFFER_MAX_SIZE	(128)
# define CARRIAGE_RETURN	('\r')
# define LINE_FEED		('\n')
# define CRLF			("\r\n")

enum				e_cmd_type
{
  NONE,
  CONNECT,
  QUIT,
  SET_NICKNAME,
  REGISTER,
  LIST_CHANNELS,
  JOIN_CHANNEL,
  LEAVE_CHANNEL,
  LIST_USERS,
  LIST_CHANNEL_USERS,
  SEND_MESSAGE,
  SEND_FILE,
  ACCEPT_FILE,
};

#endif /* !PSU_2016_MYIRC_COMMON_CONFIG_H */