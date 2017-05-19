/*
** raytracer.h for raytracer in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Fri May 20 16:43:36 2016 montag_v
** Last update Sun May 22 18:08:55 2016 Buyumad Anas
*/

#ifndef RAYTRACER
# define RAYTRACER

#include		<math.h>
#include		<lapin.h>
#include		<stdio.h>
#include		<pthread.h>
#include		"macro.h"

typedef struct          s_raytracer t_raytracer;

typedef struct		s_position
{
  float			x;
  float			y;
  float			z;
}			t_position;

typedef struct		s_list
{
  char			**tab;
  struct s_list		*next;
}			t_list;

typedef struct		s_eye
{
  t_position		origin;
  t_position		inclinaison;
  int			blur_level;
}			t_eye;

typedef struct		s_lux
{

  int			type;
  t_position		origin;
  t_position		att;
  float			intensity;
}			t_lux;

typedef struct		s_vector_data
{
  int			count[4];
  t_position		*vector;
  t_position		*vectort;
  t_position		*vectorn;
}			t_vector_data;

typedef struct		s_mtl
{
  char			*name;
  t_color		color;
}			t_mtl;

typedef struct		s_triangle
{
  int			index_color;
  t_position		vector[3];
  t_position		vectort[3];
  t_position		vectorn[3];
}			t_triangle;

typedef struct		s_texture
{
  t_bunny_pixelarray	*texture;
  char			*name;
  int			size_x;
  int			size_y;
}			t_texture;

typedef struct		s_infos
{
  int			nb_triangle;
  t_triangle		*triangle;
  t_color		color;
  char			*texture;
  t_position		inclinaison;
  t_position		normal;
  float			angle;
  float			height;
  float			radius;
  float			center_y;
  bool			cylinder_top;
}			t_infos;

typedef struct		s_object
{
  int			type;
  t_position		origin;
  t_infos		infos;
}			t_object;

typedef struct		s_shadow_info
{
  bool			obstructed;
  float			coeff;
  float			distance;
  float			light_distance;
}			t_shadow_info;

typedef struct		s_light_info
{
  float			coeff;
}			t_light_info;

typedef struct		s_data
{
  t_position		origin;
  t_position		target;
  t_position		vector;
  t_position		s_origin;
  t_position		s_vector;
  float			coeff;
  int			index;
  int			polygon_index;
  t_position		hitpoint;
  t_color		hit_color;
  float			shadow_coeff;
  float			light_coeff;
  bool			obstructed;
  t_shadow_info		*shadow_infos;
  t_light_info		*light_infos;
  t_bunny_position	thread_area[2];
  pthread_t		thread;
}			t_data;

struct         		 s_raytracer
{
  int			index;
  int			nb_lux;
  int			nb_obj;
  t_eye			eye;
  t_lux			*lux;
  t_mtl			*mtl;
  t_texture		*texture;
  t_object		*object;
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  void			(* compute[5])(t_data *data, t_infos *info, int index);
  void			(* a_texture[5])(t_data *data, t_object *obj,
			 t_bunny_pixelarray *pix, t_bunny_position *pos);
};

typedef struct		s_thread_arg
{
  t_data		thread;
  t_raytracer		data;
}			t_thread_arg;

typedef struct		s_bmp
{
  unsigned short int	type;
  unsigned int		size;
  unsigned int		reserved;
  unsigned int 		offset;
  unsigned int		header_size;
  int			width;
  int			height;
  unsigned short int	planes;
  unsigned short int	bits;
  unsigned int		compression;
  unsigned int		imagesize;
  int			xresolution;
  int			yresolution;
  unsigned int		ncolours;
  unsigned int		importantcolours;
}			t_bmp;

extern float		xcos[360];
extern float		xsin[360];

/*
** - Miscellaneous -
*/

void			freetab(char **tab);
char			**my_wordtab(char *str, char separator);
int			my_strncmp(char *s1, char *s2, int nb);
int			my_strcmp(char *s1, char *s2);
int			add_liste(t_list **p, char **tab);
char			**my_str_to_wordtab(char *);
void			disp_liste(t_list *p);
char			*get_next_line(const int fd);
int			str_len(char *string);
int			my_atoi(const char *str);
float			my_atof(const char *str);
int			put_fd(int fd, char *string);
int			put_nb(int fd, int nb);
int			format(int fd, char *str, ...);
char			*my_strdup(const char *str);
void			full_pix(t_bunny_pixelarray *pix,
				 unsigned int color);
void			pixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
			      t_color *color);
unsigned int		get_color(t_bunny_pixelarray *pix, int x, int y);
t_bunny_pixelarray	*get_pix(char *name, t_texture *textures,
				 t_bunny_position *size);

/*
** -Loading -
*/

void			init_obj(t_object *obj);
int			init_data(t_vector_data *, t_object *);
int			find_scope(t_bunny_ini *ini,
				   char **scope,
				   char *origin,
				   int nb);
