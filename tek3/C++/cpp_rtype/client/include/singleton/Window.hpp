//
// Created by ventinc on 1/10/18.
//

#ifndef CPP_RTYPE_WINDOW_HPP
#define CPP_RTYPE_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

# ifndef WWIDTH
#  define WWIDTH (1600)
# endif

# ifndef WHEIGHT
#  define WHEIGHT (900)
# endif

namespace rtype {
	class Window {
	public:
		explicit Window();
		~Window();
		sf::RenderWindow &get();

	private:
		sf::RenderWindow _window;
	};
}

#endif //CPP_RTYPE_WINDOW_HPP
