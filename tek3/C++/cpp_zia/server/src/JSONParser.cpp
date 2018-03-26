//
// Created by valentin on 06/02/18.
//

#include <fstream>
#include <iostream>
#include <BetterConf.hpp>
#include "../include/JSONParser.hpp"

zia::server::JSON
zia::server::JSONParser::parseFromStr(const std::string &data) {
  try {
    return (JSON::parse(data));
  } catch (std::exception &e) {
    std::cerr << "[ERROR] Wrong format in the configuration file" << std::endl;
    std::cerr << e.what() << std::endl;
    return (JSON());
  }
}

zia::server::JSON zia::server::JSONParser::parseFromFile(std::ifstream &file) {
  std::stringstream data;

  data << file.rdbuf();
  return (parseFromStr(data.str()));
}

zia::server::JSONParser &zia::server::JSONParser::Instance() {
  static JSONParser jsonParser;
  return (jsonParser);
}

zia::api::ConfArray
zia::server::JSONParser::translate(const zia::server::JSON &json) {
  zia::api::ConfArray conf;

  for (const auto &j: json) {
    conf.emplace_back();
    conf.back().v = static_cast<std::string>(j);
  }
  return (std::move(conf));
}

zia::api::ConfObject
zia::server::JSONParser::translateToObject(const zia::server::JSON &json) {
    zia::api::ConfObject object;

    for (JSON::const_iterator it = json.begin(); it != json.end(); ++it)
	object[it.key()].v = static_cast<std::string>(it.value());
    return (std::move(object));
}
