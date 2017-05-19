/*
** point.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_02/point.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 10:53:51 2017 Antoine FORET
** Last update Sat Jan 07 10:53:51 2017 Antoine FORET
*/

#define			_GNU_SOURCE
#include		<stddef.h>
#include		<malloc.h>
#include		<stdio.h>
#include		"object.h"

typedef			struct
{
  Class			base;
  int			x;
  int			y;
  char			*str_representation;
} PointClass;

/**
 * Initialize self instance with parameters from list
 *
 * @param self
 * @param list
 */
static void		Point_ctor(Object *self, va_list *list)
{
  ((PointClass *)self)->x = va_arg(list, int);
  ((PointClass *)self)->y = va_arg(list, int);
}

/**
 * Clean self instance
 *
 * @param self
 */
static void		Point_dtor(Object* self)
{
  if (self != NULL && ((PointClass *)self)->str_representation != NULL)
  {
    free(((PointClass *)self)->str_representation);
  }
}

/**
 * Convert self instance into string
 *
 * @param self
 * @return
 */
static char const	*Point_toString(Object* self)
{
  PointClass		*that;

  if (self == NULL)
    return (NULL);
  that = ((PointClass *)self);
  if (that->str_representation != NULL)
    free(that->str_representation);
  asprintf(&that->str_representation, "<%s (%d, %d)>", that->base.__name__, that->x, that->y);
  return (that->str_representation);
}

static PointClass	_description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_toString},
  0, 0, NULL
};

Class* Point = (Class*) &_description;
