/*
** bitmap_header.c for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex02/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan  4 18:03:35 2017 Gauthier Cler
** Last update Wed Jan  4 21:05:09 2017 Gauthier Cler
*/

#include	"bitmap.h"

void		make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->size = size * size * 4 + 14 + 40;
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = 54;
}

void		make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * size * 4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
