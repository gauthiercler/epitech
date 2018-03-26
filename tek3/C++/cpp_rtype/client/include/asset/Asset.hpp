//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_ASSET_HPP
#define CPP_RTYPE_ASSET_HPP

#include <string>
#include "AssetType.hpp"

namespace rtype {
	class Asset {
	public:
		explicit Asset(const std::string &name);
		virtual ~Asset() = default;
		virtual bool load() = 0;

	protected:
		std::string name;
	};
}

#endif //CPP_RTYPE_ASSET_HPP
