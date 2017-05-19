/*
** Engine.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/Engine.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:07 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:07 2017 Gauthier CLER
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class Engine
    : public BaseComponent
{
    public:

        Engine(float power, float x = 0, float y = 0);
        virtual ~Engine();

        void goTorward(float x, float y);
        float distanceTo(float x, float y) const;

        float getX() const;
        float getY() const;

    private:
        float _power;
        float _x;
        float _y;

};

#endif // ENGINE_HPP_
