/*
** String.c for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:54 2017 Gauthier Cler
** Last update Sat Jan  7 09:42:42 2017 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"String.h"

static void	assign_s(String *this, String const *str);
static void	assign_c(String *this, char const *s);
static void	append_s(String *this, String const *ap);
static void	append_c(String *this, char const *aps);

void	StringInit(String *this, char const *s)
{
  if (this){
    if (s)
      this->str = strdup(s);
    else
      this->str = NULL;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_c = &append_c;
    this->append_s = &append_s;
  }
}

void	StringDestroy(String *this)
{
  if (this){
      if (this->str){
	  free(this->str);
	  this->str = NULL;
	}
    }
}

static void	assign_s(String *this, String const *str)
{
  if (this){
      if (this->str)
	free(this->str);
      if (str && str->str)
	  this->str = strdup(str->str);
      else
	this->str = NULL;
    }
}

static void	assign_c(String *this, char const *s)
{
  if (this){
      if (this->str)
	free(this->str);
      if (s)
	this->str = strdup(s);
      else
	this->str = NULL;
    }
}

static void	append_s(String *this, String const *ap)
{
  char		*newString;

  if (!this || !ap || !ap->str)
    return ;
  if (!this->str && ap->str){
      this->str = strdup(ap->str);
    }
  else{
      newString = malloc(strlen(this->str) + strlen(ap->str) + 1);
      strcpy(newString, this->str);
      strcat(newString, ap->str);
      free(this->str);
      this->str = newString;
    }
}

static void	append_c(String *this, char const *aps)
{
  char		*newString;

  if (!this || !aps)
    return ;
  if (!this->str && aps){
      this->str = strdup(aps);
      strcpy(this->str, aps);
    }
  else{
      newString = malloc(strlen(this->str) + strlen(aps) + 1);
      strcpy(newString, this->str);
      strcat(newString, aps);
      free(this->str);
      this->str = newString;
    }
}
