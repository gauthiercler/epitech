/*
** explode.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/parser/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Tue May 31 15:35:47 2016 Vincent Dusautoir
** Last update Sun Jun  5 18:47:15 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		<string.h>
#include		"libc.h"

/*
** Check str is a token at the pointer
** @params self, *str
** @return success -> tokens error -> -1
*/
static int		parser_is_token(t_parser *self, char *str)
{
  unsigned int		tokens;

  tokens = 0;
  while (self->tokens[tokens])
    {
      if (strncmp(self->tokens[tokens], str,
		  strlen(self->tokens[tokens])) == 0)
	return (tokens);
      tokens++;
    }
  return (-1);
}

static void		parser_nb_word_token(t_bool *in_word,
					     unsigned int *index,
					     char *token,
					     unsigned int *nb_words)
{
  *in_word = FALSE;
  *index += strlen(token) - 1;
  *nb_words += 1;
}

/*
** Calc the number of words in the sentence
** @params *self, *str
** @return nb_words
*/
static unsigned int	parser_nb_words(t_parser *self, char *str)
{
  unsigned int		nb_words;
  unsigned int		index;
  int			token;
  t_bool		in_word;

  in_word = FALSE;
  index = 0;
  nb_words = 0;
  while (str[index] != '\0')
    {
      if (str[index] == ' ' || str[index] == '\t')
	in_word = FALSE;
      else if ((token = parser_is_token(self, &str[index])) != -1)
	parser_nb_word_token(&in_word, &index, self->tokens[token], &nb_words);
      else if (in_word == FALSE)
	{
	  nb_words++;
	  in_word = TRUE;
	}
      index++;
    }
  return (nb_words);
}

/*
** Calc the length of a word
** @params *self, *str
** @return length
*/
static unsigned int	parser_word_length(t_parser *self, char *str)
{
  unsigned int		length;
  int			token;

  length = 0;
  if ((token = parser_is_token(self, str)) != -1)
    return (strlen(self->tokens[token]));
  while (str[length] != '\0' && str[length] != ' ' && str[length] != '\t' &&
	 parser_is_token(self, &str[length]) == -1)
    length++;
  return (length);
}

/*
** Explode a string in array
** @params *self, *str
** @return success -> tab error error -> NULL
*/
char			**parser_explode(t_parser *self, char *str)
{
  char			**array;
  unsigned int		index;
  unsigned int		current_word;

  index = 0;
  current_word = 0;
  purge(str);
  array = malloc(sizeof(char *) * (parser_nb_words(self, str) + 1));
  if (array == NULL)
    return (NULL);
  while (str[index] != '\0')
    {
      if ((parser_is_token(self, &str[index])) != -1 ||
	  (str[index] != ' ' && str[index] != '\t'))
	{
	  array[current_word++] = strndup(&str[index],
					  parser_word_length(self, &str[index]));
	  index += parser_word_length(self, &str[index]) - 1;
	}
      index++;
    }
  array[current_word] = NULL;
  return (array);
}
