/*
** macro.h for macro in /home/gogo/rendu/gfx_raytracer2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu May 12 16:14:20 2016 Gauthier Cler
** Last update Sun May 22 19:24:36 2016 Gauthier Cler
*/

#ifndef _MACRO_H
# define _MACRO_H

/*
** - Program Configuration -
*/

# ifndef SUCCESS
#  define SUCCESS        	(0)
# endif

# ifndef ERROR
#  define ERROR          	(1)
# endif

/*
** - Loading complex OBJ -
*/

# ifndef V
#  define V              	(0)
# endif

# ifndef VN
#  define VN             	(1)
# endif

# ifndef VT
#  define VT             	(2)
# endif

# ifndef F
#  define F              	(3)
# endif

/*
** - get_next_line -
*/

# ifndef READ_SIZE
#  define READ_SIZE		(4096)
# endif

/*
** - Screen Configuration -
*/

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH		(1024)
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT		(768)
# endif

/*
** - Object Type -
*/

# ifndef NB_OBJ_TYPES
#  define NB_OBJ_TYPES		(5)
# endif

# ifndef SPHERE
#  define SPHERE		(0)
# endif

# ifndef CYLINDER
#  define CYLINDER		(1)
# endif

# ifndef CONE
#  define CONE			(2)
# endif

# ifndef PLANE
#  define PLANE			(3)
# endif

# ifndef POLYGON
#  define POLYGON		(4)
# endif

/*
** - Intersection -
*/

# ifndef IMPOSSIBLE
#  define IMPOSSIBLE		(-42.0)
# endif

/*
** - Threading -
*/

# ifndef NB_THREADS
#  define NB_THREADS		(4)
# endif

#endif /* _MACRO_H */
