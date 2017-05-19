/*
** solver.h for solver in /home/gogo/rendu/dante/profondeur/include/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 22:41:51 2016 Gauthier Cler
** Last update Sun May  1 14:18:15 2016 Gauthier Cler
*/

#ifndef SOLVER_H_
# define SOLVER_H_

#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

typedef struct s_pile		t_pile;
typedef struct s_list		t_list;

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

struct				s_list
{
  int				x;
  int				y;
  t_list			*next;
};

typedef struct			s_map
{
  int				size_x;
  int				size_y;
  char				**array;
}				t_map;

typedef struct			s_solve
{
  t_map				map;
  t_list			*list;
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

#ifndef NORTH
# define NORTH			(10)
#endif

#ifndef SOUTH
# define SOUTH			(11)
#endif

#ifndef EAST
# define EAST			(12)
#endif

#ifndef WEST
# define WEST			(13)
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

t_list				*solve_maze(t_map *map);
int				get_pos_x(int x, int direction);
int				get_pos_y(int y, int direction);
t_list				*find_path(t_pile *visited, int father_x,
					   int father_y,
					   t_pos end);

/*
** -- List --
*/

void				add_to_list(t_list **list, int x, int y);
void				add_end_list(t_list **list, int x, int y);
void				disp_list(t_list *list);
void				add_end_pile(t_pile **p, t_pos pos,
					     int father_x, int father_y);
void				switch_list(t_pile **visited, t_pile **pile);
void				add_pile(t_pile **list, t_pos pos,
					 t_pos father, t_map *map);
void				disp_pile(t_pile *pile);
int				already_in_pile(t_pile *pile, int x, int y);
void				add_end_save(t_pile **p, t_pos pos,
					     t_pile *pile,
					     t_map *map);

/*
** -- Clean --
*/

void				clean_map(char **map);
void				clean_list(t_list *list);
void				clean_pile(t_pile *pile);

/*
** -- Fill --
*/

void				fill_map(char **map, t_list *list,
					 int *counter);
void				empty_map(char **map);

/*
** -- Args --
*/

int				print_usage();
int				check_args(int ac, char **av, bool *color,
					   bool *count);

#endif
