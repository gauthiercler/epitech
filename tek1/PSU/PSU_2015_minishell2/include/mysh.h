/*
** mysh.h for mysh in /home/gogo/rendu/PSU_2015_minishell2/include
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Mar 16 08:38:08 2016 Gauthier Cler
** Last update Mon Apr 18 23:52:22 2016 Gauthier Cler
*/

#ifndef MY_SH_
# define MY_SH_

#ifndef READ_SIZE
# define READ_SIZE	(4096)
#endif

#ifndef SUCCESS
# define SUCCESS	(0)
#endif

#ifndef ERROR
# define ERROR		(-1)
#endif

#ifndef RED
# define RED		"\e[31m"
#endif

#ifndef BLUE
# define BLUE		"\e[34m"
#endif

#ifndef WHITE
# define WHITE		"\e[0m"
#endif

#ifndef LEFT
# define LEFT		(10)
#endif

#ifndef RIGHT
# define RIGHT		(11)
#endif

#ifndef DLEFT
# define DLEFT		(12)
#endif

#ifndef DRIGHT
# define DRIGHT		(13)
#endif

#ifndef MAX_LENGTH
# define MAX_LENGTH	(4096)
#endif

#include		<stdbool.h>

typedef struct		s_env
{
  char			**env;
  int			fd[2];
  int			save;
  bool			redir;
  bool			redir_pipe;
  int			fd_file;
}			t_env;

typedef struct		s_redir
{
  char			*arg1;
  char			*arg2;
  int			type;
}			t_redir;

extern bool		prompt;

/*
** GET_NEXT_LINE
*/

char			*get_next_line(const int fd);
char			*increase_size(char *res, char *buf);
int			check_buf(char *buf, char *res, int *buf_pos);
int			check_backslash(char *buf);
char			*add_slash(char *buf, char *res, int *buf_pos);

/*
** MISC
*/

void			init_couple(int *a, int *b);
void			my_bzero(char *str, int size);
void			my_strcpy(char *src, char *dest);
int			put_fd(int fd, char *str);
int			format(int fd, char *str, ...);
int			put_nb(int fd, int nb);
char			*my_strdup(char *str);
char			*my_strcat(char *str1, char *str2);
void			malloc_error();
void			disp_prompt(char **ae);
void			signal_handler(int sig);
int			my_strlen(char *str);
int			my_strcmp(char *str1, char *str2);
int			my_strncmp(char *str1, char *str2, int nb);
int			is_num(char *str);
int			my_atoi(char *str);
void			*xmalloc(unsigned int size);
int			is_empty(char *str);

/*
** TAB
*/

char			**my_str_to_wordtab(char *str);
char			**separator_to_tab(char *str, char separator);

/*
** SHELL
*/

int			my_sh(char **ae);
void			command_finder(t_env *env, char **cmd, char **path);
void			my_exit(char **cmd);
int			my_cd(t_env *env, char **cmd);
int			path_exec(t_env *env, char **cmd, char **path);
int			current_dir_exec(t_env *env, char **cmd);
int			launch_command(char *instruction, t_env *env);

/*
** ENV
*/

int			disp_env(t_env *env);
int			check_env(char **ae, char *request);
char			**gen_path(char **ae);
char			**clone_env(char **ae);
int			set_env(t_env *env, char **cmd);
int			unset_env(t_env *env, char **cmd);
int			tab_len(char **tab);

/*
** CLEAN
*/

void			free_tab(char **tab);

/*
** PIPE
*/

int			check_pipe(char *instruction);
int			pipe_command(char *instruction, t_env *env);
int			first_pipe_exec(char *instruction, t_env *env);
int			multi_pipe_exec(char *instruction, t_env *env);
int			end_pipe_exec(char *instruction, t_env *env);
int			is_valid_pipe(char **tab);

/*
** REDIR
*/

int			redir_command(char *instruction, t_env *env);
int			check_redir(char *instruction);
int			right_redir(t_redir *redir, t_env *env);
int			left_redir(t_redir *redir, t_env *env);
int			dright_redir(t_redir *redir, t_env *env);
int			dleft_redir(t_redir *redir, t_env *env);

#endif
