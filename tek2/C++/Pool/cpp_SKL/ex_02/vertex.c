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
#include		"object.h"

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

static VertexClass	_description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_toString},
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
