/*
** sawp.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/array/sawp.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 22:30:38 2016 Antoine FORET
** Last update Sun Jun  5 18:35:02 2016 Gauthier Cler
*/

/*
** Swap two elements
** @params elem1, elem2
** @return void
*/
void		swap(void **elem1, void **elem2)
{
  void		*tmp;

  tmp = *elem1;
  *elem1 = *elem2;
  *elem2 = tmp;
}
