/*
** get_sequence.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Jun  3 19:10:49 2016 Buyumad Anas
** Last update Sun Jun  5 20:18:35 2016 Buyumad Anas
*/

#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Gets the corresponding termcap sequence
** @params sequence
** @return char *;
*/
char		*line_editor_get_sequence(char *sequence)
{
  return (tgetstr(sequence, NULL));
}
