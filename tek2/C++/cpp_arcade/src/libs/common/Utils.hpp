/*
** Utils.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/common/Utils.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 03 16:32:17 2017 Vincent DUSAUTOIR
** Last update Mon Apr 03 16:32:17 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_UTILS_HPP
#define CPP_ARCADE_UTILS_HPP

#include <vector>
#include <string>

namespace arcade {

  namespace Utils {
    std::string trim(const std::string &sentence);
    std::string removeSpaces(const std::string &sentence);
    std::vector<std::string> explode(const std::string &sentence, char delim);
    std::vector<std::string> scanDirectory(const std::string &path);
  };

};

#endif //CPP_ARCADE_UTILS_HPP
