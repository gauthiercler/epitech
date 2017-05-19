/*
** Ex-1.h.h for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex-1/Ex-1.h.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 11:12:00 2017 Gauthier CLER
** Last update Thu Jan 12 11:12:00 2017 Gauthier CLER
*/


#ifndef CPP_D09_EX_1_H_H
#define CPP_D09_EX_1_H_H

typedef struct	s_cthulhu
{
  int		m_power;
  char		*m_name;
}		t_cthulhu;

typedef struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;
}		t_koala;

t_cthulhu	*NewCthulhu();
void		PrintPower(t_cthulhu *self);
void		Attack(t_cthulhu *self);
void		Sleeping(t_cthulhu *self);

t_koala		*NewKoala(char* name, char _isALegend);
void		Eat(t_koala* self);


#endif //CPP_D09_EX_1_H_H
