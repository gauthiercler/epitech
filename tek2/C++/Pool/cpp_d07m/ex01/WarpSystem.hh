/*
** WarpSystem.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex00/WarpSystem.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 10:40:13 2017 Gauthier CLER
** Last update Tue Jan 10 10:40:13 2017 Gauthier CLER
*/

#ifndef CPP_D07M_WARPSYSTEM_H
#define CPP_D07M_WARPSYSTEM_H


namespace WarpSystem {
  class QuantumReactor{
  private:
    bool	_stability;

  public:
    QuantumReactor();
    bool	isStable();
    void	setStability(bool);
  };
  class Core {
  private:
    QuantumReactor *_coreReactor;

  public:
    Core(QuantumReactor *reactor);
    ~Core();
    QuantumReactor *checkReactor();
  };
}


#endif //CPP_D07M_WARPSYSTEM_H
