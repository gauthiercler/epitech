//
// Created by ventinc on 1/9/18.
//

#ifndef CPP_RTYPE_COMPONENTTYPE_HPP
#define CPP_RTYPE_COMPONENTTYPE_HPP

#include <cstddef>
#include <set>

namespace ecs {
    using ComponentType = unsigned int;

    // Must be positive ID
    static constexpr const ComponentType InvalidComponentType = 0;

    using ComponentTypeSet = std::set<ComponentType>;
}

#endif //CPP_RTYPE_COMPONENTTYPE_HPP
