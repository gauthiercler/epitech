//
// Created by ventinc on 1/16/18.
//

#ifndef CPP_RTYPE_ICONTEXT_HPP
#define CPP_RTYPE_ICONTEXT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "client/include/singleton/Context.hpp"

namespace rtype {
	class AContext {
	public:
		explicit AContext(sf::RenderWindow &window);
		virtual ~AContext() = default;

		virtual void run(sf::Time &time) = 0;

	protected:
		sf::RenderWindow &_window;
	};
}

#endif //CPP_RTYPE_ICONTEXT_HPP
