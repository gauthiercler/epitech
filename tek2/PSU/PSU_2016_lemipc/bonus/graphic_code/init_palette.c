/*
** init_palette.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/init_palette.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 16:56:17 2017 Gauthier Cler
** Last update Sun Apr 02 16:56:17 2017 Gauthier Cler
*/

#include		"lem_graphic.h"

static void		init_palettes(t_color palette[10])
{
  palette[7].red = 244;
  palette[7].green = 51;
  palette[7].blue = 255;
  palette[8].red = 255;
  palette[8].green = 245;
  palette[8].blue = 238;
  palette[9].red =  248;
  palette[9].green = 114;
  palette[9].blue = 23;
  palette[0].alpha = 255;
  palette[1].alpha = 255;
  palette[2].alpha = 255;
  palette[3].alpha = 255;
  palette[4].alpha = 255;
  palette[5].alpha = 255;
  palette[6].alpha = 255;
  palette[7].alpha = 255;
  palette[8].alpha = 255;
  palette[9].alpha = 255;
}

void			init_palette(t_color palette[10])
{
  palette[0].red = 31;
  palette[0].green = 69;
  palette[0].blue = 252;
  palette[1].red = 127;
  palette[1].green = 255;
  palette[1].blue = 212;
  palette[2].red = 95;
  palette[2].green = 251;
  palette[2].blue = 23;
  palette[3].red = 255;
  palette[3].green = 216;
  palette[3].blue = 1;
  palette[4].red = 255;
  palette[4].green = 36;
  palette[4].blue = 0;
  palette[5].red =  158;
  palette[5].green = 123;
  palette[5].blue = 255;
  palette[6].red =  245;
  palette[6].green = 40;
  palette[6].blue = 135;
  init_palettes(palette);
}

void			init_palette_t(t_color palette[1])
{
  palette[0].red = 229;
  palette[0].green = 228;
  palette[0].blue = 226;
  palette[0].alpha = 255;
}