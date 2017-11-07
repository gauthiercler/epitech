/*
** Error.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Error.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:42:16 2017 Gauthier Cler
** Last update Sun Oct 08 19:42:16 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_ERROR_HPP
#define CPP_SPIDER_ERROR_HPP

#include <exception>
#include <string>
#include <utility>

namespace DB {
  class Error : public std::runtime_error {
  public:
    explicit Error(const char *message) : std::runtime_error(message) {};
    ~Error() noexcept override = default;
  };

  class ModelError : public Error {
  public:
    explicit ModelError(std::string const &message) : Error(std::string("Database Model : " + message).c_str()) {};
    ~ModelError() noexcept override = default;
  };

  class ManagerError : public Error {
  public:
    explicit ManagerError(std::string const &message) : Error(std::string("Database Manager : " + message).c_str()) {};
    ~ManagerError() noexcept override = default;
  };

  class CollectionError : public Error {
  public:
    explicit CollectionError(std::string const &message) : Error(std::string("Database Collection : " + message).c_str()) {};
    ~CollectionError() noexcept override = default;
  };
}

#endif //CPP_SPIDER_ERROR_HPP
