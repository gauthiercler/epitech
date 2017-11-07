/*
** Model.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Model.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 10:38:11 2017 Gauthier Cler
** Last update Mon Oct 02 10:38:11 2017 Gauthier Cler
*/

#include <boost/algorithm/string.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>

#include "Model.hpp"
#include "Error.hpp"


RethinkDB::Object DB::Model::generateRethinkDBModel() {
  return this->addElements(_tree);
}

void DB::Model::load(const std::string &jsonString) {
  std::stringstream stream;

  stream << jsonString;
  try {
    boost::property_tree::read_json(stream, _tree);
  } catch (boost::property_tree::json_parser::json_parser_error &e) {
    throw DB::ModelError("An error occurred when loading json model (" + std::string(e.what()) + ")");
  }
}

RethinkDB::Object DB::Model::addElements(boost::property_tree::ptree &tree) {
  RethinkDB::Object result;
  BOOST_FOREACH(boost::property_tree::ptree::value_type &item, tree) {
	  if (item.second.size() > 1)
	    result.insert({item.first.data(), this->addElements(item.second)});
	  else
	    result.insert({item.first.data(), item.second.data()});
	}
  return result;
}

void DB::Model::displayModel(boost::property_tree::ptree &tree, size_t depth){
  if (depth == 1)
    std::cout << '{' << std::endl;
  BOOST_FOREACH(boost::property_tree::ptree::value_type &item, tree) {
	  std::string padding = std::string(depth, ' ');
	  if (item.second.size() > 1) {
	    std::cout << padding << item.first.data() << ": [" << std::endl;
	    this->displayModel(item.second, depth + 7);
	    std::cout << padding << "]" << std::endl;
	  } else {
	    if (std::string(item.first).length()) {
	      std::cout << padding << item.first.data() << ": " << item.second.data()
			<< std::endl;
	    } else {
	      std::cout << padding << item.second.data() << std::endl;
	    }
	  }
	}
  if (depth == 1)
    std::cout << '}' << std::endl;
}

void DB::Model::dump() {
  this->displayModel(_tree, 1);
}

DB::Model::Model(const std::string &_name) : _name(_name) {
  this->initialize();
}

void DB::Model::initialize() {
  this->registerSchema("server/Models/" + boost::algorithm::to_lower_copy(_name) + ".json");
}

void DB::Model::registerSchema(const std::string &name) {
  try {
    this->_schema.load(name);
  } catch(DB::ModelError &e) {
    std::cerr << e.what() << std::endl;
  }
}

bool DB::Model::validate() {
  return !_schema.isLoaded() || _schema.validate(_tree);
}

std::string DB::Model::get(const std::string &key) {
  try {
    return this->_tree.get<std::string>(key);
  } catch (std::exception &e) {
    throw ModelError("Can't find key " + key);
  }
}

void DB::Model::add(const std::string &key, const std::string &value) {
  try {
    this->_tree.put(key, value);
  } catch (std::exception &e) {
    throw ModelError("Can't add key \"" + key + "\" with value \"" + value + "\".");
  }
}

