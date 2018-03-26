//
// Created by ventinc on 1/16/18.
//

#ifndef CPP_RTYPE_ENGINE_HPP
#define CPP_RTYPE_ENGINE_HPP

#include <singleton/Window.hpp>
#include "client/include/singleton/Context.hpp"

namespace rtype {

	class Engine {
	public:
		Engine() = default;
		~Engine() = default;

		void run();

	private:

		Window _window;
	};
}

#endif //CPP_RTYPE_ENGINE_HPP
