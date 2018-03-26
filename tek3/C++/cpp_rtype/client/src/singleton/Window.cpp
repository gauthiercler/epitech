//
// Created by ventinc on 1/10/18.
//

#include <singleton/Window.hpp>

rtype::Window::Window() : _window(sf::VideoMode(WWIDTH, WHEIGHT), "R-Type") {

}

sf::RenderWindow &rtype::Window::get() {
	return _window;
}

rtype::Window::~Window() {
}

