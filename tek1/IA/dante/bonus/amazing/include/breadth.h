/*
** solver.h for solver in /home/gogo/rendu/dante/profondeur/include/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 22:41:51 2016 Gauthier Cler
** Last update Sat May 21 16:12:10 2016 Buyumad Anas
*/

#ifndef SOLVERB_H_
# define SOLVERB_H_

#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

typedef struct s_listb		t_listb;
typedef struct s_pileb		t_pileb;
typedef struct s_amazing	t_amazing;

struct				s_pileb
{
  int				x;
  int				y;
  t_pileb			*next;
  int				father_x;
  int				father_y;
};

typedef struct			s_posb
{
  int				x;
  int				y;
}				t_posb;

struct				s_listb
{
  int				x;
  int				y;
  t_listb			*next;
};

typedef struct			s_mapbreadth
{
  int				size_x;
  int				size_y;
  char				**array;
}				t_mapbreadth;

typedef struct			s_solve_breadth
{
  t_mapbreadth			map;
  t_listb			*list;
}				t_solve_breadth;

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

#ifndef WALL_BREADTH
# define WALL_BREADTH		'X'
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

#ifndef NORTH_BREADTH
# define NORTH_BREADTH		(10)
#endif

#ifndef SOUTH_BREADTH
# define SOUTH_BREADTH		(11)
#endif

#ifndef EAST_BREADTH
# define EAST_BREADTH		(12)
#endif

#ifndef WEST_BREADTH
# define WEST_BREADTH		(13)
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

t_listb				*solve_maze_b(t_amazing *amazing, t_mapbreadth *map);
int				get_pos_x_b(int x, int direction);
int				get_pos_y_b(int y, int direction);
t_listb				*find_pathb(t_pileb *visited,
					   int father_x, int father_y,
					   t_posb end);

/*
** -- List --
*/

void				add_to_listb(t_listb **list, int x, int y);
void				add_end_listb(t_listb **list, int x, int y);
void				add_end_pileb(t_pileb **p, t_posb pos,
					     int father_x, int father_y);
void				switch_listb(t_pileb **visited, t_pileb **pile);
void				add_pileb(t_pileb **list, t_posb pos,
					 int father_x, int father_y);
int				already_in_pileb(t_pileb *pile, int x, int y);
void				add_end_saveb(t_pileb **p, t_posb pos,
					     t_pileb *pile, t_mapbreadth *map);

/*
** -- Clean --
*/

void				clean_mapb(char **map);
void				clean_listb(t_listb *list);
void				clean_pileb(t_pileb *pile);

/*
** -- Fill --
*/

void				fill_mapb(char **map, t_listb *list,
					 int *counter);
void				empty_mapb(char **map);

/*
** -- Args --
*/

int				print_usage();
int				check_args(int ac, char **av, bool *color,
					   bool *count);

#endif
