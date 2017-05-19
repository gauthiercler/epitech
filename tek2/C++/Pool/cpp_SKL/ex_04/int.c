/*
** int.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_04/int.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 14:07:18 2017 Antoine FORET
** Last update Sat Jan 07 14:07:18 2017 Antoine FORET
*/

#define			_GNU_SOURCE
#include		"raise.h"		/* Fix redefinition of macros */
#include		<string.h>
#include		"object.h"
#include		"new.h"
#include		"int.h"

typedef			struct
{
  Class			base;
  int			value;
  char			*str_representation;
} IntClass;

/**
 * Initialize self instance with parameters from list
 *
 * @param self
 * @param list
 */
static void		Int_ctor(Object *self, va_list *list)
{
  ((IntClass *)self)->value = va_arg(list, int);
}

/**
 * Clean self instance
 *
 * @param self
 */
static void		Int_dtor(Object* self)
{
  if (self != NULL && ((IntClass *)self)->str_representation != NULL)
  {
    free(((IntClass *)self)->str_representation);
  }
}

/**
 * Convert self instance into string
 *
 * @param self
 * @return
 */
static char const	*Int_toString(Object* self)
{
  IntClass		*that;

  if (self == NULL)
    return (NULL);
  that = ((IntClass *)self);
  if (that->str_representation != NULL)
    free(that->str_representation);
  asprintf(&that->str_representation, "<%s (%d)>", that->base.__name__, that->value);
  return (that->str_representation);
}

/**
 * Compute sum of two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Int_add(const Object* self, const Object* other)
{
  const IntClass	*that;
  const IntClass	*otherInt;
  int			result;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried to add two different Class");
  result = that->value + otherInt->value;
  return (new(Int, result));
}

/**
 * Compute difference between two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Int_sub(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;
  int			result;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value - otherInt->value;
  return (new(Int, result));
}

/**
 * Compute multiplication between two Object of the same type
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Int_mul(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;
  int			result;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value * otherInt->value;
  return (new(Int, result));
}

static Object		*Int_div(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;
  int			result;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  if (otherInt->value == 0)
    raise("Invalid operation: Tried to div by 0");
  result = that->value / otherInt->value;
  return (new(Int, result));
}

/**
 * Check if two object have the same value
 *
 * @param self
 * @param other
 * @return
 */
static bool		Int_eq(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value == otherInt->value));
}

/**
 * Test if Object is lower that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Int_lt(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value < otherInt->value));
}

/**
 * Test if Object is greater that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Int_gt(const Object *self, const Object *other)
{
  const IntClass	*that;
  const IntClass	*otherInt;

  that = self;
  otherInt = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherInt->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherInt->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value > otherInt->value));
}



static IntClass		_description = {
  {
    sizeof(IntClass),
    "Int",
    &Int_ctor,
    &Int_dtor,
    &Int_toString,
    &Int_add,
    &Int_sub,
    &Int_mul,
    &Int_div,
    &Int_eq,
    &Int_gt,
    &Int_lt
  },
  0, NULL
};

Class* Int = (Class*) &_description;
