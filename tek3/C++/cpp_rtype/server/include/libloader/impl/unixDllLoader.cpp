//
// unixDllLoader.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/unixDllLoader.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 17 15:52:19 2018 Anthony LECLERC
// Last update mer. janv. 17 15:52:19 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_UNIXDLLLOADER_HPP
#define CPP_RTYPE_UNIXDLLLOADER_HPP

#include <string>
#include <dlfcn.h>
#include "ImplDllLoader.hpp"

/// Linux specific header for dynamic library loader.

namespace rtype {
	namespace module {

		const detail::Handle detail::InvalidHandle { nullptr };
		const detail::Sym  detail::InvalidSym { nullptr };
		namespace detail {

			Handle ImplDllLoader::loadLibrary(std::string const& name)
			{
				return dlopen(name.c_str(), RTLD_NOW);
			}

			Sym ImplDllLoader::loadSymbol(Handle h, std::string const& name)
			{
				if (h == InvalidHandle)
					return InvalidSym;
				return dlsym(h, name.c_str());
			}

			void ImplDllLoader::closeLibrary(detail::Handle h)
			{
				if (h != InvalidHandle)
					dlclose(h);
			}
		}
	}
}

#endif /* CPP_RTYPE_UNIXDLLLOADER_HPP */
