/*
** solver.h for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/includes/solver.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:53:37 2017 Gauthier Cler
** Last update Tue Mar 28 15:53:37 2017 Gauthier Cler
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# include			<stdbool.h>
# include			<stdlib.h>
# include			<stdint.h>
# include			"lem_ipc.h"

typedef struct s_node		t_node;
typedef struct s_list		t_list;

struct				s_node
{
  t_pos				pos;
  t_pos				father;
  int				f;
  int				g;
  int				h;
  t_node			*next;
};

struct				s_list
{
  int				x;
  int				y;
  t_list			*next;
};

# ifndef SUCCESS
#  define SUCCESS		(0)
# endif

# ifndef ERROR
#  define ERROR			(1)
# endif

# ifndef VISITED
#  define VISITED		'o'
# endif

# ifndef POSSIBLE
#  define POSSIBLE		' '
# endif

# ifndef WAITING
#  define WAITING		'-'
# endif

# ifndef EXIT
#  define EXIT			'S'
# endif

# ifndef NORTH
#  define NORTH			(10)
# endif

# ifndef SOUTH
#  define SOUTH			(11)
# endif

# ifndef EAST
#  define EAST			(12)
# endif

# ifndef WEST
#  define WEST			(13)
# endif

void				*xmalloc(unsigned int size);
t_list				*path_finding(char  **map, t_pos *start_pos,
						  t_pos *target);
int				get_pos_x(int x, int direction);
int				get_pos_y(int y, int direction);
t_list				*find_path(t_node *open,
					   t_node *closed, t_node *selected);
int				heuristic(int pos_x, int pos_y);
void				add_node(t_node **node, t_node new);
void				add_to_list(t_list **list, int x, int y);
void				switch_list(t_node **close, t_node **open,
					    t_node *selected);
t_node				*get_node(t_node *node, t_node new);
t_node				*get_lower_node(t_node *open);
void				clean_node(t_node *list);
void				clean_list(t_list *list);
int				is_possible(t_node *open, char **map,
					    int direction, t_pos *pos);

#endif /* !SOLVER_H */