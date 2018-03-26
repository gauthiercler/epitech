//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_LOADER_HPP
#define CPP_RTYPE_LOADER_HPP

#include <string>
#include <client/include/singleton/Singleton.hpp>
#include "AssetsStore.hpp"
#include "AssetIdGenerator.hpp"

namespace rtype {
	class AssetsLoader : public Singleton<AssetsLoader> {
		friend class Singleton<AssetsLoader>;
	public:
		~AssetsLoader() = default;

		template <typename A>
		bool createAssetsStore() {
			static_assert(std::is_base_of<Asset, A>::value, "A must derived from the Asset Class");
			auto atype = AssetTypeId<A>::make();
			if (atype == InvalidAssetType)
				return false;
			return this->assetsStores.insert(std::make_pair(atype, IAssetsStore::Ptr(new AssetsStore<A>()))).second;
		}

		template <typename A>
		AssetsStore<A>	&getAssetsStore() {
			static_assert(std::is_base_of<Asset, A>::value, "A must derived from the Asset Class");
			auto atype = assetType<A>();
			if (atype == InvalidAssetType)
				throw std::runtime_error("The AssetsStore " + std::to_string(atype) + " does not exist");
			auto iAssetStore = this->assetsStores.find(atype);
			if (this->assetsStores.end() == iAssetStore)
				throw std::runtime_error("The AssetsStore does not exist");
			return reinterpret_cast<AssetsStore<A>&>(*(iAssetStore->second));
		}

		template <typename A>
		A &get(unsigned int id) {
			auto &store = this->getAssetsStore<A>();
			if (store.has(id))
				return store.get(id);
			else
				throw std::runtime_error("Can't get id [" + std::to_string(id) + "] in Asset Store " + std::to_string(1));
		}

		template <typename A>
		void load(unsigned int id, const std::string name) {
			static_assert(std::is_base_of<Asset, A>::value, "A must derived from the Asset Class");
			auto atype = assetType<A>();
			if (atype == InvalidAssetType)
				throw std::runtime_error("The AssetsStore " + std::to_string(atype) + " does not exist");
			A as(name);
			if (!as.load()) {
				throw std::runtime_error("Can't load " + name + " of class [" + std::to_string(atype) + "]");
			}
			this->addAsset<A>(id, std::move(as));
		}

	private:
		AssetsLoader() = default;
		template <typename A>
		bool				addAsset(unsigned int id, A &&component) {
			static_assert(std::is_base_of<Asset, A>::value, "A must derived from the Asset Class");
			return this->getAssetsStore<A>().add(id, std::forward<A>(component));
		}

		std::unordered_map<AssetType, IAssetsStore::Ptr> assetsStores;
	};
}

#endif //CPP_RTYPE_LOADER_HPP
