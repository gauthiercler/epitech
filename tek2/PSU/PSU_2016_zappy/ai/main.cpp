/*
** main.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/main.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:23:46 2017 Gauthier Cler
** Last update Mon Jun 19 21:23:46 2017 Gauthier Cler
*/

#include <cstdlib>
#include <memory>
#include <classes/IOStreamHandler.hpp>
#include <classes/Engine.hpp>

bool		ai::running = true;

int		main(int argc, const char *argv[])
{
  ai::Engine	engine(argc, argv);

  if (!engine.getOptionHandler().isConform()) {
    return EXIT_SUCCESS;
  }
  engine.getOptionHandler().dumpConfiguration();

  try {
    engine.connect();
    engine.run();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Fatal error occurred. Exiting" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}