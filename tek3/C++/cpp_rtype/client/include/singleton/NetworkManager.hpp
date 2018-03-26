#ifndef CPP_RTYPE_NETWORKMANAGER_HPP
# define CPP_RTYPE_NETWORKMANAGER_HPP

#include <rnetwork/async/IOService.hpp>
#include <ClientChannel.hpp>
#include "Singleton.hpp"
#include <iostream>

namespace rtype {

	class NetworkManager :
		public Singleton<NetworkManager> {
		friend class Singleton<NetworkManager>;

	public:
		~NetworkManager() = default;

		void
		setIOService(std::shared_ptr<rnetwork::async::IOService> IOService)
		{
			_ptr = std::make_shared<rnetwork::ClientChannel>(*IOService);
			_ptr->setGateway(
				[&](std::shared_ptr<rnetwork::ClientChannel> client,
					rnetwork::packet::PacketBase& packet) {
					this->handlePacket(packet);
				});
		}

		std::shared_ptr<rnetwork::ClientChannel>
		getClientChannel()
		{
			return _ptr;
		};

		rnetwork::Router<void(rnetwork::packet::PacketBase&)>&
		getRouter()
		{
			return _router;
		}

		void
		handlePacket(rnetwork::packet::PacketBase& packet)
		{
			if (_router.isRegistered(packet.getOp()))
				_router(packet);
			else
				std::cout << "No route to handle packet with id: "
					<< packet.getOp() << std::endl;
		}

	private:
		NetworkManager() = default;

		std::shared_ptr<rnetwork::ClientChannel> _ptr;
		rnetwork::Router<void(rnetwork::packet::PacketBase&)> _router;
	};
}
#endif /* !CPP_RTYPE_NETWORKMANAGER_HPP*/
