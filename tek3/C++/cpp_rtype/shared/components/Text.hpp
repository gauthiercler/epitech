//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_TEXT_HPP
#define CPP_RTYPE_TEXT_HPP

#include <string>
#include <SFML/Graphics/Color.hpp>

namespace rtype {
	namespace ct {
		struct Text {

			unsigned int font = 0;
			sf::Color color = sf::Color(255,255,255);
			unsigned int size = 18;
			std::string content = "default text";

			Text () = default;

			explicit Text(unsigned int font, const std::string &content) : font(font), content(content) {}
			explicit Text(const std::string &content) : content(content) {}
		};
	}
}

#endif //CPP_RTYPE_TEXT_HPP
