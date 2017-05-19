/*
** Oxygenator.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/Oxygenator.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:15 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:15 2017 Gauthier CLER
*/

#ifndef OXYGENATOR_HPP_
#define OXYGENATOR_HPP_

#include "BaseComponent.hpp"

class Oxygenator
    : public BaseComponent
{
    public:

        Oxygenator();
        virtual ~Oxygenator() {}

        void generateOxygen();
        void useOxygen(int quantity);

    private:
        int _quantity;

};

#endif // OXYGENATOR_HPP_
