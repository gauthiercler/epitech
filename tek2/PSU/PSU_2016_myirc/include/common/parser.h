/*
** parser.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/common/parser.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 10:11:15 2017 Gauthier Cler
** Last update Wed May 31 10:11:15 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_COMMON_PARSER_H
# define PSU_2016_MYIRC_COMMON_PARSER_H

# include		<stdint.h>

# define CR		('\r')
# define LF		('\n')

char			**split(char *input, char *delimiters);
uint16_t		count_indexes(char **array);
void			strip_crlf(char *string);

#endif /* !PSU_2016_MYIRC_COMMON_PARSER_H */