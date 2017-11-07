/*
** Schema.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Schema.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 10:38:00 2017 Gauthier Cler
** Last update Mon Oct 02 10:38:03 2017 Gauthier Cler
*/

#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <boost/foreach.hpp>
#include "Schema.hpp"
#include "Error.hpp"

void DB::Schema::load(const std::string &name) {
  try {
    boost::property_tree::read_json(name, _schema);
    _isLoaded = true;
  } catch (boost::property_tree::json_parser::json_parser_error &e) {
    throw DB::ModelError("An error occurred when loading json model (" + std::string(e.what()) + ")");
  }
}

bool DB::Schema::isLoaded() const {
  return _isLoaded;
}

bool DB::Schema::validate(boost::property_tree::ptree &model) {
  return this->validation(this->_schema, model);
}

DB::Schema::Schema() {
  this->_simpleTemplates = {
    { "number", boost::regex("[0-9]+") },
    { "string", boost::regex(".*") }
  };

  this->_advancedTemplates = {
    { "regex", std::bind(&DB::Schema::regexValidation, this, std::placeholders::_1, std::placeholders::_2) },
    { "object", std::bind(&DB::Schema::objectValidation, this, std::placeholders::_1, std::placeholders::_2) },
    { "enum", std::bind(&DB::Schema::enumValidation, this, std::placeholders::_1, std::placeholders::_2) }
  };
}

bool DB::Schema::regexValidation(boost::property_tree::ptree &validation, boost::property_tree::ptree &item) {
  try {
    auto value = validation.get_optional<std::string>("value");
    if (value) {
      if (!boost::regex_match(item.data(), boost::regex(*value)))
	return false;
    }
  } catch (std::exception &e) {
    return false;
  }
  return true;
}

bool DB::Schema::objectValidation(boost::property_tree::ptree &validation,
				  boost::property_tree::ptree &item) {
  try {
    return this->validation(validation.get_child("items"), item);
  } catch (std::exception &e) {
    return false;
  }
}

bool DB::Schema::enumValidation(boost::property_tree::ptree &validation,
				boost::property_tree::ptree &item) {
  try {
    for (auto &value : validation.get_child("values"))
    {
      if (item.data() == value.second.get_value<std::string>())
	return true;
    }
  } catch (std::exception &e){
    return false;
  }
  return false;
}

bool DB::Schema::validation(boost::property_tree::ptree &validation,
			    boost::property_tree::ptree &model) {
  if (validation.size() != model.size())
    return false;
  BOOST_FOREACH(boost::property_tree::ptree::value_type &item, validation)
	{
	  auto value = model.get_optional<std::string>(item.first);
	  if (!value)
	    return false;

	  auto regexp = this->_simpleTemplates.find(item.second.get<std::string>("type"));
	  if (regexp != this->_simpleTemplates.end()) {
	    if (!boost::regex_match(*value, regexp->second) || (*value).empty())
	      return false;
	  }

	  auto advanced = this->_advancedTemplates.find(item.second.get<std::string>("type"));
	  if (advanced != this->_advancedTemplates.end()) {
	    if (!advanced->second(item.second, model.get_child(item.first)))
	      return false;
	  }
	}
  return true;
}
