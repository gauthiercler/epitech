/*
** String.h for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:34 2017 Gauthier Cler
** Last update Fri Jan  6 17:04:53 2017 Gauthier Cler
*/

#ifndef STRING_H
# define STRING_H

# include	<stddef.h>

typedef struct s_String String;

struct s_String
{
  char		*str;
  void		(*assign_s)(String *this, String const *str);
  void		(*assign_c)(String *this, char const *str);
  void		(*append_s)(String *this, String const *ap);
  void		(*append_c)(String *this, char const *ap);
  char		(*at)(String *this, size_t pos);
  void		(*clear)(String *this);
  int		(*size)(String *this);
  int		(*compare_s)(String *this, const String *str);
  int		(*compare_c)(String *this, char const *str);
  size_t	(*copy)(String *this, char *s, size_t n, size_t pos);
  char const	*(*c_str)(String *this);
  int		(*empty)(String *this);
  int		(*find_s)(String *this, const String *str, size_t pos);
  int		(*find_c)(String *this, char const *str, size_t pos);
  void		(*insert_s)(String *this, size_t pos, String const *str);
  void		(*insert_c)(String *this, size_t pos, char const *str);
  int		(*to_int)(String *this);
};

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif
