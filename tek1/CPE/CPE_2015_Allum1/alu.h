/*
** alu.h for alu in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Feb  9 23:35:31 2016 Gauthier Cler
** Last update Fri Feb 12 14:44:00 2016 Gauthier Cler
*/

#ifndef ALU_H_
# define ALU_H_

#ifndef READ_SIZE
# define READ_SIZE (4096)
#endif

#define PLAYER (0)
#define IA (1)

char    *get_next_line(const int fd);
char    *increase_size(char *res, char *buf);
int     check_buf(char *buf, char *res, int *buf_pos);
int     check_backslash(char *buf);
char    *add_slash(char *buf, char *res, int *buf_pos, char *save);
int	player_input(int *alu);
int	er(char *str, int *alu);
void	disp_remove(char *str, int matches, int line);
void	ia_input(int *allu, int *turn);
int	my_strlen(char *str);
int	is_num(char *str);
int	my_atoi(char *str);
int	player_match_operation(int *alu, int line, int matches);
void	my_putstr(char *str);

#endif
