/*
** string_extended.h for cpp_libs in /home/foret_a/Lab/cpp_libs/Extended/C/includes/string_extended.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 10 08:51:29 2017 Antoine FORET
** Last update Wed May 10 08:51:29 2017 Antoine FORET
*/

#ifndef STRING_EXTENDED_H_
# define STRING_EXTENDED_H_

# include	<stdio.h>

ssize_t		strpos(const char *haystack, const char *needle);
ssize_t		strpos_binary(const char *haystack,
				     unsigned int haystack_size,
				     const char *needle,
				     unsigned int needle_size);
char		**explode(const char *str, const char delimiter);
size_t		nb_token_ahead(const char *str, char token);
void		strip_extra_token(char *str, char token);
void		free_explode(char **explode);

#endif /* !STRING_EXTENDED_H */
