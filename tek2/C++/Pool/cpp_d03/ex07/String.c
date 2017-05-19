/*
** String.c for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:54 2017 Gauthier Cler
** Last update Sat Jan  7 09:43:54 2017 Gauthier Cler
*/

#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>
#include	"String.h"

static void	assign_s(String *this, String const *str);
static void	assign_c(String *this, char const *s);
static void	append_s(String *this, String const *ap);
static void	append_c(String *this, char const *aps);
static char	at(String *this, size_t pos);
static void	clear(String *this);
static int	size(String *this);
static int	compare_s(String *this, const String *str);
static int	compare_c(String *this, char const *str);
static size_t	copy(String *this, char *s, size_t n, size_t pos);

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
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
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

static char	at(String *this, size_t pos)
{
  if (!this || !this->str)
    return -1;
  if (pos >= strlen(this->str))
    return -1;
  return this->str[pos];
}

static void	clear(String *this)
{
  if (this && this->str)
    bzero(this->str, strlen(this->str));
}

static int	size(String *this)
{
  if (!this || !this->str)
    return -1;
  return strlen(this->str);
}

static int	compare_s(String *this, const String *str)
{
  if (!this || !this->str || !str || !str->str)
    return -1;
  return strcmp(this->str, str->str);
}

static int	compare_c(String *this, char const *str)
{
  if (!this || !this->str || !str)
    return -1;
  return strcmp(this->str, str);
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  size_t	iterator = pos;
  size_t	count = 0;
  
  if (!this || !this->str)
    return 0;
  if (pos > strlen(this->str) - 1)
    return 0;
  if (!s)
    return 0;
  while (this->str[iterator] && count < n)
    {
      s[count] = this->str[iterator];
      count += 1;
      iterator += 1;
    }
  return iterator - pos;
}
