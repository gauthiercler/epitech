/*
** load_buttons.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 21:15:38 2016 Buyumad Anas
** Last update Sun May 22 23:12:56 2016 Gauthier Cler
*/

#include	"amazing.h"

void		load_gen_type(t_button buttons[NB_BUTTONS])
{
  if ((buttons[0].button_normal =
       load_image("./ressources/buttons/BacktrackU.png")) == NULL)
    exit(printf("Couldn't load Button BacktrackU."));
  if ((buttons[0].button_hover =
       load_image("./ressources/buttons/BacktrackO.png")) == NULL)
    exit(printf("Couldn't load Button BacktrackO."));
  if ((buttons[0].button_selected =
       load_image("./ressources/buttons/BacktrackS.png")) == NULL)
    exit(printf("Couldn't load Button BacktrackS."));
  if ((buttons[1].button_normal =
       load_image("./ressources/buttons/PrimU.png")) == NULL)
    exit(printf("Couldn't load Button PrimU."));
  if ((buttons[1].button_hover =
       load_image("./ressources/buttons/PrimO.png")) == NULL)
    exit(printf("Couldn't load Button PrimO."));
  if ((buttons[1].button_selected =
       load_image("./ressources/buttons/PrimS.png")) == NULL)
    exit(printf("Couldn't load Button PrimS."));
}

void		load_solver_type_next(t_button buttons[NB_BUTTONS])
{
  if ((buttons[4].button_normal =
       load_image("./ressources/buttons/A-StarU.png")) == NULL)
    exit(printf("Couldn't load Button A-StarU."));
  if ((buttons[4].button_hover =
       load_image("./ressources/buttons/A-StarO.png")) == NULL)
    exit(printf("Couldn't load Button A-StarO."));
  if ((buttons[4].button_selected =
       load_image("./ressources/buttons/A-StarS.png")) == NULL)
    exit(printf("Couldn't load Button A-StarS."));
}

void		load_solver_type(t_button buttons[NB_BUTTONS])
{
  if ((buttons[2].button_normal =
       load_image("./ressources/buttons/DepthU.png")) == NULL)
    exit(printf("Couldn't load Button DepthU."));
  if ((buttons[2].button_hover =
       load_image("./ressources/buttons/DepthO.png")) == NULL)
    exit(printf("Couldn't load Button DepthO."));
  if ((buttons[2].button_selected =
       load_image("./ressources/buttons/DepthS.png")) == NULL)
    exit(printf("Couldn't load Button DepthS."));
  if ((buttons[3].button_normal =
       load_image("./ressources/buttons/BreadthU.png")) == NULL)
    exit(printf("Couldn't load Button BreadthU."));
  if ((buttons[3].button_hover =
       load_image("./ressources/buttons/BreadthO.png")) == NULL)
    exit(printf("Couldn't load Button BreadthO."));
  if ((buttons[3].button_selected =
       load_image("./ressources/buttons/BreadthS.png")) == NULL)
    exit(printf("Couldn't load Button BreadthS."));
  load_solver_type_next(buttons);
}

void		init_solver_buttons(t_button buttons[NB_BUTTONS])
{
  buttons[2].name = strdup("Depth");
  buttons[2].hitbox.x = 700;
  buttons[2].hitbox.y = 430;
  buttons[2].hitbox.w = 106;
  buttons[2].hitbox.h = 53;
  buttons[3].name = strdup("Breadth");
  buttons[3].hitbox.x = 826;
  buttons[3].hitbox.y = 430;
  buttons[3].hitbox.w = 136;
  buttons[3].hitbox.h = 45;
  buttons[4].name = strdup("A-Star");
  buttons[4].hitbox.x = 700;
  buttons[4].hitbox.y = 490;
  buttons[4].hitbox.w = 121;
  buttons[4].hitbox.h = 42;
}

void		load_buttons(t_button buttons[NB_BUTTONS])
{
  load_gen_type(buttons);
  load_solver_type(buttons);
  load_action_buttons(buttons);
  buttons[0].state = 1;
  buttons[1].state = 1;
  buttons[2].state = 1;
  buttons[3].state = 1;
  buttons[4].state = 1;
  buttons[0].type = 1;
  buttons[1].type = 1;
  buttons[2].type = 1;
  buttons[3].type = 1;
  buttons[4].type = 1;
  buttons[0].name = strdup("Backtrack");
  buttons[0].hitbox.x = 700;
  buttons[0].hitbox.y = 155;
  buttons[0].hitbox.w = 167;
  buttons[0].hitbox.h = 42;
  buttons[1].name = strdup("Prim");
  buttons[1].hitbox.x = 887;
  buttons[1].hitbox.y = 155;
  buttons[1].hitbox.w = 89;
  buttons[1].hitbox.h = 42;
  init_solver_buttons(buttons);
}
