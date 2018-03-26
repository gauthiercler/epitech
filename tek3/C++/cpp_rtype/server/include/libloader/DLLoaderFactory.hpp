//
// DLLoaderFactory.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/DLLoaderFactory.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  jeu. janv. 18 13:02:21 2018 Anthony LECLERC
// Last update jeu. janv. 18 13:02:21 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_DLLOADERFACTORY_HPP
#define CPP_RTYPE_DLLOADERFACTORY_HPP

#include <memory>

#include "DLInstanceLoader.hpp"

namespace rtype {
	namespace module {
		struct make {


			template<typename TInterface, typename ...Args>
			static std::unique_ptr<DLInstanceLoader<TInterface> >
			newInstanceLoader(std::string const& lib,
						   std::string const& entry,
						   std::string const& dtor,
						   Args&& ...args)
			{
				return std::make_unique<DLInstanceLoader<TInterface > >
					(lib.c_str(), entry.c_str(), dtor.c_str(), std::forward<Args>(args)...);
			};

			template<typename TInterface>
			static std::unique_ptr<DLInstanceLoader<TInterface> >
			newFunctionLoader(std::string const& lib)
			{
				return std::make_unique<DLInstanceLoader<TInterface > >
					(lib.c_str());
			}
		};
	}
}


#endif //CPP_RTYPE_DLLOADERFACTORY_HPP
