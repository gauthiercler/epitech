/*
** megalovania.h for megalovania in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 20 18:20:17 2016 Anas Buyumad
** Last update Tue Mar 22 11:45:17 2016 Gauthier Cler
*/

#ifndef MEGALOVANIA_H_
# define MEGALOVANIA_H_

#ifndef	SUCCESS
# define SUCCESS (0)
#endif /* !SUCCESS */

#ifndef ERROR
# define ERROR (1)
#endif /* SUCCESS */

#include	<lapin/basic.h>
#include	<lapin/advanced.h>
#include	<math.h>
#include	<time.h>
#include	<unistd.h>

typedef struct	s_midi
{
  double	pitch;
  int		length;
}		t_midi;

typedef struct		s_star
{
  t_bunny_position	pos;
  int			type;
  double		speed;
  t_color		color;
}			t_star;

typedef struct		s_planet
{
  t_bunny_pixelarray	*planet;
  double		pos_x;
  double		pos_y;
  double		dim;
  double		speed;
}			t_planet;

typedef struct		s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*ship[4];
  t_bunny_pixelarray	*peanut[8];
  t_bunny_pixelarray	*sans;
  double		ship_pos_x;
  double		ship_pos_y;
  int			ship_mode;
  t_planet		planets[4];
  t_star		stars[20];
  t_bunny_music		*music;
  int			ondulation;
  t_bunny_position	sin_pos;
  bool			peanut_active;
  t_bunny_position	peanut_pos;
  double		sin_circle;
  int			loading_progress;
  t_bunny_effect	*music_load;
  t_midi		*midi;
}			t_data;

int			initialize();
t_bunny_response	loop(void *data);
t_bunny_response	key_handle(t_bunny_event_state state,
				   t_bunny_keysym key, void *d);
void			fill(t_bunny_pixelarray *pix, unsigned int color);
void			pixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  t_color *color);
void			line(t_bunny_pixelarray *pix,
				 t_bunny_position *pos, t_color *color);
void			draw_star(t_bunny_pixelarray *pix, t_star *star);
void			draw_square(t_bunny_pixelarray *pix,
					t_bunny_position *pos, double size,
					unsigned int color);
void                    tektext(t_bunny_pixelarray *pix,
                                const char *str,
                                t_bunny_pixelarray *font_png,
                                t_bunny_position *pos);

void                    put_char(t_bunny_pixelarray *pix,
                                 t_bunny_position  font_pos,
                                 t_bunny_pixelarray *font_png,
                                 t_bunny_position pos);

int			get_color(t_bunny_pixelarray *pix,
				  t_bunny_position *pos);
void			gen_stars(t_data *data);
void			draw_planets(t_data *data);
void			draw_sprite(t_data *data);
void			draw_peanut(t_data *data);
int			load_jelly(t_data *data);
int			load_ship(t_data *data);
void			load_sprite_attribute(t_data *data);
t_bunny_response	loading_loop(void *d);
void			draw_names(t_data *data);
t_midi                  *load_ini(char *path);
int                     play_song(t_bunny_effect *music, t_midi *midi);
void			burn(t_data *data);
void			big_loop(t_data *data);
void			draw_sans(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *sans);
void			load_sans(t_data *data);

#endif /* !MEGALOVANIA_H_ */
