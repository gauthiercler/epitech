/*
** draw_amazing.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 22:55:02 2016 Buyumad Anas
** Last update Tue May  3 15:28:56 2016 Buyumad Anas
*/

#include	"amazing.h"

void		draw_titles(t_amazing *amazing)
{
  t_position	pos;

  pos.x = 550;
  pos.y = 50;
  blit(amazing->Screen, amazing->Generator, &pos);
  pos.y = 150;
  blit(amazing->Screen, amazing->Type, &pos);
  pos.y = 250;
  blit(amazing->Screen, amazing->Size, &pos);
  pos.y = 325;
  blit(amazing->Screen, amazing->Solver, &pos);
  pos.y = 425;
  blit(amazing->Screen, amazing->Type, &pos);
  pos.y = 15;
  pos.x = 115;
  blit(amazing->Screen, amazing->Credits, &pos);
  pos.x = 775;
  pos.y = 250;
  blit(amazing->Screen, amazing->WxH, &pos);
}

void		draw_amazing(t_amazing *amazing)
{
  blit(amazing->Screen, amazing->Background, NULL);
  draw_titles(amazing);
  draw_maze(amazing);
  draw_buttons(amazing, amazing->buttons);
}
