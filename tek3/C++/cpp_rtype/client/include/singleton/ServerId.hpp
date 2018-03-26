//
// ServerId.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ServerId.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 09:49:21 2018 Anthony LECLERC
// Last update dim. janv. 21 09:49:21 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_SERVERID_HPP
#define CPP_RTYPE_SERVERID_HPP

#include <Entity.hpp>
#include <unordered_map>
#include "Singleton.hpp"

namespace rtype {
	class ServerId : public Singleton<ServerId>
	{
		friend class Singleton<ServerId>;
	public:

		void associateId(ecs::Entity const serverId, ecs::Entity clientId) noexcept;

		ecs::Entity fromServerId(ecs::Entity const id);
		ecs::Entity fromClientId(ecs::Entity const id);

		void remove(ecs::Entity const serverId);

		void clear() noexcept;
	private:
		ServerId() = default;

		std::unordered_map<ecs::Entity, ecs::Entity> _fromServer;
		std::unordered_map<ecs::Entity, ecs::Entity> _fromClient;
	};
}

#endif /* CPP_RTYPE_SERVERID_HPP */
