//
// ComponentIdGenerator.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ComponentIdGenerator.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  lun. janv. 15 14:00:49 2018 Anthony LECLERC
// Last update lun. janv. 15 14:00:49 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_COMPONENTIDGENERATOR_HPP
#define CPP_RTYPE_COMPONENTIDGENERATOR_HPP

#include <component/ComponentType.hpp>
#include <component/IdGenerator.hpp>
#include "Export.hpp"

namespace ecs {

	struct RTECS_API component_trait {
		using Id = ComponentType;
		static constexpr const Id invalid_id = InvalidComponentType;
	};


	template<typename T>
	ComponentType componentType() {
		return Generator_type_id<T, component_trait>::ctype();
	}

	template<typename T>
	using ComponentTypeId = Generator_type_id<T, component_trait>;


}

#endif /* CPP_RTYPE_COMPONENTIDGENERATOR_HPP */
