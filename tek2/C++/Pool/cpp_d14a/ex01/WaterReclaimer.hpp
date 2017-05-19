/*
** WaterReclaimer.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex01/WaterReclaimer.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 18:08:28 2017 Gauthier CLER
** Last update Tue Jan 17 18:08:28 2017 Gauthier CLER
*/

#ifndef WATER_RECLAIMER_HPP_
#define WATER_RECLAIMER_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class WaterReclaimer
    : public BaseComponent
{
    public:
        WaterReclaimer();
        virtual ~WaterReclaimer() {}

        void start();
        void generateWater();
        void useWater(int water);

    private:
        int _water;
        bool _started;
};

#endif // WATER_RECLAIMER_HPP_
