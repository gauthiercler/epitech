//
// Created by ventinc on 1/18/18.
//

#include <algorithm>
#include <iostream>
#include "client/include/singleton/Settings.hpp"

void rtype::Settings::setMusicVolume(int volume) {
	this->_musicVolume = volume;
}

void rtype::Settings::setEffectsVolume(int volume) {
	this->_effectsVolume = volume;
}

void rtype::Settings::setKeyboard(const std::string &up,
								  const std::string &down,
								  const std::string &left,
								  const std::string &right,
								  const std::string &fire,
								  const std::string &charge) {
	_inputs.Up = this->getKeyboardKey(up);
	_inputs.Down = this->getKeyboardKey(down);
	_inputs.Left = this->getKeyboardKey(left);
	_inputs.Right = this->getKeyboardKey(right);
	_inputs.Fire = this->getKeyboardKey(fire);
	_inputs.Charge = this->getKeyboardKey(charge);
}

const rtype::ct::RtypeInput &rtype::Settings::getKeyboard() {
	return this->_inputs;
}

sf::Keyboard::Key rtype::Settings::getKeyboardKey(const std::string &key) {
	for (auto &&value : this->_keys) {
		if (value.second == key) {
			return value.first;
		}
	}
	return sf::Keyboard::Unknown;
}

const std::string rtype::Settings::getKeyboardString(sf::Keyboard::Key key) {
	for (auto &&value : this->_keys) {
		if (value.first == key)
			return value.second;
	}
	return "Unknown";
}