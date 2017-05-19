/*
** KreogCom.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex02/KreogCom.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 22:07:01 2017 Gauthier CLER
** Last update Tue Jan 10 22:07:01 2017 Gauthier CLER
*/


#ifndef CPP_D07M_KREOGCOM_H
#define CPP_D07M_KREOGCOM_H


class KreogCom {
public:
  KreogCom(int x, int y, int serial);
  ~KreogCom();
public:
  void addCom(int x, int y, int serial);
  KreogCom *getCom();
  void removeCom();
public:
  void ping() const;
  void locateSquad() const;
private:
  int	_x;
  int	_y;
  const int	_serial;
  KreogCom	*next;
  KreogCom	*prev;
};


#endif //CPP_D07M_KREOGCOM_H
