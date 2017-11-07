/*
** Collection.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Collection.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:42:02 2017 Gauthier Cler
** Last update Sun Oct 08 19:42:02 2017 Gauthier Cler
*/

#include <iostream>
#include <future>
#include <utility>
#include <boost/thread/future.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser/error.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "Collection.hpp"
#include "Error.hpp"

DB::Collection::Collection(const std::string &name, RethinkDB::Connection &connection, const std::string &dbName) :
  _name(name), _connection(connection), _dbName(dbName) {
  this->initialize();
}

const std::string &DB::Collection::getName() const {
  return this->_name;
}

void DB::Collection::initialize() {
  if (!this->exist())
    this->create();
}

bool DB::Collection::exist() {
  return *RethinkDB::db(this->_dbName).table_list().contains(this->getName()).run(this->_connection).to_datum().get_boolean();
}

void DB::Collection::create() {
  RethinkDB::db(this->_dbName).table_create(this->_name).run(this->_connection);
}

void DB::Collection::insert(DB::Model &model) {
  if (model.validate())
    RethinkDB::db(this->_dbName).table(this->getName()).insert(model.generateRethinkDBModel()).run(this->_connection);
}

void DB::Collection::subscribe(std::function<void (const std::string &result)> callback) {
  boost::async(boost::bind(&DB::Collection::subscribeEvent, this, std::move(callback)));
}

void DB::Collection::subscribeEvent(std::function<void (const std::string &result)> callback) {
  try {
    RethinkDB::Cursor cursor = RethinkDB::db(this->_dbName).table(this->getName()).changes().run(this->_connection);
    for (RethinkDB::Datum& item : cursor)
      callback(item.as_json());
  } catch (RethinkDB::Error &err) {
    std::cout << err.message << std::endl;
  }
}

void DB::Collection::subscribeCallback(const std::string &result) {
  std::cout << result << std::endl;
}

bool DB::Collection::exist(const std::string &json) {
  Model		filter;

  try {
    filter.load(json);
  } catch (std::exception &e) {
    throw CollectionError("An error occured when loading json filter for exist.");
  }

  return this->exist(filter);
}

bool DB::Collection::exist(DB::Model &model) {
  RethinkDB::Cursor cursor = RethinkDB::db(this->_dbName).table(this->getName()).filter(model.generateRethinkDBModel()).count().run(this->_connection);

  return *cursor.to_datum().get_number() >= 1;
}

void DB::Collection::remove(const std::string &id) {
  RethinkDB::db(this->_dbName).table(this->getName()).get(id).delete_().run(this->_connection);
}

