//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_DLLOADERFACTORY_HPP
#define CPP_RTYPE_DLLOADERFACTORY_HPP

#include <memory>
#include "DLInstanceLoader.hpp"

namespace zia {
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
