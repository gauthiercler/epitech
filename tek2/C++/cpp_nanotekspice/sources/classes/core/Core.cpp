/*
** Core.cpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/core/Core.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Feb 15 00:15:25 2017 Gauthier Cler
** Last update Wed Feb 15 00:15:25 2017 Gauthier Cler
*/

#include <sources/classes/parser/Parser.hpp>
#include <sources/classes/components/False.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/INPUT.hpp>
#include <sources/classes/components/CLOCK.hpp>
#include <sources/classes/components/OUTPUT.hpp>
#include <sources/classes/components/C2716.hpp>
#include <sources/classes/components/C4801.hpp>
#include <sources/classes/components/C4017.hpp>
#include <sources/classes/components/C4013.hpp>
#include <sources/classes/components/C4011.hpp>
#include <sources/classes/components/C4008.hpp>
#include <sources/classes/components/C4001.hpp>
#include <sources/classes/components/C4040.hpp>
#include <sources/classes/components/C4069.hpp>
#include <sources/classes/components/C4071.hpp>
#include <sources/classes/components/C4081.hpp>
#include <sources/classes/components/C4094.hpp>
#include <sources/classes/components/C4514.hpp>
#include <sources/classes/components/C4030.hpp>
#include <iostream>
#include <sources/classes/misc/Misc.hpp>
#include <sources/classes/errors/Error.hpp>
#include "Core.hpp"

nts::Core::Core(std::string fileName) {
  this->_parser = new nts::Parser(fileName);
  this->_tree = this->_parser->createTree();
  this->_parser->parseTree(*this->_tree);
  this->initMap();
  this->initSimulation();
  this->createGraph();
  this->checkAllLinked();
}

nts::Core::~Core() {
  this->deleteTree(this->_tree);
  delete this->_tree;
  delete this->_parser;
  nts::Misc::deleteVector(&this->_components);
}

void nts::Core::createGraph() {
  std::vector<nts::t_ast_node *>	*chipsets = this->getTreeSection("chipsets")->children;
  std::vector<nts::t_ast_node *>	*links = this->getTreeSection("links")->children;
  IComponent				*currentComponent;
  IComponent				*componentToLink;

  for (nts::Parser::nodeIterator it = chipsets->begin(); it != chipsets->end(); ++it){
    this->_components.push_back(this->_componentsAssociativeMap[(*it)->lexeme]((*it)->value));
  }
  std::sort(this->_components.begin(), this->_components.end(), this->sortComponentNames);
  for(nts::Parser::nodeIterator it = links->begin(); it != links->end(); ++it)
  {
    currentComponent = this->getComponentByName((*it)->children->at(0)->lexeme);
    componentToLink = this->getComponentByName((*it)->children->at(1)->lexeme);
    currentComponent->SetLink(std::stoul((*it)->children->at(0)->value.c_str()), *componentToLink, std::stoul((*it)->children->at(1)->value.c_str()));
  }
}

void nts::Core::checkAllLinked() {
  for (std::vector<nts::IComponent*>::iterator it = this->_components.begin(); it != this->_components.end(); ++it)
  {
    if (static_cast<AComponent*>((*it))->getType() == nts::AComponent::ComponentType::OUTPUT){
      if (!static_cast<AComponent*>((*it))->getPinAt(1)->isLinked())
	throw nts::Error("Pin of component " + static_cast<AComponent*>((*it))->getName() + " is not linked");
    }
  }
}


void nts::Core::deleteTree(nts::t_ast_node *node) {
  if (node && node->children) {
    for (std::vector<nts::t_ast_node*>::iterator it = node->children->begin();
	 it != node->children->end(); ++it)
    {
      if ((*it)->children)
	this->deleteTree(*it);
    }
    nts::Misc::deleteVector(node->children);
    delete node->children;
  }
}

void nts::Core::exit() {
}

void nts::Core::display() {
  for (std::vector<nts::IComponent*>::iterator it = this->_components.begin(); it != this->_components.end(); ++it)
  {
    if (static_cast<AComponent*>((*it))->getType() == nts::AComponent::OUTPUT){
      nts::Tristate value = static_cast<AComponent*>((*it))->getPinAt(1)->getValue();
      std::cout << static_cast<AComponent*>((*it))->getName() << "=" << ((value == nts::Tristate::UNDEFINED) ? "U" : std::to_string(value)) << std::endl;
    }
  }
}

void nts::Core::simulate() {
  for (std::vector<nts::IComponent *>::iterator it = this->_components.begin(); it != this->_components.end(); ++it) {
    if (static_cast<nts::AComponent *>((*it))->getType() == nts::AComponent::OUTPUT) {
      (*it)->Compute(1);
    }
  }
  for (std::vector<nts::IComponent *>::iterator it = this->_components.begin(); it != this->_components.end(); ++it) {
    if (static_cast<nts::AComponent *>((*it))->getType() ==
	nts::AComponent::CLOCK) {
      static_cast<CLOCK *>((*it))->InvertClock();
    }
  }

}

void nts::Core::loop() {
  do{
    this->simulate();
  }while (true);
}

void nts::Core::dump() {
  for (std::vector<nts::IComponent*>::iterator it = this->_components.begin(); it != this->_components.end(); ++it)
    (*it)->Dump();
}

