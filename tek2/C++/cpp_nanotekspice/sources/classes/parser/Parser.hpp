/*
** Parser.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/parser/Parser.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Feb 03 19:35:05 2017 Gauthier Cler
** Last update Fri Feb 03 19:35:05 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP


#include <sources/interfaces/IParser.hpp>
#include <map>
#include <regex>

namespace nts {



  enum class ParserSectionType : int {
    NONE = 0,
    LINKS,
    CHIPSETS,
  };


  class Parser : public nts::IParser {
  public:
    Parser(const std::string &fileName);
    virtual ~Parser();
    virtual void feed(std::string const& input);
    virtual void parseTree(nts::t_ast_node& root);
    virtual nts::t_ast_node *createTree();
    typedef std::vector<std::pair<std::regex, void (nts::Parser::*)(std::string input, nts::t_ast_node *node)>> regexGrammar;
    typedef std::vector<t_ast_node *>::iterator nodeIterator;

  private:

    std::vector<std::string>	_validComponents;
    regexGrammar 				_lexerGrammar;
    std::string					_inputString;
    nts::ParserSectionType			_section;

    nts::ParserSectionType getSection() const;
    void		setSection(nts::ParserSectionType type);
    std::string		getInputString() const;
    void		initGrammar();
    std::string		getStringFromFile(std::string fileName) const;
    void		setNodeType(nts::t_ast_node *node, nts::ASTNodeType type);
    void		lexLine(std::string line, nts::t_ast_node *tree);
    void		lexSection(std::string input, nts::t_ast_node *node);
    void		lexIgnore(std::string input, nts::t_ast_node *node);
    void		lexLink(std::string input, nts::t_ast_node *node);
    void		lexComponent(std::string input, nts::t_ast_node *node);
    void		checkDuplicateLinks(t_ast_node *node, std::string lexeme, std::string value) const;
    void		checkDuplicateComponents(t_ast_node *node, std::string lexeme) const;
    void		componentExist(t_ast_node *node, std::string name);
    nts::t_ast_node	*getTreeSection(t_ast_node *tree, std::string name) const;
    void		displayTree(t_ast_node *node) const;
    nts::t_ast_node	*createNode(std::vector<t_ast_node*>*children, std::string lexeme, std::string value, nts::ASTNodeType type);
    void		parseComponents(nts::t_ast_node &root);
    void		parseLinks(nts::t_ast_node &root);
  };
}



#endif //CPP_NANOTEKSPICE_PARSER_HPP