int			loop_lux(t_bunny_ini *ini,
				 t_lux **lux,
				 int nb_lux);
int			load_lux(t_bunny_ini *ini,
				 char *scope,
				 t_lux *lux);
int			load_obj(t_bunny_ini *ini,
				 char *scope,
				 t_raytracer *ray,
				 t_object *obj);
int			load_complex_obj(t_bunny_ini *ini,
					 char *scope,
					 t_raytracer *ray,
					 t_object *obj);
void			load_faces(t_object *obj,
				   t_raytracer *ray,
				   t_vector_data *data,
				   t_list *list);
void			load_eye(t_bunny_ini *ini,
				 t_eye *eye);
int			loop_obj(t_bunny_ini *ini,
				 t_raytracer *ray,
				 t_object **obj,
				 int nb_obj);
int			load_texture(t_bunny_ini *ini, t_texture **texture);
int			load_ini(t_raytracer *raytracer,
				 char *filename);
void			load_coord(t_bunny_ini *ini,
				   char *scope,
				   char *name,
				   t_position *coord);
void			load_color(t_bunny_ini *ini,
				   char *scope,
				   t_color *color);
int			load_mtl(t_raytracer *ray, char *filename);
void			load_tab_funct(t_raytracer *data);
void			init_trigo();
int			get_angle(int angle);

/*
** - Events -
*/

t_bunny_response	handle_keys(t_bunny_event_state state,
				    t_bunny_keysym      key,
				    void                *data);

/*
** - Screen Renderer -
*/

int			render_screen(t_raytracer *raytracer);
int			render_target(t_raytracer *raytracer, t_data *data);
void			render_pixel(t_raytracer *raytracer, t_data *data);

/*
** - Intersection -
*/

int			compute_intersection(t_raytracer *raytracer,
					     t_data *data);
void			compute_ray(t_position *origin, t_position *target,
				    t_position *vector);
void			compute_space_ray(t_position *origin,
					  t_position *target,
					  t_position *vector);
float			get_root(float a, float b, float c);
float			get_simple_root(float a, float b);
void			sphere(t_data *data, t_infos *info, int index);
void			plane(t_data *data, t_infos *info, int index);
void			cylinder(t_data *data, t_infos *info, int index);
void			cone(t_data *data, t_infos *info, int index);
void			polygon(t_data *data, t_infos *info, int index);
int			hit_is_in_range(float coeff, t_data *data,
					float center, float height);

/*
** - Shadow -
*/

void			configure_hitpoint(t_data *data);
int			compute_shadow(t_raytracer *raytracer, t_data *data);
void			compute_color(t_data *data);

/*
** - Light -
*/

int			compute_light(t_raytracer *raytracer, t_data *data,
				      t_object *object);

/*
** - Matrices -
*/

void			rotate_x(t_position *point, float angle);
void			rotate_y(t_position *point, float angle);
void			rotate_z(t_position *point, float angle);
void			rotate_inverse(t_position *point,
				       t_position *inclinaison);
void			init_x(float *matrix, int angle);
void			init_y(float *matrix, int angle);
void			init_z(float *matrix, int angle);
void			mult_matrix_y(float *matrix, int angle);
void			mult_matrix_z(float *matrix, int angle);

/*
** - Threading -
*/

void			init_threads(t_data *threads, t_eye *eye);
int			start_threads(t_data *threads, t_raytracer *raytracer);
void			aa_ray_compute(t_data *thread, int x, int y);
void			set_final_color(int *colors, t_color *final_color,
					int level);

/*
** - Deletion -
*/

void			delete_raytracer(t_raytracer *raytracer);
void			delete_list(t_list *list);

/*
** Saving
*/

int			save_to_file(t_bunny_pixelarray *pix);

/*
** Anti-aliasing
*/

void			set_final_color(int *colors, t_color *final_color,
					int level);
void			blur_ray_compute(t_data *thread, int x, int y);

/*
** Texture
*/

void			texturing(t_data *data, t_object *obj,
				  t_bunny_pixelarray *pix,
				  t_bunny_position *pos);
void			texture_surface(t_data *data, t_object *obj,
					t_texture *textures,
					t_raytracer *raytracer);
void			get_normal_texture(t_data *data, t_object *obj);
void			plane_texture(t_data *data, t_object *obj,
				      t_bunny_pixelarray *pix,
				      t_bunny_position *size);
void			sphere_texture(t_data *data, t_object *obj,
				       t_bunny_pixelarray *pix,
				       t_bunny_position *size);
void			cylinder_texture(t_data *data, t_object *obj,
					 t_bunny_pixelarray *pix,
					 t_bunny_position *size);
void			cone_texture(t_data *data, t_object *obj,
				     t_bunny_pixelarray *pix,
				     t_bunny_position *size);
void			polygon_texture(t_data *data, t_object *obj,
					t_bunny_pixelarray *pix,
					t_bunny_position *size);
#endif
