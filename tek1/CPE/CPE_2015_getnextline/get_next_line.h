/*
** get_next_line.h for get_next_line in /home/gauthier/rendu/CPE_2015_getnextline
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan  4 09:39:53 2016 Gauthier Cler
** Last update Sun Jan 17 19:45:18 2016 Gauthier Cler
*/

#ifndef	GET_NEXT_LINE_
# define GET_NEXT_LINE_

#ifndef READ_SIZE
# define READ_SIZE (4096)
#endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	*increase_size(char *res, char *buf);
int	check_buf(char *buf, char *res, int *buf_pos);
int	check_backslash(char *buf);
char	*add_slash(char *buf, char *res, int *buf_pos, char *save);

#endif /* GET_NEXT_LINE_ */
