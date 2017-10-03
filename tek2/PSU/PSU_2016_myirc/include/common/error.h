/*
** error.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/common/error.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:01:33 2017 Anas Buyumad
** Last update Sat May 27 17:01:33 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_COMMON_ERROR_H
# define PSU_2016_MYIRC_COMMON_ERROR_H

# include	<stdbool.h>

enum		e_error_type
{
  MINOR,
  CRITICAL
};

void		throw_error(const char *sys_caller,
				const char *func_caller,
				bool *operational,
				enum e_error_type type);

#endif /* !PSU_2016_MYIRC_COMMON_ERROR_H */