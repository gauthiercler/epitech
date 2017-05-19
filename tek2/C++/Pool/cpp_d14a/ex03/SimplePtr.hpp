/*
** SimplePtr.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/ex03/SimplePtr.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 20:32:10 2017 Gauthier CLER
** Last update Tue Jan 17 20:32:10 2017 Gauthier CLER
*/

#ifndef SIMPLE_PTR_HPP_
#define SIMPLE_PTR_HPP_

#include "BaseComponent.hpp"

class SimplePtr
{
    public:
        explicit SimplePtr(BaseComponent *rawPtr);
        ~SimplePtr();
        BaseComponent *get() const;

    private:
        // Make the class non copyable
        SimplePtr(SimplePtr const &);
        SimplePtr &operator=(SimplePtr const &);

        BaseComponent *_rawPtr;
};

#endif // SIMPLE_PTR_HPP_
