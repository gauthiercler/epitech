/*
** print_sequence.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Jun  3 19:09:07 2016 Buyumad Anas
** Last update Sun Jun  5 20:28:14 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"class/line_editor.h"

/*
** Prints sequence.
** @params sequence
** @return int;
*/
int		line_editor_print_sequence(int sequence)
{
  write(1, &sequence, 1);
  return (0);
}
