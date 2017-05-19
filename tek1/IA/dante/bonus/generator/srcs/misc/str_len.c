/*
** str_len.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:51:08 2016 Buyumad Anas
** Last update Tue Apr 26 15:51:11 2016 Buyumad Anas
*/

int		str_len(char *string)
{
  return (*string) ? str_len(++string) + 1 : 0;
}
