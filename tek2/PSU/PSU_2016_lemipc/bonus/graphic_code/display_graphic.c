/*
** display_graphic.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/bonus/graphic_code/display_graphic.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 02 20:18:17 2017 Anas Buyumad
** Last update Sun Apr 02 20:18:17 2017 Anas Buyumad
*/

#include		"lem_ipc.h"

static void		handle_click(SDL_Event *event, bool *pause,
					bool *press)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE)
    *pause = false;
  else if (event->type == SDL_MOUSEBUTTONDOWN)
    *press = true;
  else if (event->type == SDL_MOUSEBUTTONUP)
    *press = false;
}

static void		modify_map(char *arena, SDL_Event *event,
				      t_pos *translated_pos)
{
  if (event->button.button == SDL_BUTTON_LEFT)
  {
    if (arena[CT(translated_pos->x, translated_pos->y)] == FREE_CELL)
      arena[CT(translated_pos->x, translated_pos->y)] = '+';
  }
  else if (event->button.button == SDL_BUTTON_RIGHT ||
	   event->button.button == SDL_BUTTON_X1)
  {
    if (is_wall(arena[CT(translated_pos->x, translated_pos->y)]))
      arena[CT(translated_pos->x, translated_pos->y)] = FREE_CELL;
  }
}

static void		handle_press(t_ipc *data, SDL_Event *event)
{
  t_pos			translated_pos;
  t_pos			mousePos;
  int			ratio;

  ratio = 400 / arena_ss;
  SDL_GetMouseState(&mousePos.x, &mousePos.y);
  mousePos.x -= ((SCREEN_WIDTH / 2) / 2) - (400 / 2);
  mousePos.y -= 100;
  if (mousePos.x >= 0 && mousePos.y >= 0)
  {
    translated_pos.x = mousePos.x / ratio;
    translated_pos.y = mousePos.y / ratio;
    if (translated_pos.x >= 0 && translated_pos.x < arena_ss &&
	translated_pos.y >= 0 && translated_pos.y < arena_ss)
    {
      modify_map(data->memory->arena, event, &translated_pos);
      draw_arena(data);
      SDL_RenderPresent(data->graphic.frames.screen);
    }
  }
}

void			display_graphic(t_ipc *data)
{
  SDL_Event 		event;
  bool			pause;
  bool			press;

  press = false;
  pause = false;
  while (SDL_PollEvent(&event))
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
      pause = true;
  while (pause)
  {
    while (SDL_PollEvent(&event))
    {
      handle_click(&event, &pause, &press);
      if (press)
	handle_press(data, &event);
    }
  }
  draw_arena(data);
  display_teams(data);
  display_players(data);
  SDL_RenderPresent(data->graphic.frames.screen);
}
