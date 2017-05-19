/*
** build_sequences.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:08:08 2016 Buyumad Anas
** Last update Sun Jun  5 20:13:29 2016 Buyumad Anas
*/

#include	<string.h>
#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Gets the terminal from the environment
** @params env
** @return char * ; Success => name, Error => NULL
*/
char		*get_term(char **env)
{
  int		index;

  index = 0;
  while (env[index])
    {
      if (strncmp(env[index], "TERM=", 5) == 0)
	return (env[index] + 5);
      index += 1;
    }
  return (NULL);
}

/*
** Dups a key sequence.
** @params name
** @return char * ; Success => name, Error => NULL
*/
static char 	*dup_key(char *capname)
{
  char		*tmp;
  char		*res;

  if ((tmp = tigetstr(capname)) == NULL)
    return (NULL);
  res = strdup(tmp);
  return (res);
}

/*
** Builds termcaps sequences
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
static bool	line_editor_build_second_sequences(t_line_editor *self)
{
  if ((self->keys[L_BACKSPACE].sequence = dup_key("kbs")) == NULL)
    return (false);
  self->keys[L_BACKSPACE].handle = line_editor_handle_backspace;
  if ((self->keys[L_TAB].sequence = strdup(S_TAB)) == NULL)
    return (false);
  self->keys[L_TAB].handle = NULL;
  if ((self->keys[L_ERASE].sequence = strdup(S_ERASE)) == NULL)
    return (false);
  self->keys[L_ERASE].handle = line_editor_handle_erase;
  if ((self->keys[L_CLEAR].sequence = strdup(S_CLEAR)) == NULL)
    return (false);
  self->keys[L_CLEAR].handle = line_editor_handle_clear;
  if ((self->keys[L_EOT].sequence = strdup(S_EOT)) == NULL)
    return (false);
  self->keys[L_EOT].handle = NULL;
  self->keys[NB_SEQUENCES].sequence = NULL;
  self->keys[NB_SEQUENCES].handle = NULL;
  return (true);
}

/*
** Builds termcaps sequences
** @params self, env
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_build_sequences(t_line_editor *self, char **env)
{
  int		ret;
  char		*key_pad;

  setupterm(get_term(env), 1, &ret);
  if (ret <= 0)
    return (false);
  if ((key_pad = tigetstr("smkx")) == NULL)
    return (false);
  putp(key_pad);
  if ((self->keys[L_KEY_LEFT].sequence = dup_key("kcub1")) == NULL)
    return (false);
  self->keys[L_KEY_LEFT].handle = line_editor_handle_left;
  if ((self->keys[L_KEY_RIGHT].sequence = dup_key("kcuf1")) == NULL)
    return (false);
  self->keys[L_KEY_RIGHT].handle = line_editor_handle_right;
  if ((self->keys[L_KEY_UP].sequence = dup_key("kcuu1")) == NULL)
    return (false);
  self->keys[L_KEY_UP].handle = line_editor_handle_up;
  if ((self->keys[L_KEY_DOWN].sequence = dup_key("kcud1")) == NULL)
    return (false);
  self->keys[L_KEY_DOWN].handle = line_editor_handle_down;
  if (line_editor_build_second_sequences(self) == false)
    return (false);
  return (true);
}
