//
// util.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/util.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  jeu. janv. 18 17:16:59 2018 Anthony LECLERC
// Last update jeu. janv. 18 17:16:59 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_UTIL_HPP
#define CPP_RTYPE_UTIL_HPP

#include <cstddef>

namespace rtype {
	namespace util {

		/// For type hash<Enum> in unordered_map.
		/// Necessary for g++ versions < 6.1
		struct EnumClassHash {

			template<typename T>
			std::size_t operator()(T t) const
			{
				return static_cast<std::size_t>(t);
			}
		};
	}
}


#endif /* CPP_RTYPE_UTIL_HPP */
