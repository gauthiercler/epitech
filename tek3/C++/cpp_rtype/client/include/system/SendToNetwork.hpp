//
// SendToNetwork.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/SendToNetwork.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 20 06:32:58 2018 Anthony LECLERC
// Last update sam. janv. 20 06:32:58 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_SENDTONETWORK_HPP
#define CPP_RTYPE_SENDTONETWORK_HPP

#include <system/System.hpp>
#include <ClientChannel.hpp>

namespace rtype {
	class SendToNetwork : public ecs::System {
	public:
		SendToNetwork(std::shared_ptr<rnetwork::ClientChannel> const& channel);
		void process(ecs::Manager& mgr, float elapsed_time);
	private:
		std::shared_ptr<rnetwork::ClientChannel> _client;
	};
}


#endif //CPP_RTYPE_SENDTONETWORK_HPP
