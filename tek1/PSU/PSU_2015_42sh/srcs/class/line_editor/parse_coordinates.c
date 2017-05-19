/*
** parse_coordinates.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Jun  2 22:12:42 2016 Buyumad Anas
** Last update Sun Jun  5 20:27:52 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"libc.h"

/*
** Extracts number from a string
** @params sequence, coord
** @return char * ; Success => number string, Error => NULL
*/
static char	*line_editor_extract_number(char *sequence, size_t *dimension)
{
  char		*number_string;
  size_t	iterator;
  size_t	size;

  iterator = 0;
  size = dimension[1] - dimension[0];
  if ((number_string = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  while (iterator < size)
    {
      number_string[iterator] = sequence[dimension[0] + iterator];
      iterator += 1;
    }
  number_string[iterator] = '\0';
  sequence += size;
  return (number_string);
}

/*
** Parses number of a string
** @params sequence, start index
** @return size_t * ; Success => Coords ; Error => NULL
*/
static size_t	*line_editor_parse_number(char *sequence, size_t start)
{
  size_t	iterator;
  size_t	*dimension;
  bool		extracting;

  iterator = start;
  if ((dimension = malloc(sizeof(size_t) * 2)) == NULL)
    return (NULL);
  dimension[0] = 0;
  dimension[1] = 0;
  extracting = false;
  while (sequence[iterator])
    {
      if (sequence[iterator] >= '0' && sequence[iterator] <= '9' && !extracting)
	{
	  dimension[0] = iterator;
	  extracting = true;
	}
      if (extracting && (sequence[iterator] < '0' || sequence[iterator] > '9'))
	{
	  dimension[1] = iterator;
	  return (dimension);
	}
      iterator += 1;
    }
  return (NULL);
}

/*
** Parses cursor coordinates
** @params sequence, coord
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_parse_coordinates(char *sequence, int *coord)
{
  size_t	*dimension;
  char		*y_string;
  char		*x_string;
  size_t	start;

  if ((dimension = line_editor_parse_number(sequence, 0)) == NULL)
    return (false);
  if ((y_string = line_editor_extract_number(sequence, dimension)) == NULL)
    return (false);
  start = dimension[1];
  free(dimension);
  if ((dimension = line_editor_parse_number(sequence, start)) == NULL)
    return (false);
  if ((x_string = line_editor_extract_number(sequence, dimension)) == NULL)
    return (false);
  free(dimension);
  coord[0] = get_number(x_string);
  coord[1] = get_number(y_string);
  free(x_string);
  free(y_string);
  return (true);
}
