/*
** String.h for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:34 2017 Gauthier Cler
** Last update Fri Jan  6 10:17:34 2017 Gauthier Cler
*/

#ifndef STRING_H
# define STRING_H

typedef struct s_String String;

struct s_String
{
  char		*str;
  void		(*assign_s)(String *this, String const *str);
  void		(*assign_c)(String *this, char const *str);
};


void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif
