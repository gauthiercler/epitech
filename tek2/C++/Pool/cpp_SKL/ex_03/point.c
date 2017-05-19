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
#include		<string.h>
#include		"object.h"
#include		"raise.h"
#include		"new.h"
#include		"point.h"

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

/**
 * Compute sum of two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Point_add(const Object* self, const Object* other)
{
  const PointClass	*that;
  const PointClass	*otherPoint;
  int			x;
  int			y;

  that = self;
  otherPoint = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherPoint->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherPoint->base.__name__) != 0)
    raise("Tried to add two different Class");
  x = that->x + otherPoint->x;
  y = that->y + otherPoint->y;
  return (new(Point, x, y));
}

/**
 * Compute difference between two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Point_sub(const Object *self, const Object *other)
{
  const PointClass	*that;
  const PointClass	*otherPoint;
  int			x;
  int			y;

  that = self;
  otherPoint = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherPoint->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherPoint->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  x = that->x - otherPoint->x;
  y = that->y - otherPoint->y;
  return (new(Point, x, y));
}

static PointClass	_description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_toString, &Point_add, &Point_sub},
  0, 0, NULL
};

Class* Point = (Class*) &_description;