void nts::Core::initMap() {
  this->_componentsAssociativeMap.insert({"input", &createInstance<INPUT>});
  this->_componentsAssociativeMap.insert({"clock", &createInstance<CLOCK>});
  this->_componentsAssociativeMap.insert({"true", &createInstance<True>});
  this->_componentsAssociativeMap.insert({"false", &createInstance<False>});
  this->_componentsAssociativeMap.insert({"output", &createInstance<OUTPUT>});
  this->_componentsAssociativeMap.insert({"4001", &createInstance<C4001>});
  this->_componentsAssociativeMap.insert({"4008", &createInstance<C4008>});
  this->_componentsAssociativeMap.insert({"4011", &createInstance<C4011>});
  this->_componentsAssociativeMap.insert({"4013", &createInstance<C4013>});
  this->_componentsAssociativeMap.insert({"4030", &createInstance<C4030>});
  this->_componentsAssociativeMap.insert({"4069", &createInstance<C4069>});
  this->_componentsAssociativeMap.insert({"4071", &createInstance<C4071>});
  this->_componentsAssociativeMap.insert({"4081", &createInstance<C4081>});
}

void nts::Core::run() {
  std::string	currentCommand;
  bool		validCommand;
  std::cmatch	matchCompare;

  this->simulate();
  this->display();
  std::cout << "> ";
  while (std::getline(std::cin, currentCommand)){
    currentCommand = nts::Misc::trim(currentCommand);
    if (currentCommand.length() > 0) {
      validCommand = false;
      if (std::regex_match(currentCommand.c_str(), matchCompare, std::regex("^\\S+=[0-1]$"), std::regex_constants::match_default)) {
	this->updateValue(currentCommand);
	validCommand = true;
      }
      else {
	for (simulationMatches::iterator it = this->_simulationMatches.begin();
	     it != this->_simulationMatches.end(); ++it) {
	  if (it->first == currentCommand) {
	    (this->*(it->second))();
	    validCommand = true;
	    break;
	  }
	}
      }
      if (!validCommand)
	std::cerr << currentCommand << ": command not found" << std::endl;
      if (currentCommand == "exit")
	break;
    }
    std::cout << "> ";
  }
}

void nts::Core::initSimulation() {
  this->_simulationMatches.push_back({"exit", &nts::Core::exit});
  this->_simulationMatches.push_back({"display", &nts::Core::display});
  this->_simulationMatches.push_back({"simulate", &nts::Core::simulate});
  this->_simulationMatches.push_back({"loop", &nts::Core::loop});
  this->_simulationMatches.push_back({"dump", &nts::Core::dump});
}

nts::IComponent *nts::Core::getComponentByName(const std::string &name) {
  for (std::vector<IComponent *>::iterator it = this->_components.begin(); it != this->_components.end(); ++it)
  {
    if (static_cast<AComponent *>((*it))->getName() == name)
      return (*it);
  }
  return NULL;
}

bool nts::Core::sortComponentNames(nts::IComponent *first,
				   nts::IComponent *second) {
  return static_cast<AComponent*>(first)->getName() < static_cast<AComponent*>(second)->getName();
}

void nts::Core::handleArgs(char **args, int nbArgs) {
  nts::IComponent	*component;
  std::string		currentArg;
  std::string		componentName;
  nts::Tristate 	valueEnum;

  for (int it = 0; it < nbArgs; it ++)
  {
    currentArg = std::string(args[it]);
    componentName = currentArg.substr(0, currentArg.find("="));
    currentArg = currentArg.substr(currentArg.find("=") + 1).c_str();
    if (currentArg != "0" && currentArg != "1")
      throw nts::Error("Invalid value for component " + componentName);
    valueEnum = static_cast<nts::Tristate >(std::atoi(currentArg.c_str()));
    if (!(component = this->getComponentByName(componentName)))
      throw nts::Error("Unknown component");
    if (static_cast<AComponent*>(component)->getType() != nts::AComponent::ComponentType::INPUT
      && static_cast<AComponent*>(component)->getType() != nts::AComponent::ComponentType::CLOCK)
      throw nts::Error("Invalid component type");
    static_cast<AComponent*>(component)->getPinAt(1)->setValue(valueEnum);
  }
  this->checkDefinedValues();
}

nts::t_ast_node *nts::Core::getTreeSection(const std::string &name) {
  for (std::vector<t_ast_node*>::iterator it = this->_tree->children->begin(); it != this->_tree->children->end(); ++it)
  {
    if ((*it)->type == nts::ASTNodeType::SECTION && (*it)->value == name)
      return (*it);
  }
  return NULL;
}

void nts::Core::checkDefinedValues() {
  for (std::vector<nts::IComponent*>::iterator it = this->_components.begin(); it != this->_components.end(); ++it)
  {
    if (static_cast<AComponent*>((*it))->getType() == nts::AComponent::ComponentType::INPUT
      || static_cast<AComponent*>((*it))->getType() == nts::AComponent::ComponentType::CLOCK){
      if (static_cast<AComponent*>((*it))->getPinAt(1)->getValue() == nts::Tristate::UNDEFINED)
	throw nts::Error("Component " + static_cast<AComponent*>((*it))->getName() + " has an undefined value");
    }
  }
}

void nts::Core::updateValue(std::string command) {
  std::string	componentName = command.substr(0, command.find_first_of("="));
  IComponent	*component = this->getComponentByName(componentName);
  nts::Tristate value;

  if (!component){
    std::cerr << "Component " << componentName << " does not exist" << std::endl;
    return ;
  }
  if (static_cast<AComponent*>(component)->getType() != nts::AComponent::ComponentType::INPUT){
    std::cerr << "You can't change the value of this type of component" << std::endl;
    return ;
  }
  value = static_cast<nts::Tristate >(std::atoi(command.substr(command.find_last_of("=") + 1).c_str()));
  static_cast<AComponent*>(component)->getPinAt(1)->setValue(value);
}

