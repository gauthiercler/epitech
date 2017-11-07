/*
** Schema.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Schema.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 10:37:50 2017 Gauthier Cler
** Last update Mon Oct 02 10:37:50 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_SCHEMA_HPP
#define CPP_SPIDER_SCHEMA_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/regex.hpp>

namespace DB {

  class Schema {

  public:
    Schema();
    ~Schema() = default;

    void	load(const std::string &name);
    bool	isLoaded() const;
    bool	validate(boost::property_tree::ptree &model);
  private:
    boost::property_tree::ptree	_schema;
    bool			_isLoaded{false};
    std::map<std::string, boost::regex>	_simpleTemplates;
    std::map<std::string, std::function<bool(boost::property_tree::ptree &, boost::property_tree::ptree &)>> _advancedTemplates;

    bool			regexValidation(boost::property_tree::ptree &validation, boost::property_tree::ptree &item);
    bool			objectValidation(boost::property_tree::ptree &validation, boost::property_tree::ptree &item);
    bool			enumValidation(boost::property_tree::ptree &validation, boost::property_tree::ptree &item);
    bool			validation(boost::property_tree::ptree &validation, boost::property_tree::ptree &model);
  };
}

#endif //CPP_SPIDER_SCHEMA_HPP
