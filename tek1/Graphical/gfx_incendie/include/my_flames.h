/*
** my_flames.h for my_flames in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Sat Dec  5 23:49:29 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:07:01 2015 Sylvain Chaugny
*/

#include		<lapin.h>

typedef struct		 s_prog
{
  int			plus;
  int			height;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  unsigned int		col;
  t_bunny_music		*psit;
  t_bunny_music		*music;
} t_prog;

typedef struct		s_datas
{
  t_bunny_position	pos[2];
  t_color		col[2];
  int			height;
  int			k;
} t_datas;

void				tekline(t_bunny_pixelarray *,
				t_bunny_position *,
				unsigned int);
void				tekpixel(t_bunny_pixelarray *,
				t_bunny_position *,
				 t_color);
t_bunny_response		key(t_bunny_event_state state,
				    t_bunny_keysym	key,
				    void                *data);
void				fill_black(t_bunny_pixelarray	 *pix);
void				draw_line(t_bunny_pixelarray	*pix,
					  t_datas		*datas,
					  int			arg);
void				init_datas(t_datas *datas, int i, int height, int plus);
void				go_to_next_part(t_datas *datas, int i, int height, int plus);
int				check_k();
int				fire(t_bunny_pixelarray *pix, int height, int plus);
t_bunny_response		click(t_bunny_event_state	state,
				      t_bunny_mousebutton	mouse,
				      void			*data);
t_bunny_response		main_loop(void *p);
void				load_musics(t_prog *prog);
