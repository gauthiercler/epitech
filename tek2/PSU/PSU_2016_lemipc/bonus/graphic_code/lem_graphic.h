/*
** lem_graphic.h for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/bonus/includes/lem_graphic.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 30 21:43:50 2017 Anas Buyumad
** Last update Thu Mar 30 21:43:52 2017 Anas Buyumad
*/

#ifndef PSU_2016_LEMIPC_LEM_GRAPHIC_H
#define PSU_2016_LEMIPC_LEM_GRAPHIC_H

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH		(1080)
# endif /* SCREEN_WIDTH */

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT	(720)
# endif /* SCREEN_HEIGHT */

# ifndef SCREEN_BPP
#  define SCREEN_BPP		(32)
# endif /* SCREEN_WIDTH */

#include			<stdbool.h>
#include			<SDL2/SDL.h>
#include			<SDL2/SDL_image.h>

typedef struct s_ipc		t_ipc;
typedef struct s_pos		t_pos;

typedef struct s_graphic	t_graphic;
typedef struct s_frames		t_frames;
typedef struct s_color		t_color;
typedef struct s_team		t_team;

struct				s_team
{
  SDL_Surface			*id;
};

struct				s_color
{
  uint8_t			red;
  uint8_t			blue;
  uint8_t			green;
  uint8_t			alpha;
};

struct				s_frames
{
  SDL_Renderer			*screen;
  SDL_Surface			*title;
  SDL_Surface			*anas;
  SDL_Surface			*gauthier;
  SDL_Surface			*arena;
  SDL_Surface			*teams;
  SDL_Surface			*team;
  SDL_Surface			*wins;
};

struct				s_graphic
{
  SDL_Window			*window;
  t_frames			frames;
  t_color			palette[10];
  t_color			t_palette[1];
  t_team			teams[10];
};

void				startup_graphic(t_ipc *data);
void				close_graphic(t_ipc *data);
void				display_graphic(t_ipc *data);
void				display_winner(t_ipc *data);
void				init_graphic(t_graphic	*graphic);
void				load_ressources(t_graphic *graphic);
void				init_palette(t_color palette[10]);
void				init_palette_t(t_color palette[1]);
bool				draw_lemipc(t_graphic *graphic);
bool				draw_teams_t(t_graphic *graphic);
bool				draw_arena_t(t_graphic *graphic);
void				display_sdl_error(char *error);
bool				draw_authors(t_graphic *graphic);
bool				draw_titles(t_graphic *graphic);
bool				display_players(t_ipc *data);
bool				display_teams(t_ipc *data);
bool				draw_arena(t_ipc *data);
void				wait_end_event();
void				clear_screen(t_ipc *data);
void				draw_cell(t_ipc *data, char cell_content,
				      SDL_Rect *cell_outline,
				      SDL_Rect *cell_fill);

#endif /* !PSU_2016_LEMIPC_LEM_GRAPHIC_H */