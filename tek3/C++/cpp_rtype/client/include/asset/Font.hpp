//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_FONT_HPP
#define CPP_RTYPE_FONT_HPP

#include <string>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include "Asset.hpp"

namespace rtype {
	namespace asset {
		class Font : public Asset {
		public:
			explicit Font(const std::string &name);

			virtual bool load();
			sf::Font &get();

			private:
			sf::Font font;
		};
	}
}

#endif //CPP_RTYPE_FONT_HPP
