/*
** receive_until.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/receive_until.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 09 16:27:29 2017 Antoine FORET
** Last update Tue May 09 16:27:29 2017 Antoine FORET
*/

#include	<malloc.h>
#include	<string_extended.h>
#include	<memory.h>
#include	"tcp_socket.h"

static void	feed_buffer(t_tcp_socket *self, const char *buff)
{
  char		*result;

  if (self->buffer != NULL)
  {
    result = malloc(sizeof(char) * (strlen(self->buffer) + strlen(buff) + 1));
    if (result == NULL)
      return ;
    strcpy(result, self->buffer);
    strcat(result, buff);
    free(self->buffer);
  }
  else
    result = strdup(buff);
  self->buffer = result;
}

static char	*extract_from_buff(t_tcp_socket *self,
				      ssize_t pos,
				      ssize_t delimiter_length)
{
  char		*result;

  if (pos < 0)
  {
    result = self->buffer;
    self->buffer = NULL;
    return (result);
  }
  else
  {
    result = self->buffer;
    result[pos] = '\0';
    self->buffer = strdup(&result[pos + delimiter_length]);
    return (result);
  }
}

ssize_t		tcp_socket_receive_until(t_tcp_socket *self,
						char **data,
						const char *delimiter)
{
  char		buff[4096];
  ssize_t	pos;
  ssize_t	readed;

  readed = 0;
  while ((self->buffer == NULL ||
	  strpos_binary(self->buffer, (unsigned int)strlen(self->buffer),
			delimiter, (unsigned int)strlen(delimiter)) == -1) &&
	 (readed = self->receive(self, buff, 4095, true)) > 0)
  {
    buff[readed] = '\0';
    feed_buffer(self, buff);
  }
  if (self->buffer == NULL || strlen(self->buffer) == 0)
  {
    self->connected = false;
    *data = NULL;
    return (SOCKET_ERROR);
  }
  pos = strpos_binary(self->buffer, (unsigned int)strlen(self->buffer),
		      delimiter, (unsigned int)strlen(delimiter));
  *data = extract_from_buff(self, pos, strlen(delimiter));
  return ((*data == NULL) ? -1 : (ssize_t)strlen(*data));
}