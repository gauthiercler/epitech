/*
** perfection.h for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/include/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:23:23 2016 Buyumad Anas
** Last update Sat May 21 19:16:43 2016 Buyumad Anas
*/

#ifndef PERFECTION_H_
# define PERFECTION_H_

#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

typedef struct			s_random
{
  uint32_t			alpha;
  uint32_t			beta;
  uint32_t			gamma;
  uint32_t			omega;
}				t_random;

extern				t_random xrandom;

/*
** -- Program --
*/

#ifndef SUCCESS
# define SUCCESS		(0)
#endif

#ifndef ERROR
# define ERROR			(1)
#endif

/*
** -- Start of the Maze --
*/

#ifndef START_X
# define START_X		(0)
#endif

#ifndef START_Y
# define START_Y		(0)
#endif

/*
** -- Type of Cells --
*/

#ifndef PATH
# define PATH			(1)
#endif

#ifndef WALL
# define WALL			(2)
#endif

#ifndef UNSET
# define UNSET			(3)
#endif

/*
** -- Colors Macro --
*/

# ifndef KRED
#  define KRED          ("\x1B[31m")
# endif /* !KRED */

# ifndef KGRN
#  define KGRN          ("\x1B[32m")
# endif /* !KGRN */

# ifndef KYEL
#  define KYEL          ("\x1B[33m")
# endif /* !KYEL */

# ifndef KMAG
#  define KMAG          ("\x1B[35m")
# endif /* !KMAG */

# ifndef KCYN
#  define KCYN          ("\x1B[36m")
# endif /* !KCYN */

# ifndef KRESET
#  define KRESET        ("\033[0m")
# endif /* !KRESET */

/*
** -- Type Neighbors --
*/

#ifndef IMP
# define IMP			(42)
#endif

#ifndef OUT
# define OUT			(21)
#endif

#ifndef NORTH
# define NORTH			(1)
#endif

#ifndef EAST
# define EAST			(2)
#endif

#ifndef SOUTH
# define SOUTH			(3)
#endif

#ifndef WEST
# define WEST			(4)
#endif

/*
** -- Type of Generation --
*/

#ifndef BACKTRACK
# define BACKTRACK		(0)
#endif

#ifndef PRIM
# define PRIM			(1)
#endif

/*
** -- Structures --
*/

/*
** -- Prototypes --
*/

typedef struct			s_list t_list;

typedef struct			s_map
{
  int				**cells;
  int				width;
  int				height;
}				t_map;

typedef struct			s_cell
{
  int				pos_x;
  int				pos_y;
}				t_cell;

typedef struct			s_list
{
  t_cell			cell;
  t_cell			link;
  t_list			*next;
}				t_list;

typedef struct			s_perfect
{
  t_list			*list;
  t_map				map;
  int				start_x;
  int				start_y;
  char				*filename;
  int				mode;
  int				type;
  int				debug;
}				t_perfect;

/*
** -- Usage --
*/

void				display_usage(void);
int				check_arguments(char **av);
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

/*
** -- Gen --
*/

void				gen_map(t_map *map);
void				gen_start(t_perfect *perfect);
int				generation_over(t_map *map);
t_list				*select_cell(t_list **list, int mode);
int				is_not_link(t_cell *link, t_cell *cell);
int				is_cell(t_list *list, t_cell *cell);
int				pick_neighbor(t_list *list, t_map *map,
					      t_list *cell);
int				check_directions(t_list *list, t_map *map,
						 t_list *cell, int direction);
int				check_surroundings(t_list *list, t_map *map,
						   t_list *cell, int direction);
void				assess_direction(t_perfect *perfect,
						 t_list *cell,
						 int direction);
int				check_sets(t_list *list, t_map *map,
					    t_list *cell, int direction);
int				correct_neighbors(t_perfect *perfect,
						  t_list *neighbor);
int				check_imperfect_walls(t_map *map,
						      t_list *cell,
						      int direction);
void				imperfection(t_perfect *perfect);

/*
** -- List --
*/

void				add_elem(t_list **list,
					 t_cell *cell, t_cell *link);
void				delete_elem(t_list **list, t_list *elem);
void				display_list(t_list *list);
int				get_pos_x(t_list *cell, int direction);
int				get_pos_y(t_list *cell, int direction);

/*
** -- Output --
*/

void				disp_map(t_map *map);
void				create_file(t_perfect *perfect);

/*
** -- Clean --
*/

void				clean_map(t_map *map);

#endif
