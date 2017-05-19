/*
** String.c for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:54 2017 Gauthier Cler
** Last update Sat Jan  7 09:38:53 2017 Gauthier Cler
*/

#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>
#include	<unistd.h>
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
static char const	*c_str(String *this);
static int	empty(String *this);
static int	find_s(String *this, const String *str, size_t pos);
static int	find_c(String *this, char const *str, size_t pos);
static void	insert_s(String *this, size_t pos, String const *str);
static void	insert_c(String *this, size_t pos, char const *str);
static int	to_int(String *this);
static String	*split_s(String *this, char separator);
static char	**split_c(String *this, char separator);
static void	aff(String *this);

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
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
    this->aff = &aff;
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

static char const	*c_str(String *this)
{
  if (!this)
    return NULL;
  return this->str;
}

static int	empty(String *this)
{
  if (!this || !this->str)
    return 1;
  if (strlen(this->str))
    return -1;
  return 1;
}

static int	find_s(String *this, const String *str, size_t pos)
{
  if (!this || !this->str || !str || !str->str)
    return -1;
  return find_c(this, str->str, pos);
}

static int	find_c(String *this, char const *str, size_t pos)
{
  size_t	index = pos;
  if (!this || !this->str || !str)
    return -1;
  if (strlen(str) > strlen(this->str) - pos)
    return -1;
  while (this->str[index])
    {
      if (!strncmp(this->str + index, str, strlen(str)))
	return index;
      index += 1;
    }
  return -1;
}

static void	insert_s(String *this, size_t pos, String const *str)
{
  if (!this || !this->str || !str || !str->str)
    return ;
  insert_c(this, pos, str->str);
}

static void	insert_c(String *this, size_t pos, char const *str)
{
  char		*newString;

  if (!this || !this->str || !str)
    return ;
  if (pos > strlen(this->str))
    pos = strlen(this->str);
  newString = malloc(strlen(this->str) + strlen(str) + 1);
  if (!newString)
    return ;
  strncpy(newString, this->str, pos);
  newString[pos] = '\0';
  strcat(newString, str);
  strcat(newString, this->str + pos);
  free(this->str);
  this->str = newString;
}

static int	to_int(String *this)
{
  if (!this || !this->str)
    return 0;
  return atoi(this->str);
}

static String	*split_s(String *this, char separator)
{
  char		**tmp;
  String	*table;
  size_t	iterator = 0;
  size_t	size = 0;
  
  if (!this || !this->str)
    return NULL;
  tmp = split_c(this, separator);
  if (!tmp)
    return NULL;
  while (tmp[size])
    size += 1;
  table = malloc(sizeof(String) * (size + 1));
  if (!table)
    return NULL;
  iterator = 0;
  while (iterator < size)
    {
      table[iterator].str = strdup(tmp[iterator]);
      free(tmp[iterator]);
      iterator += 1;
    }
  free(tmp);
  return table;
}

static char	**split_c(String *this, char separator)
{
  char		**table;
  char		*tmp;
  size_t	size = 0;
  size_t	iterator = 0;
  size_t	counter = 1;
  char		Separator[2];

  if (!this || !this->str)
    return NULL;
  
  Separator[0] = separator;
  Separator[1] = '\0';
  while (this->str[iterator])
    {
      if (this->str[iterator] == separator)
	size += 1;
      iterator += 1;
    }
  tmp = strdup(this->str);
  table = malloc(sizeof(char *) * (size + 2));
  if (!table)
    return NULL;
  table[0] = strdup(strtok(tmp, Separator));
  if (!table[0])
    return NULL;
  while (counter < size + 1)
    {
      table[counter] = strdup(strtok(NULL, Separator));
      if (!table[counter])
	return NULL;
      counter += 1;
    }
  table[size + 1] = NULL;
  free(tmp);
  return table;
}

static void	aff(String *this)
{
  if (!this || !this->str)
    return;
  write(1, this->str, strlen(this->str));
}
