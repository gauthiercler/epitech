/*
** main.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/libs/main.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:59:49 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:59:49 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "Core.hpp"
#include "Error.hpp"
#include "games/common/Scores.hpp"

int main(int ac, char **av)
{
  if (ac > 1)
  {
    try {
      arcade::Core	core(av[1]);
      core.run();
    } catch (arcade::Error &e) {
      std::cerr << e.what() << std::endl;
    }
  } else
    std::cerr << "You must provide the dynamic library in first parameter" << std::endl;
}
