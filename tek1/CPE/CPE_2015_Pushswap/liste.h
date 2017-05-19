/*
** liste.h for liste in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 18:52:02 2015 Gauthier Cler
** Last update Sun Nov 22 19:13:39 2015 Gauthier Cler
*/

#ifndef LISTE_H_
#define LISTE_H_

typedef struct s_list
{
  int	valeur;
  struct s_list   *next;
} t_list;

void add_liste(t_list **, int);
void add_fin_liste(t_list **, int);
void disp_liste(t_list *);
int liste_len(t_list *);
int sa(t_list *);
int sb(t_list *);
int ss(t_list *, t_list *);
int pa(t_list **, t_list **);
int pb(t_list **, t_list **);
int ra(t_list **);
int rb(t_list **);
int rr(t_list **, t_list **);
int rra(t_list **);
int rrb(t_list **);
int rrr(t_list **, t_list **);
int rra_s(t_list **);
int rrb_s(t_list **);
t_list loop_liste(t_list **, t_list **);
int check_liste(t_list *);
int check_start(t_list *);

#endif
