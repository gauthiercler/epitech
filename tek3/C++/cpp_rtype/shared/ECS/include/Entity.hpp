//
// Created by ventinc on 1/9/18.
//

#ifndef CPP_RTYPE_ENTITY_HPP
#define CPP_RTYPE_ENTITY_HPP

#include <cstddef>

namespace ecs {
    typedef size_t Entity;

    // Entity must be positive ID
    static const Entity InvalidEntity = 0;
}

#endif //CPP_RTYPE_ENTITY_HPP
