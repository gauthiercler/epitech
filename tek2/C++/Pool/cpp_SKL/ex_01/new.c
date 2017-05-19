/*
** new.c for cpp_SKL in /home/foret_a/Lab/cpp_SKL/ex_01/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 07 09:49:18 2017 Antoine FORET
** Last update Sat Jan 07 09:49:18 2017 Antoine FORET
*/

#include	<memory.h>
#include	"object.h"
#include	"raise.h"

/**
 * Create an new object instance of type "class"
 *
 * @param class
 * @return void *object
 */
void		*new(Class *class)
{
  void		*object;

  if (class == NULL)
    raise("Tried to create new(NULL)");
  if ((object = malloc(class->__size__)) == NULL)
    raise("Unable to allocate memory");
  memcpy(object, class, class->__size__);
  if (((Class *)object)->__init__ != NULL)
    ((Class *)object)->__init__(object);
  return (object);
}

/**
 * Delete an object instance
 *
 * @param ptr
 */
void		delete(Object *ptr)
{
  if (ptr == NULL)
    raise("Tried to delete(NULL)");
  if (((Class *)ptr)->__del__ != NULL)
    ((Class *)ptr)->__del__(ptr);
  free(ptr);
}
