/*
** main.cpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/sources/main.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Apr 10 00:43:23 2017 Anas Buyumad
** Last update Mon Apr 10 00:43:23 2017 Anas Buyumad
*/

#include	<iostream>
#include 	<Reception.hpp>
#include 	<mutex>
#include 	<Mutex.hpp>
#include 	<CondVar.hpp>
#include	<Thread.hpp>
#include	<ThreadPool.hpp>
#include	<CommandManager.hpp>
#include	<Utils.hpp>
#include <XorCypher.hpp>
#include <CaesarCypher.hpp>
#include	"File.hpp"

// 06 12 63 74 58
// 06 12 63 74 66

int		main(int ac, char *av[])
{
  int		capacity;

  //std::cout << "Size of struct : " << sizeof(plazza::Data) << std::endl;
//  return (0);
  if (ac != 2) {
    std::cerr << "Invalid Number of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    capacity = std::stoi(std::string(av[1]));
    if (capacity <= 0) {
      std::cerr << "Office capacity cannot be negative" << std::endl;
      return EXIT_FAILURE;
    }
  } catch (std::logic_error &e) {
    std::cerr << e.what() << ": Argument is not a number" << std::endl;
    return EXIT_FAILURE;
  }
  plazza::Reception reception(static_cast<unsigned int>(capacity));

  reception.run(ac, av);

//  plazza::Worker	worker;

//  worker.performJob("sources/main.cpp", Information::PHONE_NUMBER);
  /*plazza::File file;
  plazza::CaesarCypher cypher;

  file.load("sources/main.cpp");
  std::string buffer = file.getBuffer();
  cypher >> buffer >> buffer >> buffer >> buffer >> buffer >> buffer;
  std::cout << buffer;*/
  return (0);
}

// vincent.dusautoir@epitech.eu
// 06 12 63 74 58
// 127.0.0.1