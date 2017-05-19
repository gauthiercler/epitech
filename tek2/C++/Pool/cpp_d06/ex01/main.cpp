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
#include <iomanip>

int		main()
{

  double	temp;
  std::string 	type;
  double	result;

  std::cin >> temp >> type;

  if (type.compare("Celsius") && type.compare("Fahrenheit"))
    return 84;

  if (!type.compare("Fahrenheit")){
    result = 5.0 / 9.0 * (temp - 32);
    type = "Celsius";
  }
  else{
    result = (temp / (5.0 / 9.0)) + 32;
    type = "Fahrenheit";
  }
  std::cout.precision(3);
  std::cout << std::right << std::setw(16) << std::fixed << result << std::right  << std::setw(16) << type << std::endl;
  return 0;
}

