//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_BOUNDINGBOX_HPP
#define CPP_RTYPE_BOUNDINGBOX_HPP

namespace rtype {
	namespace ct {
		/// @brief Collide.
		struct BoundingBox {
			unsigned int width;
			unsigned int height;
			BoundingBox(unsigned int width, unsigned int height) : width(width), height(height) {};
			BoundingBox() : width(0), height(0) {};
		};
	}
}

#endif //CPP_RTYPE_BOUNDINGBOX_HPP
