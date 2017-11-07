/*
** Manager.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/database/Manager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:42:24 2017 Gauthier Cler
** Last update Sun Oct 08 19:42:24 2017 Gauthier Cler
*/

#include <algorithm>
#include <iostream>
#include "Manager.hpp"
#include "Error.hpp"

DB::Manager::Manager() : _ip("http://teledor.fr"), _port(28015), _databaseName("spider") {
  this->initialize();
}

DB::Manager::Manager(const std::string &ip, int port, const std::string &databaseName) : _ip(ip), _port(port), _databaseName(databaseName) {
  this->initialize();
}

DB::Manager::~Manager() {

}

void DB::Manager::registerCollection(const std::string &collection) {
  auto foundCollection = std::find_if(this->_collections.begin(), this->_collections.end(),
				      [collection](const std::shared_ptr<Collection>& coll)
				      {
					return coll->getName() == collection;
				      });

  if (foundCollection == this->_collections.end())
    this->_collections.push_back(std::move(std::make_shared<Collection>(collection, *this->_connection, this->_databaseName)));
}

std::shared_ptr<DB::Collection> &DB::Manager::getCollection(const std::string &collection) {
  auto foundCollection = std::find_if(this->_collections.begin(), this->_collections.end(),
				      [collection](const std::shared_ptr<Collection>& coll)
				      {
					return coll->getName() == collection;
				      });

  if (foundCollection == this->_collections.end())
    throw DB::Error("This collection does not exist");
  return *foundCollection;
}

std::shared_ptr<DB::Collection> &DB::Manager::operator[](const std::string &collection) {
  return this->getCollection(collection);
}

void DB::Manager::initialize() {
  try {
    this->_connection = RethinkDB::connect(this->_ip, this->_port);
  } catch (const RethinkDB::Error &e) {
    throw DB::ManagerError("Can't connect to the database " + this->_ip + ":" + std::to_string(this->_port));
  }
  this->initializeDatabase();
}

bool DB::Manager::databaseExist() {
  RethinkDB::Cursor databases = RethinkDB::db_list().run(*this->_connection);
  for (auto &database : databases) {
    if (*database.get_string() == this->_databaseName)
      return true;
  }
  return false;
}

void DB::Manager::createDatabase() {
  RethinkDB::db_create(this->_databaseName).run(*this->_connection);
}

void DB::Manager::initializeDatabase() {
  if (!this->databaseExist())
    this->createDatabase();
}

void DB::Manager::drop() {
  RethinkDB::db_drop(this->_databaseName).run(*this->_connection);
}

