/*
** vertex.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_02/vertex.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 11:10:21 2017 Antoine FORET
** Last update Sat Jan 07 11:10:21 2017 Antoine FORET
*/

#define			_GNU_SOURCE
#include		<stdio.h>
#include		<stddef.h>
#include		<stdlib.h>
#include		<string.h>
#include		"object.h"
#include		"new.h"
#include		"vertex.h"
#include		"raise.h"

typedef			struct
{
  Class			base;
  int			x;
  int			y;
  int			z;
  char			*str_representation;
} VertexClass;

/**
 * Initialize self instance with parameters from list
 *
 * @param self
 * @param list
 */
static void		Vertex_ctor(Object *self, va_list *list)
{
  ((VertexClass *)self)->x = va_arg(list, int);
  ((VertexClass *)self)->y = va_arg(list, int);
  ((VertexClass *)self)->z = va_arg(list, int);
}

/**
 * Clean self instance
 *
 * @param self
 */
static void		Vertex_dtor(Object* self)
{
  if (self == NULL || ((VertexClass *)self)->str_representation)
  {
    free(((VertexClass *)self)->str_representation);
  }
  (void)self;
}

/**
 * Convert self instance into string
 *
 * @param self
 * @return
 */
static char const 	*Vertex_toString(Object* self)
{
  VertexClass		*that;

  if (self == NULL)
    return (NULL);
  that = ((VertexClass *)self);
  if (that->str_representation != NULL)
    free(that->str_representation);
  asprintf(&that->str_representation, "<%s (%d, %d, %d)>", that->base.__name__, that->x, that->y, that->z);
  return (that->str_representation);
}

/**
 * Compute sum of two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Vertex_add(const Object* self, const Object* other)
{
  const VertexClass	*that;
  const VertexClass	*otherVertex;
  int			x;
  int			y;
  int			z;

  that = self;
  otherVertex = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherVertex->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherVertex->base.__name__) != 0)
    raise("Tried to add two different Class");
  x = that->x + otherVertex->x;
  y = that->y + otherVertex->y;
  z = that->z + otherVertex->z;
  return (new(Vertex, x, y, z));
}

/**
 * Compute difference between two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Vertex_sub(const Object* self, const Object* other)
{
  const VertexClass	*that;
  const VertexClass	*otherVertex;
  int			x;
  int			y;
  int			z;

  that = self;
  otherVertex = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherVertex->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherVertex->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  x = that->x - otherVertex->x;
  y = that->y - otherVertex->y;
  z = that->z - otherVertex->z;
  return (new(Vertex, x, y, z));
}

static VertexClass	_description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_toString, &Vertex_add, &Vertex_sub},
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
