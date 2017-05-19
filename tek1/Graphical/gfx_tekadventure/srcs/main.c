/*
** main.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 17:55:47 2016 Anas Buyumad
** Last update Sun Apr 17 22:26:53 2016 Buyumad Anas
*/

#include	<adventure.h>

int		start_game(t_adventure *adventure)
{
  bunny_set_click_response(&handle_clicks);
  bunny_set_key_response(&handle_keys);
  bunny_set_loop_main_function(&main_loop);
  bunny_loop(adventure->window, 200, adventure);
  return (SUCCESS);
}

void		init_var(t_adventure *adventure)
{
  adventure->endgame = false;
  adventure->nb_levels = 1;
  adventure->current_level = -1;
  adventure->main_pos = 0;
  adventure->character.moving = false;
  adventure->character.blocked = false;
  adventure->character.moving_decor = true;
  adventure->character.current_graph = 0;
  adventure->character.moving_graph = false;
}

int		load_misc(t_adventure *adventure)
{
  if ((adventure->back_button =
       bunny_load_picture("./ressources/back_button.png")) == NULL)
    return (format(2, "ERROR : Couldn't load the back button.\n"));
  if ((adventure->node = bunny_load_picture("./ressources/node.png")) == NULL)
    return (format(2, "ERROR : Couldn't load the node image.\n"));
  return (SUCCESS);
}

int		start_up(char *filename)
{
  t_adventure	adventure;

  if (load_levels(adventure.levels, filename) == ERROR)
    return (format(2, "ERROR : Couldn't load the levels.\n"));
  if ((adventure.ressources = load_ressources(filename)) == NULL)
    return (format(2, "ERROR : Couldn't load the ressources.\n"));
  if (load_menu(&adventure.menu) == ERROR)
    return (ERROR);
  if (load_character(&adventure.character, filename) == ERROR)
    return (ERROR);
  if ((adventure.window =
       bunny_start_style(1024, 768,
			 TITLEBAR | CLOSE_BUTTON | NO_BORDER,
			 "Adventure")) == NULL)
    return (format(2, "ERROR : Couldn't create the window.\n"));
  if ((adventure.pix = bunny_new_pixelarray(1024, 768)) == NULL)
    return (format(2, "ERROR : Couldn't create the pixelarray.\n"));
  if (load_misc(&adventure) == ERROR)
    return (ERROR);
  init_var(&adventure);
  fill_levels_hitboxes(&adventure);
  start_game(&adventure);
  clean_struct(&adventure);
  return (SUCCESS);
}

int		main(int ac, char **av, char **ae)
{
  if (check_env(ae) == ERROR)
    return (format(2, "Couldn't start game. missing env.\n"));
  bunny_set_maximum_ram(50000000);
  if (ac == 2)
    start_up(av[1]);
  else
    format(2, "Please enter a config file.\n");
  return (0);
}
