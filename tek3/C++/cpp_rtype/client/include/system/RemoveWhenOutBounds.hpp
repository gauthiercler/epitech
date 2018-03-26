//
// RemoveWhenOutBounds.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/RemoveWhenOutBounds.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 08:54:13 2018 Anthony LECLERC
// Last update dim. janv. 21 08:54:13 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_REMOVEWHENOUTBOUNDS_HPP
#define CPP_RTYPE_REMOVEWHENOUTBOUNDS_HPP

#include <BoundingBox.hpp>
#include <system/System.hpp>

namespace rtype {
	class RemoveWhenOutBounds : public ecs::System {
	public:
		RemoveWhenOutBounds(ct::BoundingBox const& worldBox);

		void setBounds(ct::BoundingBox const& worldBox);

		virtual void
		process(ecs::Manager& mgr, float elapsedTime) override;

	private:

		ct::BoundingBox _world;
	};
}


#endif //CPP_RTYPE_REMOVEWHENOUTBOUNDS_HPP
