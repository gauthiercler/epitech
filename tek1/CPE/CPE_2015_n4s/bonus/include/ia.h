/*
** ia.h for ia in /home/gogo/rendu/CPE_2015_n4s/include/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:03:24 2016 Gauthier Cler
** Last update Fri May 27 01:18:33 2016 Gauthier Cler
*/

#ifndef IA_H_
# define IA_H_

# include			<stdbool.h>
# include			<lapin.h>

# ifndef SUCCESS
#  define SUCCESS		(0)
# endif

# ifndef ERROR
#  define ERROR			(1)
# endif

# ifndef READ_SIZE
#  define READ_SIZE		(4096)
# endif

# ifndef NB_RAYS
#  define NB_RAYS		(32)
# endif

# ifndef NB_SPREAD
#  define NB_SPREAD		(8)
# endif

# ifndef INT
#  define INT			(1)
#  endif

# ifndef FLOAT
#  define FLOAT			(2)
#  endif

# ifndef NO_MODE
#  define NO_MODE		(3)
#  endif

typedef struct			s_raycast
{
  t_bunny_pixelarray		*pix;
  t_bunny_window		*win;
}				t_raycast;

typedef struct			s_data
{
  char				*answer;
  char				**answer_tab;
  float				rays[NB_RAYS];
  float				spread[NB_SPREAD];
  float				car_speed;
  float				turn_angle;
  int				previous_spread;
  float				previous_speed;
  float				previous_angle;
}				t_data;

/*
** Bunny
*/

void				tekline(t_bunny_pixelarray *pix,
					t_bunny_position *pos,
					unsigned int *color);
void				disp_line(t_raycast *ray,
				  int x,
				  float size);
void				tekpixel(t_bunny_pixelarray	*pix,
					 t_bunny_position	*pos,
					 unsigned int		color);
void				draw_fps(t_raycast *ray, t_data *data);

/*
** Misc
*/

int				format(int fd, char *str, ...);
char				*get_next_line(const int fd);
int				my_atoi(char *str);
int				str_len(char *str);
int				put_nb(int fd, int nb);
int				put_fd(int fd, char *str);
int				my_strcmp(char *s1, char *s2);
int				my_strncmp(char *s1, char *s2, int nb);
float				my_atof(char *string);
int				put_float(int fd, float number, int nb);
void				free_array(char **array);

/*
** - Explode -
*/

int				purge_count(char *string);
int				explode_count(char *string, char delimiter);
void				skip_purge(char *string, int *index);
void				skip_explode(char *string, int *index,
					     char delimiter);
void				copy_substring(char *str, char *dest,
					       int index, int length);
bool				purge_strings(char **strings, char *string,
					      int count);
bool				explode_strings(char **strings, char *string,
						int count,
						char delimiter);
char				**explode(char *string, char delimiter);

/*
** - Treatment -
*/

int				call_instruction(t_data *data,
						 char *instruction,
						 float value, int mode);

/*
** - Rays -
*/

int				assess_rays(float *rays, char **answer_tab);
int				get_bigger_ray(float *rays);
void				assess_spread(float *spread, float *rays);
int				get_main_spread(float *spread);

/*
** - Computation -
*/

int				compute_output(t_data *data);
void				compute_distance(float distance, float *speed,
						 float previous_speed);
void				compute_wheels_angle(t_data *data,
						     int main_spread);

/*
** - Wheels -
*/

float				get_wheels_angle(t_data *data);
int				shift_wheels(t_data *data);

#endif				/* !IA_H_ */
