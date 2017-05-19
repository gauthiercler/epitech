/*
** Parser.cpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/parser/Parser.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Feb 03 19:37:41 2017 Gauthier Cler
** Last update Fri Feb 03 19:37:41 2017 Gauthier Cler
*/

#include <fstream>
#include <sources/classes/errors/Error.hpp>
#include <sstream>
#include <iostream>
#include <regex>
#include <sources/classes/misc/Misc.hpp>
#include "Parser.hpp"

nts::Parser::Parser(const std::string &fileName) : _inputString(std::string("")){
  this->initGrammar();
  this->_validComponents = {"input", "clock", "true", "false", "output", "4001",
			    "4008", "4011", "4013", "4030", "4069", "4071", "4081"};
  this->feed(this->getStringFromFile(fileName));
}

nts::Parser::~Parser() {
}

void nts::Parser::feed(std::string const &input) {
  this->_inputString += input;
}

void nts::Parser::parseTree(nts::t_ast_node &root) {
  parseComponents(root);
  parseLinks(root);
}

void nts::Parser::parseComponents(nts::t_ast_node &root) {
  nts::t_ast_node	*components;
  if (root.children){
    components = this->getTreeSection(&root, "chipsets");
    if (!components->children)
      components->children = new std::vector<t_ast_node*>;
    for (std::vector<nts::s_ast_node*>::iterator it = components->children->begin(); it != components->children->end(); ++it)
    {
      if (std::find(this->_validComponents.begin(), this->_validComponents.end(), (*it)->lexeme) == this->_validComponents.end())
	throw nts::Error("Invalid Element Type " + (*it)->lexeme);
    }
  }
}

void nts::Parser::parseLinks(nts::t_ast_node &root) {
  nts::t_ast_node	*links, *components;

  if (root.children){
    links = this->getTreeSection(&root, "links");
    if (!links->children)
      links->children = new std::vector<t_ast_node*>;
    components = this->getTreeSection(&root, "chipsets");
    for (nodeIterator it = links->children->begin(); it != links->children->end(); ++it)
    {
      this->componentExist(components, (*it)->children->at(0)->lexeme);
      this->componentExist(components, (*it)->children->at(1)->lexeme);
    }
  }
}

nts::t_ast_node *nts::Parser::createTree() {
  nts::t_ast_node	*tree;
  std::string		currentLine;
  std::istringstream	lines(this->getInputString());

  tree = new nts::t_ast_node(new std::vector<nts::s_ast_node*>);
  this->setNodeType(tree, nts::ASTNodeType::DEFAULT);
  while (std::getline(lines, currentLine))
    this->lexLine(currentLine, tree);
  this->setSection(nts::ParserSectionType::NONE);
  return tree;
}

std::string nts::Parser::getStringFromFile(std::string fileName) const{

  std::ifstream		file;
  std::ostringstream	fileContent;

  file.open(fileName);
  if (!file.is_open())
    throw nts::Error("Can't open file " + fileName);

  fileContent << file.rdbuf();
  file.close();

  return fileContent.str();
}

void nts::Parser::setNodeType(nts::t_ast_node *node, nts::ASTNodeType type) {
  node->type = type;
}

void nts::Parser::lexLine(std::string line, nts::t_ast_node *tree) {
  std::cmatch	matchCompare;

  if (line.find("#") != 0)
    line = line.substr(0, line.find("#"));
  line = nts::Misc::trim(line);
  for (regexGrammar::iterator it = this->_lexerGrammar.begin(); it != this->_lexerGrammar.end(); ++it)
  {
    if (std::regex_match(line.c_str(), matchCompare, it->first, std::regex_constants::match_default)){
      (this->*(it->second))(line, tree);
      return ;
    }
  }
  throw nts::Error("Line " + line + " seems invalid. Please verify your syntax.");
}

void nts::Parser::initGrammar() {
  this->_lexerGrammar.push_back({std::regex("^(#(.+)?$|^\\s*$)"), &nts::Parser::lexIgnore});
  this->_lexerGrammar.push_back({std::regex("^(.chipsets:|.links:)$"), &nts::Parser::lexSection});
  this->_lexerGrammar.push_back({std::regex("^[^ :\\t]+:[^ :\\t]+[ \t]+[^ :\\t]+:[^ :\\t]+$"), &nts::Parser::lexLink});
  this->_lexerGrammar.push_back({std::regex("^\\S+([ \t]+\\S+)$"), &nts::Parser::lexComponent});
}

void nts::Parser::lexSection(std::string input, nts::t_ast_node *root) {
  t_ast_node	*newNode;

  input = input.substr(1, input.size() - 2);
  this->setSection((input == "links") ? nts::ParserSectionType::LINKS : nts::ParserSectionType::CHIPSETS);
  try { this->getTreeSection(root, input); } catch (nts::Error) {};
  newNode = new s_ast_node(new std::vector<t_ast_node*>);
  newNode->lexeme = ".";
  newNode->value = input;
  this->setNodeType(newNode, ASTNodeType::SECTION);
  root->children->push_back(newNode);
}


