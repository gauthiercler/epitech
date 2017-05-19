/*
** info.h for info in /home/cler_g/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Fri Dec  4 15:04:32 2015 Gauthier Cler
** Last update Fri Feb 12 15:26:10 2016 Gauthier Cler
*/

#ifndef	INFO_H_
# define INFO_H_

#ifndef READ_SIZE
# define READ_SIZE (4096)
#endif

typedef struct s_env t_env;

struct		s_env
{
  char	       	*elem;
  t_env		*nxt;
};

char    *get_next_line(const int fd);
char    *increase_size(char *res, char *buf);
int     check_buf(char *buf, char *res, int *buf_pos);
int     check_backslash(char *buf);
char    *add_slash(char *buf, char *res, int *buf_pos, char *save);
void	my_putstr(char *str);
void	my_putchar(char c);
char	*get_env(char **ae, char *name);
char	*get_env_list(t_env *env, char *name);
int	count_word(char *str, int *nb);
char	**my_str_to_wordtab(char *str);
int	fill_tab(char *str, char *res, int i, int );
int	count_word_tab(char *str);
char	**my_path_to_tab(char *str);
int	fill_tab_path(char *str, char *res, int i, int );
int	my_sh(t_env *env);
char	*my_strcat(char *str1, char *str2);
int	loop_access(char **exe, char **path, char **ae);
int	execution(char **exe, char **ae, char *abs);
void	fill_env(t_env **env, char **ae);
void	add_end_list(t_env **env, char *str);
void	disp_env(t_env *env);
char	*my_strdup(char *str);
int	my_strcmp(char *str1, char *str2);
void	set_env(t_env **env, char **exe);
void	unset_env(t_env **env, char **exe);
int	delete_list(t_env **env, char *name);
int	my_strncmp(char *str1, char *str2, int nb);
int	my_cd(t_env **env, char **exe);
int	my_exit(char *arg);
char	**generate_env(t_env *env);
char	*env_fill_loop(t_env *tmp);
void	init_var(int *i, int *n);
void	signal_handler(int sig);
int	my_strlen_double(char **str);
int	my_strlen(char *str);
void	loop_sh(t_env **env, char **exe, char **path, char **ae);
void	malloc_error();
void	my_prompt();
void	loop_sh(t_env **env, char **exe, char **path, char **ae);
int	current_dir_bin(char **exe, char **ae);
int	my_atoi(const char *str);

#endif
