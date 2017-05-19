/*
** bmp.h for bmp in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:10:48 2016 Gauthier Cler
** Last update Wed Apr 20 21:17:17 2016 Gauthier Cler
*/

#ifndef	_BMP_H_
# define _BMP_H_

#ifndef SUCCESS
# define SUCCESS	(0)
#endif

#ifndef ERROR
# define ERROR		(-1)
#endif

#include		<lapin.h>

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*window;
}			t_data;

typedef struct		s_bmp
{
  char			signature[2];
  int			size;
  int			pixels_offset;
  int			header_size;
  int			width;
  int			height;
  int			planes_amount;
  int			bpp;
  int			compression;
  int			image_size;
  int			colors_amount;
  int			colors_imp;
  t_color		*pixels;
  int			position;
  char			data_buffer[4];
}			t_bmp;

/*
** Loading.
*/

t_bunny_pixelarray	*load_bmp(char *path);
t_bunny_pixelarray	*load_error(t_bmp *bmp, int fd);

/*
** Generation.
*/

t_bmp			*generate_bmp();

/*
** Deletion.
*/

void			delete_bmp(t_bmp *bmp);

/*
** Checking.
*/

int			check_header(t_bmp *bmp);

/*
** Reading.
*/

int			read_header(t_bmp *bmp, int fd);
int			read_data(t_bmp *bmp, int fd);
int			read_current_byte(t_bmp *bmp, int fd);
void			assign_current_byte(t_bmp *bmp, int fd);
int			skip_x_bytes(int fd, int x);

/*
** Transposition.
*/

t_bunny_pixelarray	*transposition(t_bmp *bmp);

/*
** Misc
*/

int			format(int fd, char *str, ...);
int			str_len(char *str);
int			put_fd(int fd, char *str);
int			put_nb(int fd, int nb);

#endif /*_BMP_H */
