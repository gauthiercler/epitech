 //
// ImplDllLoader.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/ImplDllLoader.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 17 16:44:24 2018 Anthony LECLERC
// Last update mer. janv. 17 16:44:24 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_IMPLDLLLOADER_HPP
#define CPP_RTYPE_IMPLDLLLOADER_HPP

#include <memory>
#include "types.hpp"

namespace rtype {
	namespace module {

		namespace detail {

			extern const Handle InvalidHandle;
			extern const Handle InvalidSym;

			class ImplDllLoader {
			public:

				Handle loadLibrary(std::string const& name);

				detail::Sym loadSymbol(Handle, std::string const& name);

				void closeLibrary(detail::Handle );
			};
		}
	}
}

#endif /* CPP_RTYPE_IMPLDLLLOADER_HPP */
