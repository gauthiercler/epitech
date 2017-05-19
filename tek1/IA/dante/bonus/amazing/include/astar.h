/*
** solver.h for solver in /home/gogo/rendu/dante/profondeur/include/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 22:41:51 2016 Gauthier Cler
** Last update Sun May 22 17:04:32 2016 Buyumad Anas
*/

#ifndef SOLVERA_H_
# define SOLVERA_H_

#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

typedef struct s_nodea		t_nodea;
typedef struct s_lista		t_lista;
typedef struct s_amazing	t_amazing;

typedef struct			s_posa
{
  int				x;
  int				y;
}				t_posa;

struct				s_nodea
{
  t_posa			pos;
  t_posa			father;
  int				f;
  int				g;
  int				h;
  t_nodea			*next;
};

struct				s_lista
{
  int				x;
  int				y;
  t_lista			*next;
};

typedef struct			s_mapa
{
  int				size_x;
  int				size_y;
  char				**array;
}				t_mapa;

typedef struct			s_solvea
{
  t_mapa			map;
  t_lista			*list;
}				t_solvea;

extern int			goal_x;
extern int			goal_y;

#ifndef SUCCESS
# define SUCCESS		(0)
#endif

#ifndef ERROR
# define ERROR			(1)
#endif

#ifndef READ_SIZE
# define READ_SIZE		(4096)
#endif

#ifndef START_X
# define START_X		(0)
#endif

#ifndef START_Y
# define START_Y		(0)
#endif

#ifndef VISITED
# define VISITED		'o'
#endif

#ifndef WALL
# define WALL			'X'
#endif

#ifndef POSSIBLE
# define POSSIBLE		'*'
#endif

#ifndef WAITING
# define WAITING		'-'
#endif

#ifndef EXIT
# define EXIT			'S'
#endif

#ifndef NORTH_A
# define NORTH_A		(10)
#endif

#ifndef SOUTH_A
# define SOUTH_A		(11)
#endif

#ifndef EAST_A
# define EAST_A			(12)
#endif

#ifndef WEST_A
# define WEST_A			(13)
#endif

/*
** -- Misc --
*/

int				format(int fd, char *str, ...);
int				my_atoi(char *str);
int				put_fd(int fd, char *string);
int				put_nb(int fd, int nb);
void				*p_error(char *str);
int				str_len(char *string);
char				*str_dup(char *string);
void				init_random(void);
unsigned int			super_random(void);
void				*xmalloc(unsigned int size);
char				*get_next_line(const int fd);
int				my_strcmp(char *s1, char *s2);

/*
** -- Loading--
*/

char				**load_map(char *filename, int *size_x,
					   int *size_y);

/*
** -- Solve --
*/

t_lista				*solve_maze_a(t_amazing *amazing, t_mapa *map);
int				get_pos_xa(int x, int direction);
int				get_pos_ya(int y, int direction);
t_lista				*find_patha(t_nodea *open,
					   t_nodea *closed, t_nodea *selected);
int				heuristic(int pos_x, int pos_y);
void				disp_mapa(char **map);

/*
** -- List --
*/

void				disp_node(t_nodea *node);
void				change_node(t_nodea *node, t_nodea new);
void				add_node(t_nodea **node, t_nodea new);
void				add_to_lista(t_lista **list, int x, int y);
void				add_end_lista(t_lista **list, int x, int y);
void				disp_lista(t_lista *list);
void				switch_lista(t_nodea **close, t_nodea **open,
					    t_nodea *selected);
t_nodea				*get_node(t_nodea *node, t_nodea new);
t_nodea				*get_lower_node(t_nodea *open);

/*
** -- Clean --
*/

void				clean_mapa(char **map);
void				clean_node(t_nodea *list);
void				clean_lista(t_lista *list);

/*
** -- Fill --
*/

void				fill_mapa(char **map, t_lista *list,
					 int *counter);
void				empty_mapa(char **map);

/*
** -- Args --
*/

int				print_usage();
int				check_args(int ac, char **av, bool *color,
					   bool *count);

/*
** Verif
*/

int				is_in_list(t_nodea *list, int x, int y);
int				is_possiblea(t_nodea *open, t_mapa *map,
					    int direction, t_posa *pos);

#endif
