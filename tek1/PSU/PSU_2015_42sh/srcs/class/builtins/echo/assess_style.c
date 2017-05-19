/*
** assess_style.c for echo in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 23:04:08 2016 Buyumad Anas
** Last update Sun Jun  5 20:45:54 2016 Gauthier Cler
*/

#include	"class/echo.h"

/*
** Finds which echo style is on.
** @params self
** @return void
*/
void			echo_assess_style(t_echo *self)
{
  self->echo_style = BOTH;
}
