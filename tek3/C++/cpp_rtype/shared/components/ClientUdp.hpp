//
// ClientUdp.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ClientUdp.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 17 03:59:36 2018 Anthony LECLERC
// Last update mer. janv. 17 03:59:36 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_CLIENTUDP_HPP
#define CPP_RTYPE_CLIENTUDP_HPP

#include <rnetwork/udp/Client.hpp>

namespace rtype {
	namespace ct {
		struct ClientUdp {
			std::shared_ptr<rnetwork::udp::Client> client;
		};
	}
}

#endif /* CPP_RTYPE_CLIENTUDP_HPP */
