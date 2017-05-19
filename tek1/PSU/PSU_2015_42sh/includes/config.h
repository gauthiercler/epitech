/*
** config.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 19:17:24 2016 Vincent Dusautoir
** Last update Sun Jun  5 15:02:52 2016 Vincent Dusautoir
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# ifndef NB_BUILTINS
#  define NB_BUILTINS (10)
# endif /* !NB_BUILTINS */

# ifndef BLOCK_ENV
#  define BLOCK_ENV (10)
# endif /* !BLOCK_ENV */

# ifndef SEMICOLON_TOKEN
#  define SEMICOLON_TOKEN (";")
# endif /* !SEMICOLON_TOKEN */

# ifndef PIPE_TOKEN
#  define PIPE_TOKEN ("|")
# endif /* !PIPE_TOKEN */

# ifndef AND_TOKEN
#  define AND_TOKEN ("&&")
# endif /* !AND_TOKEN */

# ifndef OR_TOKEN
#  define OR_TOKEN ("||")
# endif /* !OR_TOKEN */

# ifndef SIMPLE_LEFT_TOKEN
#  define SIMPLE_LEFT_TOKEN ("<")
# endif /* !SIMPLE_LEFT_TOKEN */

# ifndef SIMPLE_RIGHT_TOKEN
#  define SIMPLE_RIGHT_TOKEN (">")
# endif /* !SIMPLE_RIGHT_TOKEN */

# ifndef DOUBLE_RIGHT_TOKEN
#  define DOUBLE_RIGHT_TOKEN (">>")
# endif /* !DOUBLE_RIGHT_TOKEN */

# ifndef DOUBLE_LEFT_TOKEN
#  define DOUBLE_LEFT_TOKEN ("<<")
# endif /* !DOUBLE_LEFT_TOKEN */

# ifndef NB_TOKENS
#  define NB_TOKENS (9)
# endif /* !NB_TOKENS */

# ifndef MISSING_NAME
#  define MISSING_NAME ("Missing name for redirect.")
# endif /* !MISSIGN_NAME */

# ifndef PATH_ENV
#  define PATH_ENV ("PATH")
# endif /* !PATH_ENV */

# ifndef RIGHTS
#  define RIGHTS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
# endif /* !RIGHTS */

# ifndef PATH_DELIMITER
#  define PATH_DELIMITER (':')
# endif /* !PATH_DELIMIER */

# ifndef PROMPT_MESSAGE
#  define PROMPT_MESSAGE ("$> ")
# endif /* !PROMPT_MESSAGE */

# ifndef EXIT_MESSAGE
#  define EXIT_MESSAGE ("Bye")
# endif /* !EXIT_MESSAGE */

# ifndef BLOCK_HISTORY
#  define BLOCK_HISTORY (20)
# endif /* !BLOCK_HISTORY */

#endif
