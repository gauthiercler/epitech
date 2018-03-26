//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_IMPLDLLLOADER_HPP
#define CPP_RTYPE_IMPLDLLLOADER_HPP

#include <memory>
#include "types.hpp"

namespace zia {
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
