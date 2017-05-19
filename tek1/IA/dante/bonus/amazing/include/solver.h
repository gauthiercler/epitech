/*
** solver.h for solver in /home/gogo/rendu/dante/profondeur/include/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 22:41:51 2016 Gauthier Cler
** Last update Sat May 21 16:52:04 2016 Gauthier Cler
*/

#ifndef SOLVER_H_
# define SOLVER_H_

#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

typedef struct s_pile		t_pile;
typedef struct s_list_depth	t_list_depth;
typedef struct s_amazing	t_amazing;

struct				s_pile
{
  int				x;
  int				y;
  t_pile			*next;
  int				father_x;
  int				father_y;
};

typedef struct			s_pos
{
  int				x;
  int				y;
}				t_pos;

struct				s_list_depth
{
  int				x;
  int				y;
  t_list_depth			*next;
};

typedef struct			s_map_depth
{
  int				size_x;
  int				size_y;
  char				**array;
}				t_map_depth;

typedef struct			s_solve
{
  t_map_depth			map;
  t_list_depth			*list;
}				t_solve;

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

#ifndef CONSIDERED
# define CONSIDERED		'Z'
#endif

#ifndef WALL_DEPTH
# define WALL_DEPTH		'X'
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

#ifndef NORTH_DEPTH
# define NORTH_DEPTH		(10)
#endif

#ifndef SOUTH_DEPTH
# define SOUTH_DEPTH		(11)
#endif

#ifndef EAST_DEPTH
# define EAST_DEPTH		(12)
#endif

#ifndef WEST_DEPTH
# define WEST_DEPTH		(13)
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

t_list_depth				*solve_maze(t_map_depth *map,
						    t_amazing *amazing);
int				get_pos_x_depth(int x, int direction);
int				get_pos_y_depth(int y, int direction);
t_list_depth				*find_path(t_pile *visited,
						   int father_x,
						   int father_y,
					   t_pos end);

/*
** -- List --
*/

void				add_to_list(t_list_depth **list, int x, int y);
void				add_end_list(t_list_depth **list, int x, int y);
void				disp_list(t_list_depth *list);
void				add_end_pile(t_pile **p, t_pos pos,
					     int father_x, int father_y);
void				switch_list(t_pile **visited, t_pile **pile);
void				add_pile(t_pile **list, t_pos pos,
					 t_pos father, t_map_depth *map);
void				disp_pile(t_pile *pile);
int				already_in_pile(t_pile *pile, int x, int y);
void				add_end_save(t_pile **p, t_pos pos,
					     t_pile *pile,
					     t_map_depth *map);

/*
** -- Clean --
*/

void				clean_list(t_list_depth *list);
void				clean_pile(t_pile *pile);

/*
** -- Fill --
*/

void				fill_map(char **map, t_list_depth *list,
					 int *counter);
void				empty_map(char **map);

/*
** -- Args --
*/

int				print_usage();
int				check_args(int ac, char **av, bool *color,
					   bool *count);

#endif