void nts::Parser::lexLink(std::string input, nts::t_ast_node *node) {

  nts::t_ast_node	*section, *newNode, *firstNode, *secondNode;
  std::string		leftElem(input.substr(0, input.find_first_of(" \t")));
  std::string		rightElem(input.substr(input.find_last_of(" \t") + 1));

  if (this->getSection() != nts::ParserSectionType::LINKS)
    throw nts::Error("Field " + input + " is misplaced");
  if (!(section = getTreeSection(node, "links")))
    throw nts::Error("Field " + input + " is misplaced");

  this->checkDuplicateLinks(section, leftElem, rightElem);

  firstNode = this->createNode(new std::vector<t_ast_node*>, leftElem.substr(0, leftElem.find(":")), leftElem.substr(leftElem.find(":") + 1), nts::ASTNodeType::LINK_END);
  secondNode = this->createNode(new std::vector<t_ast_node*>, rightElem.substr(0, rightElem.find(":")), rightElem.substr(rightElem.find(":") + 1), nts::ASTNodeType::LINK_END);

  newNode = this->createNode(new std::vector<nts::t_ast_node*>, leftElem, rightElem, nts::ASTNodeType::LINK);
  newNode->children->push_back(firstNode);
  newNode->children->push_back(secondNode);
  section->children->push_back(newNode);
}

void nts::Parser::lexComponent(std::string input, nts::t_ast_node *node) {

  nts::t_ast_node	*section;
  nts::t_ast_node	*newNode;
  std::string		type(input.substr(0, input.find_first_of(" \t")));
  std::string		name(input.substr(input.find_last_of(" \t") + 1));

  if (this->getSection() != nts::ParserSectionType::CHIPSETS)
    throw nts::Error("Field " + input + " is misplaced3");
  try {
    section = getTreeSection(node, "chipsets");
  }catch (nts::Error){
    throw nts::Error("Field " + input + " is misplaced4");
  }
  this->checkDuplicateComponents(section, name);
  newNode = this->createNode(new std::vector<t_ast_node*>, type, name, nts::ASTNodeType::COMPONENT);
  section->children->push_back(newNode);
}

void nts::Parser::lexIgnore(std::string input, nts::t_ast_node *node) {
  (void)node;
  (void)input;
}

std::string nts::Parser::getInputString() const{
  return this->_inputString;
}

nts::ParserSectionType nts::Parser::getSection() const {
  return this->_section;
}

void nts::Parser::setSection(nts::ParserSectionType type) {
  this->_section = type;
}

nts::t_ast_node *nts::Parser::getTreeSection(t_ast_node *tree, std::string name) const {
  if (tree){
    for (nodeIterator it = tree->children->begin(); it != tree->children->end(); ++it)
    {
      if ((*it)->type == nts::ASTNodeType::SECTION && (*it)->value == name)
	return (*it);
    }
  }
  throw nts::Error("Invalid Tree, missing branch " + name);
}

void nts::Parser::checkDuplicateLinks(nts::t_ast_node *node, std::string lexeme, std::string value) const {
  if (!node->children)
    return ;
  for (nodeIterator it = node->children->begin(); it != node->children->end(); ++it)
  {
    if ((*it)->lexeme == lexeme && (*it)->value == value)
      throw nts::Error("Duplicate Element");
  }
}

void nts::Parser::checkDuplicateComponents(nts::t_ast_node *node, std::string value) const {
  if (!node->children)
    return ;
  for (nodeIterator it = node->children->begin(); it != node->children->end(); ++it)
  {
    if ((*it)->value == value)
      throw nts::Error("Duplicate Element");
  }
}

void nts::Parser::displayTree(nts::t_ast_node *node) const {
  if (node->type == nts::ASTNodeType::DEFAULT){
    std::cout << "Type  " << (int)node->type << " || ";
    std::cout << "Lexem  " << node->lexeme << " || ";
    std::cout << "Value  " << node->value << std::endl;
  }
  if (node->children) {
    for (nodeIterator it = node->children->begin(); it != node->children->end(); ++it)
    {
      std::cout << "Type  " << (int)(*it)->type << " || ";
      std::cout << "Lexem  " << (*it)->lexeme << " || ";
      std::cout << "Value  " << (*it)->value << std::endl;
      if ((*it)->children != NULL)
	this->displayTree((*it));
    }
  }
}

nts::t_ast_node *nts::Parser::createNode(std::vector<t_ast_node *> *children, std::string lexeme,
					 std::string value, nts::ASTNodeType type) {

  nts::t_ast_node *newNode = new nts::t_ast_node(children);

  newNode->lexeme = lexeme;
  newNode->value = value;
  newNode->type = type;
  return newNode;
}

void nts::Parser::componentExist(nts::t_ast_node *node, std::string name) {
  for (nodeIterator it = node->children->begin(); it != node->children->end(); ++it)
  {
    if ((*it)->value == name)
      return ;
  }
  throw nts::Error("Component " + name + " does not exist.");
}
