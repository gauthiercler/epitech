/*
** IParser.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/interfaces/IParser.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:18:42 2017 Anas Buyumad
** Last update Fri Jan 27 20:18:42 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_IPARSER_HPP
# define CPP_NANOTEKSPICE_IPARSER_HPP

# include <string>
# include <vector>

namespace nts
{
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING
  };

  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) { }
    std::string lexeme;
    ASTNodeType type;
    std::string value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser
  {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser() {};
  };
}

#endif //CPP_NANOTEKSPICE_IPARSER_HPP
