//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_ASSETSSTORE_HPP
#define CPP_RTYPE_ASSETSSTORE_HPP

#include <memory>
#include <unordered_map>
#include "Asset.hpp"

namespace rtype {

class IAssetsStore {
public:
	using Ptr = std::unique_ptr<IAssetsStore>;
};

template <typename A>
class AssetsStore : public IAssetsStore {
	static_assert(std::is_base_of<Asset, A>::value, "A must be derived from the Asset class");

public:
	AssetsStore() = default;
	~AssetsStore() = default;

	inline bool add(unsigned int id, A &&asset) {
		return this->store.insert(std::make_pair(id, std::move(asset))).second;
	}

	inline bool add(unsigned int id, A const& component) {
		return this->store.insert(std::make_pair(id, component)).second;
	}

	inline bool	remove(unsigned int id) {
		return (0 < this->store.erase(id));
	}

	inline bool	has(unsigned int id) {
		return (this->store.end() != this->store.find(id));
	}

	inline A	&get(unsigned int id) {
		return this->store.at(id);
	}

private:
	std::unordered_map<unsigned int, A> store;
//	static const AssetType type = A::Type;
};
}

#endif //CPP_RTYPE_ASSETSSTORE_HPP
