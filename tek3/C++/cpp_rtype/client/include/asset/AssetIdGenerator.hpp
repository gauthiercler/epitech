//
// Created by ventinc on 1/15/18.
//

#ifndef CPP_RTYPE_ASSETIDGENERATOR_HPP
#define CPP_RTYPE_ASSETIDGENERATOR_HPP

#include "component/IdGenerator.hpp"
#include "AssetType.hpp"

namespace rtype {
	struct asset_trait {
		using Id = AssetType ;
		static constexpr const Id invalid_id = InvalidAssetType;
	};


	template<typename T>
	AssetType assetType() {
		return ecs::Generator_type_id<T, asset_trait>::ctype();
	}

	template<typename T>
	using AssetTypeId = ecs::Generator_type_id<T, asset_trait>;

};


#endif //CPP_RTYPE_ASSETIDGENERATOR_HPP
