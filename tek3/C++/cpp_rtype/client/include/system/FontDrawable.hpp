//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_FONTDRAWABLE_HPP
#define CPP_RTYPE_FONTDRAWABLE_HPP

#include <asset/AssetsLoader.hpp>
#include "system/System.hpp"

namespace rtype {
	class FontDrawable : public ecs::System {
	public:
		explicit FontDrawable(AssetsLoader &loader);
		void process(ecs::Manager& mgr, float elapsedTime) override;
	private:
		AssetsLoader &loader;
	};
}

#endif //CPP_RTYPE_FONTDRAWABLE_HPP
