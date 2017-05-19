#include <iostream>
#include "Env/Env.hpp"
#include "Core/Core.hpp"

int main(int argc, char **argv, char **arge) {

  Env::setEnv(arge);
  Config::GraphicMode mode = Config::GraphicMode ::GRAPHICS;
  int index = 1;

  while (index < argc)
  {
    if (std::string(argv[index]) == Config::termModeFlag)
      mode = Config::GraphicMode::TERM;
    index++;
  }

  Core core(mode);

  core.run();
  return 0;
}