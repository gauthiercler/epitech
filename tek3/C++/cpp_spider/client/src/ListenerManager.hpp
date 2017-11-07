/*
** ListenerManager.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/ListenerManager.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:31 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:31 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_LISTENERMANAGER_HPP
#define CPP_SPIDER_LISTENERMANAGER_HPP

#include <vector>
#include <memory>
#include <boost/foreach.hpp>
#include "KeyboardListener.hpp"
#include "MouseListener.hpp"

namespace Client {

	class ListenerManager {

	public:
		ListenerManager();

		~ListenerManager();

		bool initialize();

		void run();

	private:

		void createContext(void);

		void destroyContext(void);


		std::vector<std::unique_ptr<IListener>> _listeners;
		bool 									_running;
		HWND 									_windowHandle;
		HINSTANCE 								_moduleHandle;
	};

}


#endif //CPP_SPIDER_LISTENERMANAGER_HPP
