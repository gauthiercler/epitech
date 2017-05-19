/*
** tekpaint.h for tekpaint in /home/gauthier/rendu/gfx_tekpaint/include
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan  5 16:13:48 2016 Gauthier Cler
** Last update Tue Jan 26 21:28:07 2016 Gauthier Cler
*/

#ifndef TEKPAINT_H_
# define TEKPAINT_H_

#include	<math.h>
#include	<stdlib.h>
#include	<lapin.h>
#include	<lapin_enum.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#define ERROR (1)
#define SUCCESS (0)

typedef struct		s_palet
{
  bool			pinceau_r;
  bool			pinceau_c;
  bool			pipette;
  bool			circle;
  bool			line;
  double       		size;
  int			nb_clic;
} t_palet;

typedef struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*p_palet;
  int			state;
  t_palet		palet;
  t_color		color[2];
} t_prog;

t_bunny_pixelarray	*load_bitmap(char *file);

void			bitmap_to_pix(t_bunny_pixelarray *pix,
				      int a,
				      int	size);

t_bunny_pixelarray	*define_pix_size(int a);

void			fill_bitmap(t_bunny_pixelarray *pix,
				    unsigned int	*stock,
				    int			*pixel);

void			grey_filter(t_bunny_pixelarray *pix);

void			sepia_filter(t_bunny_pixelarray *pix);

void			inverse_filter(t_bunny_pixelarray *pix);

void			negative_filter(t_bunny_pixelarray *pix);

void			flou_filter(t_bunny_pixelarray *pix);

void			pixel_filter(t_bunny_pixelarray *pix);

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);

void			protection(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data);

t_bunny_response	main_loop(void *p);

int			my_atoi(unsigned char *str);

int			my_strlen(char *str);

int			pix_to_cactus(t_bunny_pixelarray *pix,
				      char *name);

void			decimal_to_base(int decimal, char *base);

void			size_to_char(char *tab, int size);

t_bunny_pixelarray	*define_pix_cactus(int a);

t_bunny_pixelarray	*load_cactus(char *file);

void			cactus_to_pix(t_bunny_pixelarray	*pix,
				      int			a,
				      unsigned int		width,
				      unsigned int		height);

int			cactus_to_decimal(char *buf);

int			my_strcmp(unsigned char *s1, char *s2);

int			my_strcmp_ae(char *s1, char *s2);

void			pinceau(t_prog	*prog);

void			init_palet(t_prog *prog);

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

void			tekcircle(t_bunny_pixelarray *pix,
				  const t_bunny_position *pos,
				  double i,
				  t_color *color);

void			tekcircle_pen(t_bunny_pixelarray *pix,
				  const t_bunny_position *pos,
				  double i,
				  t_color *color);

void			teksquare(t_bunny_pixelarray *pix,
				  const t_bunny_position *pos,
				  t_color *color,
				  int i);

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton key,
			      void *data);

void			teksquare_line(t_bunny_pixelarray *pix,
				       t_bunny_position *pos,
				       t_color *color);

void			compl_x(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color,
				int *coef);

void			compl_y(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color,
				int *coef);

void			set_all_false(t_prog *prog);

int			circle(t_prog *prog,
			       t_bunny_event_state state,
			       t_bunny_mousebutton key);

int			line(t_prog *prog,
			     t_bunny_event_state state,
			     t_bunny_mousebutton key);

void			full_pix(t_bunny_pixelarray *pix,
				 t_color *color);

int			get_color(t_bunny_pixelarray *pix,
				  const t_bunny_position *pos);

t_bunny_response	loop_win2(void *p);

t_bunny_response	click2(t_bunny_event_state state,
			       t_bunny_mousebutton mouse,
			       void *data);

int			fill_loop(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  int color_old,
				  t_color *new_color);

void			set_bmp_false(t_prog *prog);

char			*my_strcat(char *str1, char *str2);

void			selec(const t_bunny_position	*pos,
			       t_prog			*prog);

void			selec2(const t_bunny_position	*pos,
			       t_prog			*prog);

void			selec3(const t_bunny_position	*pos,
			       t_prog			*prog);

void			selec4(const t_bunny_position	*pos,
			       t_prog			*prog);

void			my_putstr(char *str);

int			check_arg(t_prog *prog, char *str);

t_bunny_pixelarray	*load_white();

int			myabs(int nb);

void			cactus_header(t_bunny_pixelarray	*pix,
				      int			a,
				      char			*size);

int			check_env(char **ae);

int			init_loop(t_prog prog);

#endif
