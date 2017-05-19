/*
** Exo-1.c for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex-1/Exo-1.c
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 11:11:40 2017 Gauthier CLER
** Last update Thu Jan 12 11:11:40 2017 Gauthier CLER
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Exo-1.h"

static void KoalaInitializer(t_koala* self, char* name, char isALegend);
static void CthulhuInitializer(t_cthulhu* self);


t_cthulhu	*NewCthulhu()
{
  t_cthulhu	*new;
  new = malloc(sizeof(t_cthulhu));
  if (!new)
    return NULL;
  CthulhuInitializer(new);
  return new;
}

void		PrintPower(t_cthulhu *self)
{
  if (self)
    printf("Power => %d\n", self->m_power);
}

void		Attack(t_cthulhu *self)
{
  if (self){
    if (self->m_power >= 42){
      self->m_power -= 42;
      printf("%s attacks and destroys the city\n", self->m_name);
    }
    else{
      printf("%s can't attack, he doesn't have enough power\n", self->m_name);
    }
  }
}

void		Sleeping(t_cthulhu *self)
{
  if (self){
    self->m_power += 42000;
    printf("%s sleeps\n", self->m_name);
  }
}

t_koala		*NewKoala(char* name, char isALegend)
{
  t_koala	*new;

  new = malloc(sizeof(t_koala));
  if (!new)
    return NULL;
  KoalaInitializer(new, name, isALegend);
  return new;
}

void		Eat(t_koala* self)
{
  if (self){
    self->m_parent.m_power += 42;
    printf("%s eats\n", self->m_parent.m_name);
  }
}

static void KoalaInitializer(t_koala* self, char* name, char isALegend)
{
  self->m_parent.m_name = strdup(name);
  self->m_parent.m_power = 42;
  self->m_isALegend = isALegend;
  if (!self->m_isALegend)
    self->m_parent.m_power = 0;
  printf("----\nBuilding Cthulhu\nBuilding %s\n", name);
}

static void CthulhuInitializer(t_cthulhu* self)
{
  self->m_name = strdup("Cthulhu");
  self->m_power = 42;
  printf("----\nBuilding Cthulhu\n");
}