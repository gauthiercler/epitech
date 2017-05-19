/*
** adventure.h for adventure in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Sun Apr 17 18:01:06 2016 valentin montagne
** Last update Sun Apr 17 23:29:01 2016 Gauthier Cler
*/

#ifndef ADVENTURE_H_
# define ADVENTURE_H_

# include			<lapin.h>
# include			<stdbool.h>

# ifndef SUCCESS
#  define SUCCESS 		(0)
# endif /* !SUCCESS */

# ifndef ERROR
#  define ERROR 		(-1)
# endif /* !ERROR */

# ifndef NB_LEVELS
#  define NB_LEVELS		(2)
# endif /* !NB_LEVELS */

# ifndef NB_DECOR
#  define NB_DECOR		(3)
# endif /* !NB_DECOR */

/*
** -- Structures --
*/

typedef struct	s_adventure	t_adventure;
typedef struct	s_graph		t_graph;

typedef struct			s_position
{
  int				x;
  int				y;
}				t_position;

typedef struct			s_path
{
  int				nb_path;
  int				*path;
}				t_path;

typedef struct			s_graph
{
  t_position			pos;
  t_position			size;
  int				nb_links;
  int				*links;
}				t_graph;

typedef struct			s_interaction
{
  int				type;
  int				value;
}				t_interaction;

typedef struct			s_elem
{
  char				*name;
  t_position			pos;
  t_position			base_pos;
  t_position			hitbox;
  int				ratio;
  int				tick;
  t_interaction			interaction;
  bool				exists;
}				t_elem;

typedef struct			s_decor
{
  t_elem			*elems;
  t_elem			*dynamics;
}				t_decor;

typedef struct			s_room
{
  t_bunny_picture		*background;
  t_elem			*elems;
  t_graph			*graphs;
}				t_room;

typedef struct			s_level
{
  t_decor			decors[NB_DECOR];
  t_room			*rooms;
  int				selected;
}				t_level;

typedef struct			s_ressource
{
  char				*name;
  t_bunny_picture		*picture;
  t_position			size;
}				t_ressource;

typedef struct			s_sprite
{
  t_bunny_picture		*pix;
  int				size;
  int				nb_frame;
  double			current_frame;
}				t_sprite;

typedef struct			s_character
{
  t_sprite			stay_right;
  t_sprite			stay_left;
  t_sprite			move_right;
  t_sprite			move_left;
  int				ratio;
  bool				moving;
  bool				blocked;
  bool				moving_decor;
  int				delta;
  int				current;
  int				mode;
  t_position			position;
  t_position			save_pos;
  int				size_x;
  int				size_y;
  int				current_graph;
  bool				moving_graph;
  bool				in_graph;
  t_path			*graph;
}				t_character;

typedef struct			s_menu
{
  t_bunny_picture		*bg;
  t_bunny_picture		*play;
  t_bunny_picture		*exit;
  t_bunny_music			*music;
  bool				play_music;
}				t_menu;

typedef struct			s_adventure
{
  t_bunny_window		*window;
  t_bunny_picture		*back_button;
  t_bunny_picture		*node;
  t_bunny_pixelarray		*pix;
  t_menu			menu;
  t_ressource			*ressources;
  t_level			levels[NB_LEVELS];
  t_character			character;
  int				nb_levels;
  int				current_level;
  bool				endgame;
  int				main_pos;
}				t_adventure;

/*
** -- Prototypes --
*/

/*
** -- Loading --
*/

int				find_scope(t_bunny_ini *ini, char *what,
					   char **scopeb, int nb);
int				load_loop_d(t_elem *elems,
					    t_bunny_ini *ini,
					    char **names,
					    int nb);
int				load_elem(t_bunny_ini *ini, t_elem *elem,
					  char *scope);
int				load_levels(t_level *levels, char *filename);
int				load_decor(t_decor *decor, t_bunny_ini *ini,
					   char *scope);
int				load_level(t_level *level, t_bunny_ini *ini,
					   char *scope);
t_graph				*load_graph(t_bunny_ini *ini, char *scope);
t_room				*load_rooms(t_bunny_ini *ini, char *scope);
t_ressource			*load_ressources(char *filename);
int				load_character(t_character *character,
					       char *filename);
t_bunny_picture			*get_picture(t_ressource *ressources,
					     char *name);
int				load_menu(t_menu *menu);
int				check_env(char **ae);
void				fill_levels_hitboxes(t_adventure *adventure);

/*
** -- Drawing --
*/

int				draw_level(t_adventure *adventure,
					   t_level *level);
int				draw_decor(t_adventure *adventure,
					   t_decor *decor);
int				draw_character(t_adventure *adventure);
int				draw_room(t_adventure *adventure, t_room *room);
int				reverse(t_bunny_pixelarray *pix);

/*
** -- Events --
*/

t_bunny_response		handle_clicks(t_bunny_event_state state,
					      t_bunny_mousebutton mouse,
					      void *data);
t_bunny_response		handle_keys(t_bunny_event_state state,
					    t_bunny_keysym key, void *data);
t_bunny_response		click_menu(t_bunny_event_state state,
					   t_bunny_mousebutton mouse,
					   void *data);

int				calc_delta(t_character *character,
					   const t_bunny_position *pos);
int				find_hitboxes(t_adventure *adventure,
					      const t_bunny_position *pos);

/*
** -- Parallax --
*/

int				tick_level(t_adventure *adventure, int mode);
void				tick_decor(t_decor *decor, int mode);
void				tick_dynamics(t_decor *decors);
int				analyze_click(t_adventure *adventure,
					      const t_bunny_position *pos);
void				set_moving_character(t_adventure *adventure,
				     const t_bunny_position *pos);
void				move_character(t_adventure *adventure);
void				move_graph_character(t_adventure *adventure);
void				backup_pos(t_character *character);

/*
** -- Main Loop --
*/

t_bunny_response		main_loop(void *data);
int				menu_loop(t_adventure *adventure);
t_bunny_response		click_menu(t_bunny_event_state state,
					   t_bunny_mousebutton mouse,
					   void *data);

/*
** -- Graphs --
*/

void		graph(t_adventure *adventure, const t_bunny_position *pos);
t_path		*find_path(t_graph *graph, int origin, int destination);

/*
** -- Misc --
*/

void				*p_error(char *message);
void				tekblit(t_bunny_pixelarray	*destination,
					t_bunny_pixelarray	*origin,
					t_position		*pos);

void				pixel(t_bunny_pixelarray	*pix,
				      t_position		*pos,
				      t_color			*color);

int				str_len(char *str);
int				format(int fd, char *str, ...);
int				put_fd(int fd, char *string);
int				put_nb(int fd, int nb);
int				my_atoi(const char *str);
int				my_strcmp(char *s1, char *s2);
char				*my_strdup(const char *str);

/*
** -- Clean --
*/

int				clean_struct(t_adventure *adventure);
void				clean_menu(t_menu *menu);
void				clean_graph(t_graph *graph);

#endif /* !ADVENTURE */
