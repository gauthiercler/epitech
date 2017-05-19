/*
** char.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_04/char.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 14:07:36 2017 Antoine FORET
** Last update Sat Jan 07 14:07:36 2017 Antoine FORET
*/


#define			_GNU_SOURCE
#include		"raise.h"		/* Fix redefinition of macros */
#include		<string.h>
#include		"object.h"
#include		"new.h"
#include		"char.h"

typedef			struct
{
  Class			base;
  char			value;
  char			*str_representation;
} CharClass;

/**
 * Initialize self instance with parameters from list
 *
 * @param self
 * @param list
 */
static void		Char_ctor(Object *self, va_list *list)
{
  ((CharClass *)self)->value = (char)va_arg(list, int);
}

/**
 * Clean self instance
 *
 * @param self
 */
static void		Char_dtor(Object* self)
{
  if (self != NULL && ((CharClass *)self)->str_representation != NULL)
  {
    free(((CharClass *)self)->str_representation);
  }
}

/**
 * Convert self instance into string
 *
 * @param self
 * @return
 */
static char const	*Char_toString(Object* self)
{
  CharClass		*that;

  if (self == NULL)
    return (NULL);
  that = ((CharClass *)self);
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
static Object		*Char_add(const Object* self, const Object* other)
{
  const CharClass	*that;
  const CharClass	*otherChar;
  int			result;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried to add two different Class");
  result = that->value + otherChar->value;
  return (new(Char, result));
}

/**
 * Compute difference between two objects of the same class
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Char_sub(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;
  int			result;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value - otherChar->value;
  return (new(Char, result));
}

/**
 * Compute multiplication between two Object of the same type
 *
 * @param self
 * @param other
 * @return
 */
static Object		*Char_mul(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;
  int			result;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  result = that->value * otherChar->value;
  return (new(Char, result));
}

static Object		*Char_div(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;
  int			result;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried to subtract two different Class");
  if (otherChar->value == 0)
    raise("Invalid operation: Tried to div by 0");
  result = that->value / otherChar->value;
  return (new(Char, result));
}

/**
 * Check if two object have the same value
 *
 * @param self
 * @param other
 * @return
 */
static bool		Char_eq(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value == otherChar->value));
}

/**
 * Test if Object is lower that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Char_lt(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value < otherChar->value));
}

/**
 * Test if Object is greater that the other. Have to be the same type of Object
 *
 * @param self
 * @param other
 * @return
 */
static bool		Char_gt(const Object *self, const Object *other)
{
  const CharClass	*that;
  const CharClass	*otherChar;

  that = self;
  otherChar = other;
  if (self == NULL || other == NULL ||
      that->base.__name__ == NULL || otherChar->base.__name__ == NULL ||
      strcmp(that->base.__name__, otherChar->base.__name__) != 0)
    raise("Tried compare two different type of object");
  return ((that->value > otherChar->value));
}



static CharClass		_description = {
  {
    sizeof(CharClass),
    "Char",
    &Char_ctor,
    &Char_dtor,
    &Char_toString,
    &Char_add,
    &Char_sub,
    &Char_mul,
    &Char_div,
    &Char_eq,
    &Char_gt,
    &Char_lt
  },
  0, NULL
};

Class* Char = (Class*) &_description;
