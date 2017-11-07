/*
** Manager.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Manager.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:42:38 2017 Gauthier Cler
** Last update Sun Oct 08 19:42:38 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_MANAGER_HPP
#define CPP_SPIDER_MANAGER_HPP

#include <string>
#include <memory>
#include <vector>
#include <rethinkdb.h>
#include "Collection.hpp"

namespace DB {

  class Manager {
    std::vector<std::shared_ptr<Collection>>	_collections;
    const std::string				_ip;
    const int					_port;
    const std::string				_databaseName;
    std::unique_ptr<RethinkDB::Connection>	_connection;

  public:
    Manager();
    Manager(const std::string &ip, int port, const std::string &databaseName = "test");
    ~Manager();

    void				registerCollection(const std::string &collection);
    std::shared_ptr<Collection>		&getCollection(const std::string &collection);
    std::shared_ptr<Collection>		&operator[](const std::string &collection);
    void				drop();

    private:
    void				initialize();
    bool				databaseExist();
    void				initializeDatabase();
    void				createDatabase();
  };

}

#endif //CPP_SPIDER_MANAGER_HPP
