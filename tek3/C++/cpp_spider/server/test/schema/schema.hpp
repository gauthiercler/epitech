/*
** Utils.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/Utils.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 21:56:16 2017 Gauthier Cler
** Last update Mon Oct 02 21:56:16 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_UTILS_HPP
# define CPP_SPIDER_UTILS_HPP

#define _PREFIX std::string("server/test/schema/")

#include <fstream>

static std::string readFile(const std::string &name) {
  std::ifstream ifs(name);
  return std::string((std::istreambuf_iterator<char>(ifs) ),
		     (std::istreambuf_iterator<char>()));
}

static bool generateSchemaTest(const std::string &schema,
			       const std::string &test) {
  DB::Model model;
  model.registerSchema(schema);
  model.load(readFile(test));
  return model.validate();
}

#endif /* !CPP_SPIDER_UTILS_HPP*/
