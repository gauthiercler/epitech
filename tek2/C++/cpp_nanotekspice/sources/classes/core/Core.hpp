/*
** Core.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/core/Core.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Feb 15 00:15:29 2017 Gauthier Cler
** Last update Wed Feb 15 00:15:29 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_CORE_H
#define CPP_NANOTEKSPICE_CORE_H

#include <string>
#include <sources/interfaces/IParser.hpp>
#include <sources/interfaces/IComponent.hpp>

namespace nts {

  template<typename T> nts::IComponent	*createInstance(const std::string &value){ return new T(value); };

  class Core {
  public:
    Core(std::string fileName);
    ~Core();
    void					handleArgs(char **args, int nbArgs);
    void	run();

    typedef std::vector<std::pair<std::string, void (nts::Core::*)()>> 	simulationMatches;

  private:
    IParser									*_parser;
    std::vector<nts::IComponent*>						_components;
    nts::t_ast_node								*_tree;
    std::map<std::string, nts::IComponent *(*)(const std::string &value)>	_componentsAssociativeMap;
    simulationMatches								_simulationMatches;

    void 					createGraph();
    void					checkAllLinked();
    void					deleteTree(nts::t_ast_node *node);
    void					initMap();
    void					initSimulation();
    void					exit();
    void					display();
    void					simulate();
    void					loop();
    void					dump();
    IComponent					*getComponentByName(const std::string &name);
    static bool					sortComponentNames(IComponent *first, IComponent *second);
    nts::t_ast_node				*getTreeSection(const std::string &name);
    void					checkDefinedValues();
    void					updateValue(std::string command);
  };

}

#endif

