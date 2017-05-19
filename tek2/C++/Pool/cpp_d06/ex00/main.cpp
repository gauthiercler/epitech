/*
** main.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex00/main.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 09:55:27 2017 Gauthier CLER
** Last update Mon Jan 09 09:55:27 2017 Gauthier CLER
*/

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
  int	i = 1;
  bool	returnValue = false;
  std::string name = av[0];
  std::ifstream file;

  if (ac == 1){
    std::cout << name.substr(2) << ": Usage: " << av[0] << " file [...]" << std::endl;
    return 84;
  }
  while (i < ac)
  {
    file.open(av[i]);
    if (file.is_open()){
      std::cout << file.rdbuf();
      file.close();
    }else{
      std::cerr << name.substr(2) << ": " << av[i] << ": No such file or directory" << std::endl;
      returnValue = true;
    }
    i += 1;
  }
  if (returnValue)
    return 84;
  return 0;
}

