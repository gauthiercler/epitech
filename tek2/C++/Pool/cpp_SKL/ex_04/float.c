/*
** float.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_04/float.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 14:07:03 2017 Antoine FORET
** Last update Sat Jan 07 14:07:03 2017 Antoine FORET
*/


#define			_GNU_SOURCE
#include		"raise.h"		/* Fix redefinition of macros */
#include		<string.h>
#include		"object.h"
#include		"new.h"
#include		"float.h"

typedef			struct
{
  Class			base;
  float			value;
  char			*str_representation;
} FloatClass;

/**
 * Initialize self instance with parameters from list
 *
 * @param self
 * @param list
 */
static void		Float_ctor(Object *self, va_list *list)
{
  ((FloatClass *)self)->value = (float)va_arg(list, double);
}

/**
 * Clean self instance
 *
 * @param self
 */
static void		Float_dtor(Object* self)
{
  if (self != NULL && ((FloatClass *)self)->str_representation != NULL)
  {
    free(((FloatClass *)self)->str_representation);
  }
}

/**
 * Convert self instance into string
 *
 * @param self
 * @return
 */
static char const	*Float_toString(Object* self)
{
  FloatClass		*that;

  if (self == NULL)
    return (NULL);
  that = ((FloatClass *)self);
  if (that->str_representation != NULL)
    free(that->str_representation);
  asprintf(&that->str_representation, "<%s (%f)>", that->base.__name__, that->value);
  return (that->str_representation);
}

/**
 * Compute sum of two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Float_add(const Object* self, const Object* other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;
  float			result;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried to add two different Class");
  result = that->value + otherFloat->value;
  return (new(Float, result));
}

/**
 * Compute difference between two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Float_sub(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;
  float			result;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value - otherFloat->value;
  return (new(Float, result));
}

/**
 * Compute multiplication between two Object of the same type
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Float_mul(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;
  float			result;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value * otherFloat->value;
  return (new(Float, result));
}

static Object		*Float_div(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;
  float			result;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  if (otherFloat->value == 0)
    raise("Invalid operation: Tried to div by 0");
  result = that->value / otherFloat->value;
  return (new(Float, result));
}

/**
 * Check if two object have the same value
 *
 * @param self
 * @param other
 * @return
 */
static bool		Float_eq(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value == otherFloat->value));
}

/**
 * Test if Object is lower that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Float_lt(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value < otherFloat->value));
}

/**
 * Test if Object is greater that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Float_gt(const Object *self, const Object *other)
{
  const FloatClass	*that;
  const FloatClass	*otherFloat;

  that = self;
  otherFloat = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherFloat->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherFloat->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value > otherFloat->value));
}



static FloatClass		_description = {
  {
    sizeof(FloatClass),
    "Float",
    &Float_ctor,
    &Float_dtor,
    &Float_toString,
    &Float_add,
    &Float_sub,
    &Float_mul,
    &Float_div,
    &Float_eq,
    &Float_gt,
    &Float_lt
  },
  0, NULL
};

Class* Float = (Class*) &_description;
