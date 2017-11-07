/*
** Collection.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Collection.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:42:10 2017 Gauthier Cler
** Last update Sun Oct 08 19:42:10 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_COLLECTION_HPP
#define CPP_SPIDER_COLLECTION_HPP

#include <string>
#include <rethinkdb.h>
#include "Model.hpp"

namespace DB {

  class Collection {
    const std::string		_name;
    RethinkDB::Connection	&_connection;
    const std::string		_dbName;
    boost::property_tree::ptree	_tree;

  public:
    Collection(const std::string &name, RethinkDB::Connection &connection, const std::string &dbName);
    ~Collection() = default;

    const std::string		&getName() const;
    void			insert(DB::Model &model);
    void			subscribe(std::function<void (const std::string &result)> callback);
    void			subscribeCallback(const std::string &result);
    bool			exist(const std::string &json);
    bool			exist(DB::Model &model);
    void			remove(const std::string &json);

  private:
    void			initialize();
    bool			exist();
    void			create();
    void			subscribeEvent(std::function<void (const std::string &result)> callback);
  };
}

#endif //CPP_SPIDER_COLLECTION_HPP
