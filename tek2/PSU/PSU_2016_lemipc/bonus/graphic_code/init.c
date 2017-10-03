/*
** init.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/init.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 16:52:03 2017 Gauthier Cler
** Last update Sun Apr 02 16:52:03 2017 Gauthier Cler
*/

#include		"lem_graphic.h"

void			init_graphic(t_graphic	*graphic)
{
  graphic->window = NULL;
  graphic->frames.screen = NULL;
  graphic->frames.title = NULL;
  graphic->frames.anas = NULL;
  graphic->frames.gauthier = NULL;
  graphic->frames.arena = NULL;
  graphic->frames.teams = NULL;
  graphic->frames.team = NULL;
  graphic->frames.wins = NULL;
}

static void		load_teams(t_graphic *graphic)
{
  char			*path;
  int			idx;

  if ((path = strdup("ressources/Team0.png")) == NULL)
    exit(EXIT_FAILURE);
  idx = 0;
  while (idx < 10)
  {
    path[15] = idx + 48;
    if ((graphic->teams[idx].id = IMG_Load(path)) == NULL)
    {
      fprintf(stderr, "Couldn't load %s, Error : %s\n", path, SDL_GetError());
      exit(EXIT_FAILURE);
    }
    idx += 1;
  }
}

static void		load_ressources_sprites(t_graphic *graphic)
{
  if ((graphic->frames.teams = IMG_Load("ressources/Teams.png")) == NULL)
    display_sdl_error("Couldn't load teams.png ");
  if ((graphic->frames.team = IMG_Load("ressources/Team.png")) == NULL)
    display_sdl_error("Couldn't load team.png ");
  if ((graphic->frames.wins = IMG_Load("ressources/Wins.png")) == NULL)
    display_sdl_error("Couldn't load wins.png ");
}

void			load_ressources(t_graphic *graphic)
{
  if ((graphic->frames.title = IMG_Load("ressources/title.png")) == NULL)
    display_sdl_error("Couldn't load title.png ");
  if ((graphic->frames.anas = IMG_Load("ressources/Anas.png")) == NULL)
    display_sdl_error("Couldn't load anas.png ");
  if ((graphic->frames.gauthier = IMG_Load("ressources/Gauthier.png")) == NULL)
    display_sdl_error("Couldn't load gauthier.png ");
  if ((graphic->frames.arena = IMG_Load("ressources/Arena.png")) == NULL)
    display_sdl_error("Couldn't load arena.png ");
  load_ressources_sprites(graphic);
  load_teams(graphic);
}