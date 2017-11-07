/*
** Model.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Model.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 10:38:06 2017 Gauthier Cler
** Last update Mon Oct 02 10:38:06 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_MODEL_HPP
#define CPP_SPIDER_MODEL_HPP

#include <boost/property_tree/ptree.hpp>
#include <rethinkdb.h>
#include "Schema.hpp"

namespace DB {

  class Model {

  public:
    explicit Model(const std::string &name);
    Model() = default;
    ~Model() = default;

    void load(const std::string &jsonString);
    void dump();
    RethinkDB::Object generateRethinkDBModel();
    bool validate();
    void registerSchema(const std::string &name);
    std::string		get(const std::string &key);
    void		add(const std::string &key, const std::string &value);

  private:
    void displayModel(boost::property_tree::ptree &tree, size_t depth);
    RethinkDB::Object addElements(boost::property_tree::ptree &tree);
    void initialize();

    boost::property_tree::ptree _tree;
    DB::Schema			_schema;
    const std::string 		_name;
  };
}

#endif //CPP_SPIDER_MODEL_HPP
