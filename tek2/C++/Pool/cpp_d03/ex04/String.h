/*
** String.h for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:34 2017 Gauthier Cler
** Last update Fri Jan  6 11:46:47 2017 Gauthier Cler
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
};

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif
