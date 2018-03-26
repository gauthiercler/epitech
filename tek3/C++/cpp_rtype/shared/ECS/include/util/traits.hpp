//
// traits.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/traits.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 18:43:14 2018 Anthony LECLERC
// Last update mer. janv. 10 18:43:14 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_TRAITS_HPP
#define CPP_RTYPE_TRAITS_HPP

#include <type_traits>

namespace ecs {

  template<typename T>
  using remove_cvref = std::remove_cv_t<std::remove_reference_t<T> >;

}

#endif /* CPP_RTYPE_TRAITS_HPP */
