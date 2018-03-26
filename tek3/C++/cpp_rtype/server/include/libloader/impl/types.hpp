//
// types.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/types.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 17 16:41:40 2018 Anthony LECLERC
// Last update mer. janv. 17 16:41:40 2018 Anthony LECLERC
//

#pragma once

#ifdef WIN32
namespace rtype {
	namespace module {
		namespace detail {
			using Handle = void *;
			using Sym = void *;
		}
	}

	namespace fs {
		namespace detail {
			using Folder = void *;
			using File = void *;
		}
	}
}

#else // Linux API
#include <dirent.h>

namespace rtype {
	/// libdl
	namespace module {
		namespace detail {
			/// @brief Return type of dlopen.
			using Handle = void *;

			/// @brief Return type of dlsym.
			using Sym = void *;
		}
	}

	/// Linux Filesystem API
	namespace fs {
		namespace detail {
			/// @brief Return type of opendir.
			using Folder = DIR *;

			/// @brief Return type of readdir.
			using File = struct dirent *;
		}
	}
}
#endif
