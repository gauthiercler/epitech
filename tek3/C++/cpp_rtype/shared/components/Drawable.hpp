//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_DRAWABLE_HPP
#define CPP_RTYPE_DRAWABLE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <memory>

namespace rtype {
	namespace ct {
		struct Drawable  {

			std::shared_ptr<sf::Drawable> content;

			Drawable () = default;
		};
	}
}

#endif //CPP_RTYPE_DRAWABLE_HPP
