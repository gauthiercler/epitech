#include <sources/interfaces/IParser.hpp>
#include <sources/classes/parser/Parser.hpp>
#include <sources/classes/errors/Error.hpp>
#include <iostream>
#include <sources/classes/components/gates/AND.hpp>
#include <sources/classes/components/C4081.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/core/Core.hpp>

int		main(int ac, char **av)
{

  try{
    if (ac < 2)
      throw nts::Error("Invalid Number of parameters");
    nts::Core	Core(av[1]);
    Core.handleArgs(av + 2, ac - 2);
    Core.run();
  }catch(nts::Error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}