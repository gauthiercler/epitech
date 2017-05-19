/*
** tekgui.h for tekgui in /home/gogo/rendu/gfx_tekgui/include
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:17:07 2016 Gauthier Cler
** Last update Tue Mar  1 21:37:24 2016 Gauthier Cler
*/

#ifndef TEK_GUI_
# define TEK_GUI_

# include	<lapin/basic.h>
# include	<lapin/advanced.h>
# include	<dlfcn.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

typedef struct		s_tekgui
{
  char			*name;
  char			*type;
  char			*action;
  t_bunny_position	pos;
  t_bunny_position	size;
  char			*parent;
  t_color		color;
  t_bunny_pixelarray	*pix;
  t_bunny_position	text_pos[3];
  bool			text_on;
  t_color		txt_clr;
}			t_tekgui;

typedef struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_tekgui		*gui;
}			t_prog;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

void			*tekfunction(const char *funcname);

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png);

void			my_tektext(t_bunny_pixelarray *out,
				   const char *str,
				   t_bunny_pixelarray *font_png,
				   t_bunny_position *pos);

t_bunny_response	main_loop(void *data);

void			full_pix(t_bunny_pixelarray *pix,
				 unsigned int color);

t_bunny_pixelarray	*define_pix_size(int a);

t_bunny_pixelarray	*load_bitmap(char *file);

void			fill_bitmap(t_bunny_pixelarray *pix,
				    t_color *color,
				    int *pixel);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data);

int			get_color(t_bunny_pixelarray *pix,
				  t_bunny_position *pos);

void			put_char(t_bunny_pixelarray *pix,
				 t_bunny_position font_pos,
				 t_bunny_pixelarray *font_png,
				 t_bunny_position pos);

char			*my_strdup(const char *str);

int			my_strlen(char *str);

int			my_atoi(const char *str);

t_tekgui       		*tekgui_load(const char *file);

int			fill_tab(t_tekgui *tab, int i,
				 char *tmp, t_bunny_ini *ini);

void			tekgui_display(t_bunny_pixelarray *pix,
				       t_tekgui *gui);

int			my_strcmp(char *str, char *str2);

void			draw_form(t_bunny_pixelarray *pix,
				  t_tekgui elem);

void			blit_to_pix(t_bunny_pixelarray *pix,
				    t_tekgui elem);

int			check_alpha(t_bunny_pixelarray *pix);

void			draw_border(t_bunny_pixelarray *pix,
				    t_tekgui elem);

void			loop_x(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color *color,
			       int *info);

void			loop_y(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color *color,
			       int *info);

void			protection(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);

int			tekgui_init(t_prog *prog, char *ini, char *font);

int			tekgui_loop(t_prog *prog);

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton key,
			      void *data);

t_bunny_response	text(uint32_t unicode,
			     void *data);


void			fill_text_tab(t_tekgui *tab, int i);

int			action_cases(t_prog *prog, int i);

void			reset_text(t_prog *prog);

void			invert_color(t_prog *prog, int i);

int			my_strncmp(char *s1, char *s2, int count);

#endif
