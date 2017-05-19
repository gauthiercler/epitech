/*
** mouse.c for mouse in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Fri Feb 26 10:02:07 2016 Gauthier Cler
** Last update Tue Mar  1 22:13:25 2016 Gauthier Cler
*/

#include	<lapin/basic.h>
#include	<lapin/advanced.h>
#include	"tekgui.h"

t_bunny_response		click(t_bunny_event_state	state,
				      t_bunny_mousebutton	key,
				      void			*data)
{
  t_prog			*prog;
  const t_bunny_position	*pos;
  int				i;

  (void)key;
  i = 0;
  prog = data;
  pos = bunny_get_mouse_position();
  if (state == GO_DOWN)
    while (prog->gui[i].name != NULL)
      {
	if ((pos->x >= prog->gui[i].pos.x
	     && pos->x <= prog->gui[i].pos.x + prog->gui[i].size.x) &&
	    (pos->y >= prog->gui[i].pos.y
	     && pos->y <= prog->gui[i].pos.y + prog->gui[i].size.y))
	  if (action_cases(prog, i) == EXIT_ON_SUCCESS)
	    return (EXIT_ON_SUCCESS);
	i += 1;
      }
  return (GO_ON);
}

void			set_all_false(t_prog *prog, int i)
{
  int			j;

  j = 0;
  while (prog->gui[j].name != NULL)
    {
      if (j != i)
	prog->gui[j].text_on = false;
      j += 1;
    }
}

int			action_cases(t_prog *prog, int i)
{
  if (my_strcmp(prog->gui[i].type, "text_box") == 1)
    {
      set_all_false(prog, i);
      if (prog->gui[i].text_on == false)
	prog->gui[i].text_on = true;
      else
	prog->gui[i].text_on = false;
    }
  if (my_strcmp(prog->gui[i].action, "reload") == 1)
    {
      reset_text(prog);
      tekgui_display(prog->pix, prog->gui);
    }
  if (my_strcmp(prog->gui[i].action, "quit") == 1)
    return (EXIT_ON_SUCCESS);
  if (my_strncmp(prog->gui[i].action, "invert ", 7) == 1)
    invert_color(prog, i);
  return (GO_ON);
}

void			reset_text(t_prog *prog)
{
  int			i;

  i = 0;
  while (prog->gui[i].name != NULL)
    {
      fill_text_tab(prog->gui, i);
      i += 1;
    }
}

t_bunny_response		text(uint32_t	unicode,
				     void *data)
{
  int				i;
  t_prog		       	*prog;

  prog = data;
  i = 0;
  while (prog->gui[i].name != NULL)
    {
      if (prog->gui[i].text_on == true)
	my_tektext(prog->pix, (const char *)&unicode,
		   prog->font, prog->gui[i].text_pos);
	i += 1;
    }
  return (GO_ON);
}
