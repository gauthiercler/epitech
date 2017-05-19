/*
** ToyStory.cpp for cpp_d13 in /home/gogo/rendu/tek2/cpp_d13/ex06/ToyStory.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 14:58:13 2017 Gauthier CLER
** Last update Mon Jan 16 14:58:13 2017 Gauthier CLER
*/


#include <sstream>
#include <fstream>
#include <iostream>
#include "ToyStory.h"

void ToyStory::tellMeAStory(const char *fileName, Toy &a,
			    bool (Toy::*func1)(const std::string &), Toy &b,
			    bool (Toy::*func2)(const std::string &)) {
  std::ifstream file(fileName);
  std::string line;
  unsigned int which = 0;

  if (file.fail()) {
    std::cout << "Bad Story" << std::endl;
    return;
  }
  std::cout << a.getAscii() << std::endl;
  std::cout << b.getAscii() << std::endl;

  while (std::getline(file, line)) {
    if (line.find("picture:") != std::string::npos) {
      std::string pictureName = line.substr(line.find_last_of(":") + 1);
      if (which % 2 == 0) {
	if (!a.setAscii(pictureName)) {
	  std::cout << a.getLastError().getWhere() << ": "
		    << a.getLastError().getWhat() << std::endl;
	  return;
	}else
	  std::cout << a.getAscii() << std::endl;
      } else {
	if (!b.setAscii(pictureName)) {
	  std::cout << b.getLastError().getWhere() << ": "
		    << b.getLastError().getWhat() << std::endl;
	  return;
	} else
	  std::cout << b.getAscii() << std::endl;
      }
    } else {
      if (which % 2 == 0) {
	if (!(a.*func1)(line)) {
	  std::cout << a.getLastError().getWhere() << ": "
		    << a.getLastError().getWhat() << std::endl;
	  return;
	}
      }else{
      if (!(b.*func2)(line)) {
	  std::cout << b.getLastError().getWhere() << ": "
		    << b.getLastError().getWhat() << std::endl;
	  return;
	}
      }
      which += 1;
    }
  }
}