/*
** load_actions.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 30 16:31:44 2016 Buyumad Anas
** Last update Sun May  1 16:39:12 2016 Buyumad Anas
*/

#include	"amazing.h"

void		init_size_buttons(t_button buttons[NB_BUTTONS])
{
  buttons[7].state = 1;
  buttons[8].state = 1;
  buttons[9].state = 1;
  buttons[10].state = 1;
  buttons[7].name = strdup("PlusW");
  buttons[7].hitbox.x = 700;
  buttons[7].hitbox.y = 250;
  buttons[7].hitbox.w = 37;
  buttons[7].hitbox.h = 34;
  buttons[8].name = strdup("MinusW");
  buttons[8].hitbox.x = 700;
  buttons[8].hitbox.y = 300;
  buttons[8].hitbox.w = 30;
  buttons[8].hitbox.h = 22;
  buttons[9].name = strdup("PlusH");
  buttons[9].hitbox.x = 975;
  buttons[9].hitbox.y = 250;
  buttons[9].hitbox.w = 37;
  buttons[9].hitbox.h = 34;
  buttons[10].name = strdup("MinusW");
  buttons[10].hitbox.x = 975;
  buttons[10].hitbox.y = 300;
  buttons[10].hitbox.w = 30;
  buttons[10].hitbox.h = 22;
}

void		load_size_buttons(t_button buttons[NB_BUTTONS])
{
  buttons[7].type = 2;
  if ((buttons[7].button_normal =
       load_image("./ressources/buttons/Plus.png")) == NULL)
    exit(printf("Couldn't load Button Plus"));
  buttons[7].button_hover = NULL;
  buttons[7].button_selected = NULL;
  buttons[8].type = 2;
  if ((buttons[8].button_normal =
       load_image("./ressources/buttons/Minus.png")) == NULL)
    exit(printf("Couldn't load Button Minus"));
  buttons[8].button_hover = NULL;
  buttons[8].button_selected = NULL;
  buttons[9].type = 2;
  if ((buttons[9].button_normal =
       load_image("./ressources/buttons/Plus.png")) == NULL)
    exit(printf("Couldn't load Button Plus"));
  buttons[9].button_hover = NULL;
  buttons[9].button_selected = NULL;
  buttons[10].type = 2;
  if ((buttons[10].button_normal =
       load_image("./ressources/buttons/Minus.png")) == NULL)
    exit(printf("Couldn't load Button Minus"));
  buttons[10].button_hover = NULL;
  buttons[10].button_selected = NULL;
  init_size_buttons(buttons);
}

void		init_action_buttons(t_button buttons[NB_BUTTONS])
{
  buttons[5].state = 1;
  buttons[6].state = 1;
  buttons[5].type = 1;
  buttons[6].type = 1;
  buttons[5].name = strdup("Generate");
  buttons[5].hitbox.x = 75;
  buttons[5].hitbox.y = 475;
  buttons[5].hitbox.w = 203;
  buttons[5].hitbox.h = 49;
  buttons[6].hitbox.x = 298;
  buttons[6].hitbox.y = 475;
  buttons[6].hitbox.w = 138;
  buttons[6].hitbox.h = 47;
  buttons[6].name = strdup("Solve");
}

void		load_action_buttons(t_button buttons[NB_BUTTONS])
{
  if ((buttons[5].button_normal =
      load_image("./ressources/buttons/GenerateU.png")) == NULL)
    exit(printf("Couldn't load Button GenerateU"));
  if ((buttons[5].button_hover =
       load_image("./ressources/buttons/GenerateO.png")) == NULL)
    exit(printf("Couldn't load Button GenerateU"));
  if ((buttons[5].button_selected =
       load_image("./ressources/buttons/GenerateS.png")) == NULL)
    exit(printf("Couldn't load Button GenerateU"));
  if ((buttons[6].button_normal =
       load_image("./ressources/buttons/SolveU.png")) == NULL)
    exit(printf("Couldn't load Button SolveU"));
  if ((buttons[6].button_hover =
       load_image("./ressources/buttons/SolveO.png")) == NULL)
    exit(printf("Couldn't load Button SolveU"));
  if ((buttons[6].button_selected =
       load_image("./ressources/buttons/SolveS.png")) == NULL)
    exit(printf("Couldn't load Button SolveU"));
  init_action_buttons(buttons);
  load_size_buttons(buttons);
}
