/*
** IListener.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/IListener.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:13:45 2017 Gauthier Cler
** Last update Sun Oct 08 22:13:46 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_LISTENER_HPP
#define CPP_SPIDER_LISTENER_HPP

#include <windows.h>
#include "Error.hpp"

namespace Client {

	class IListener {

	public:
		virtual void createHook(HINSTANCE const &moduleHandle) = 0;

		virtual void removeHook() = 0;

	protected:

		HHOOK _hook;

	};

}


#endif //CPP_SPIDER_LISTENER_HPP
