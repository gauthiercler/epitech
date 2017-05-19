/*
** amazing.h for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/include/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 11:57:32 2016 Buyumad Anas
** Last update Sun May 22 17:08:53 2016 Buyumad Anas
*/

#ifndef AMAZING_H_
# define AMAZING_H_

#include			"SDL/SDL.h"
#include			"SDL/SDL_image.h"
#include			"perfection.h"
#include			"solver.h"
#include			"breadth.h"
#include			"astar.h"
#include			<unistd.h>
#include			<stdbool.h>
#include			<stdlib.h>
#include			<stdint.h>

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
** -- Screen Configuration --
*/

#ifndef SCREEN_WIDTH
# define SCREEN_WIDTH		(1024)
#endif

#ifndef SCREEN_HEIGHT
# define SCREEN_HEIGHT		(548)
#endif

#ifndef SCREEN_BPP
# define SCREEN_BPP		(32)
#endif

/*
** -- Display Configuration --
*/

#ifndef NB_BUTTONS
# define NB_BUTTONS		(11)
#endif

#ifndef WHITE
# define WHITE			(0)
#endif

#ifndef BLACK
# define BLACK			(1)
#endif

#ifndef GREY
# define GREY			(2)
#endif

#ifndef BLUE
# define BLUE			(3)
#endif

#ifndef RED
# define RED			(4)
#endif

#ifndef YELLOW
# define YELLOW			(5)
#endif

#ifndef GREEN
# define GREEN			(6)
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

typedef struct			s_position
{
  int				x;
  int				y;
}				t_position;

typedef struct			s_button
{
  char				*name;
  SDL_Rect			hitbox;
  SDL_Surface			*button_normal;
  SDL_Surface			*button_hover;
  SDL_Surface			*button_selected;
  int				state;
  int				type;
}				t_button;

typedef struct			s_amazing
{
  t_perfect			perfect;
  t_solve			solver;
  t_solve_breadth		solver_breadth;
  t_solvea			solve_astar;
  int				speed;
  int				width;
  int				height;
  int				gen_mode;
  int				gen_type;
  bool				generated;
  int				solver_type;
  char				*filename;
  SDL_Surface			*Screen;
  SDL_Surface			*Background;
  SDL_Surface			*Credits;
  SDL_Surface			*Generator;
  SDL_Surface			*Solver;
  SDL_Surface			*Type;
  SDL_Surface			*Size;
  SDL_Surface			*WxH;
  SDL_Surface			*Map;
  SDL_Event			events;
  t_button			buttons[NB_BUTTONS];
  bool				w_active;
}				t_amazing;

/*
** -- Prototypes --
*/

/*
** -- Start Up --
*/

void				start_up(void);

/*
** -- Loading --
*/

SDL_Surface			*load_image(char *filename);
void				load_ressources(t_amazing *amazing);
void				load_buttons(t_button buttons[NB_BUTTONS]);
void				load_action_buttons(t_button buttons[NB_BUTTONS]);
void				kill_data(t_amazing *amazing);

/*
** -- Manipulation --
*/

void				blit(SDL_Surface *dest, SDL_Surface *src,
				     t_position *pos);

/*
** -- Drawing --
*/

void				draw_amazing(t_amazing *amazing);
void				draw_buttons(t_amazing *amazing,
					     t_button buttons[NB_BUTTONS]);
void				draw_maze(t_amazing *amazing);
void				draw_maze_depth(t_amazing *amazing);
void				draw_maze_breadth(t_amazing *amazing);
void				draw_maze_star(t_amazing *amazing);
void				init_blit_maze(t_amazing *amazing, int *pos_y,
					       int *pos_x, int *row);
void				set_cell_color(SDL_Color *color,
					       t_position *pos, int type,
					       int ratio);
void				draw_empty_maze(t_amazing *amazing);
void				set_pixel(SDL_Surface *image, t_position *pos,
					  SDL_Color *color);
void				set_color(SDL_Color *color, int macro);
/*
** -- Events --
*/

void				handle_events(t_amazing *amazing);
int				check_hitboxes(t_amazing *amazing, t_position *mouse_pos);
void				set_buttons_state(t_amazing *amazing, int index, int mode);
void				click_actions(t_amazing *amazing, int index);
void				generate(t_amazing *amazing);
void				solve(t_amazing *amazing);

int				perfection(t_amazing *amazing);
int				solver(t_amazing *amazing);
int				solver_b(t_amazing *amazing);
int				solvera(t_amazing *amazing);

#endif
