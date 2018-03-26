//
// Created by ventinc on 1/12/18.
//

#include <iostream>
#include "asset/Font.hpp"

rtype::asset::Font::Font(const std::string &name) : Asset(name) {
}

bool rtype::asset::Font::load() {
	return this->font.loadFromFile(this->name);
}

sf::Font &rtype::asset::Font::get() {
	return this->font;
}

