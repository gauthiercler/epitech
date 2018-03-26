//
// htonll.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/htonll.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  sam. janv. 20 06:10:06 2018 Anthony LECLERC
// Last update sam. janv. 20 06:10:06 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_HTONLL_HPP
#define CPP_RTYPE_HTONLL_HPP

#include <algorithm>

namespace rnetwork {

	namespace detail {
		static bool isLittleEndian()
		{
			static constexpr const short int number = 0x1;
			return (reinterpret_cast<char const *>(&number)[0] == 1);
		}
	}

	template <typename T>
    T htonll(T value) noexcept
    {
		if (detail::isLittleEndian())
		{
			char* ptr = reinterpret_cast<char*>(&value);
			std::reverse (ptr, ptr + sizeof(T));
		}
		return value;
    }

    template<typename T>
    T ntohll(T value) noexcept
    {
        return htonll(value);
    }
}

#endif /* CPP_RTYPE_HTONLL_HPP */
