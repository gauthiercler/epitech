//
// Created by valentin on 08/02/18.
//

#pragma once

#ifdef WIN32
namespace zia {
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

namespace zia {
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
