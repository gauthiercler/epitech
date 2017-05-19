/*
** raytracer.h for raytracer in /home/gogo/rendu/gfx_raytracer1/include
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 29 10:02:11 2016 Gauthier Cler
** Last update Fri Mar 18 11:52:07 2016 Gauthier Cler
*/

#ifndef RAYTRACER1_
# define RAYTRACER1_

# include	<math.h>
# include	<stdlib.h>
# include	<lapin/basic.h>
# include	<lapin/advanced.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

#ifndef ERROR_
#define ERROR (1)
#endif

#ifndef SUCCESS_
#define SUCCESS (0)
#endif

typedef struct          s_atof
{
  double		decimal;
  double		res;
}			t_atof;

typedef struct		s_vec
{
  double		x;
  double		y;
  double		z;
}			t_vec;

typedef struct		s_object
{
  char			*name;
  int			type;
  t_vec			pos;
  double       		radius;
  t_color		color;
}			t_object;

typedef struct		s_target
{
  int			elem;
  double		distance;
}			t_target;

typedef struct		s_option
{
  bool			shadow;
  bool			plane;
  double		lum_coef;
  double       		size;
}			t_option;

typedef struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  int			x_div_2;
  int			y_div_2;
  t_object		*object;
  int			nb_objects;
  t_vec			eye_ori;
  t_vec			lum;
  t_vec			point;
  t_target		target;
  t_option		options;
  bool			shadow;
  bool			plane;
}			t_prog;

/*
** EVENTS
*/

t_bunny_response	main_loop(void *p);

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *data);
/*
** RENDER
*/

void	render(t_prog *prog);

void	render_line(t_prog *prog, int y);

/*
** RAYTRACER
*/

void	calc_ray(double x, double y, t_prog *prog);

void	ray_tracing(t_prog *prog, t_vec vec, double x, double y);

void	sphere_intersection(t_prog *prog, t_vec *vec, t_vec *eye_ori, int i);

void	plane_intersection(t_prog *prog,
			   t_vec *vec, t_vec *eye_ori, int i);

void	cylinder_intersection(t_prog *prog,
			      t_vec *vec, t_vec *eye_ori, int i);

#endif

/*
** INIT
*/

void		init_cos_sin(double *dcos, double *dsin);

void		init_sphere(t_object *object);

t_object	*load_ini(char *path, int *nb_objects);

int		load_infos(char *path, t_option *options, t_vec *eye_ori, t_vec *lum);

/*
** MISC
*/

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color *color);

void		full_pix(t_bunny_pixelarray *pix, unsigned int color);

int		my_atoi(const char *str);

double		my_atof(const char *str);

int		my_strlen(char *str);

char		*my_strdup(const char *str);

double		norme(t_vec *vec);

void		apply_norme(t_vec *vec, double norme);

double		to_rad(double angle);

unsigned int	damier(t_prog *prog, t_vec *vec);

unsigned int	get_coef(t_prog *prog, t_vec *vec, t_vec *res, double *coef);

void		prevent_overflow(double coef, t_color *color);
