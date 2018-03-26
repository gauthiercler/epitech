//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_UNIXDLLLOADER_HPP
#define CPP_RTYPE_UNIXDLLLOADER_HPP

#include <string>
#include <dlfcn.h>
#include "DLLoader/ImplDllLoader.hpp"

/// Linux specific header for dynamic library loader.

namespace zia {
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
