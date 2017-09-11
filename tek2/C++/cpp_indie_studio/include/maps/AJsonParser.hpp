/*
** AJsonParser.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/AJsonParser.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 07:09:47 2017 Anthony LECLERC
** Last update ven. juin 16 07:09:47 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_AJSONPARSER_HPP
#define CPP_INDIE_STUDIO_AJSONPARSER_HPP


#include <rapidjson/document.h>
#include "IJsonLoader.hpp"
#include "Errors.hpp"

namespace indie {
  class AJsonParser : IJsonLoader {
  protected:
    rapidjson::Document _doc;

    void parse() const;

    void parseMember(char const *s) const;

    template<typename Predicate>
    Parser::ObjectType const& getMember(Parser::ObjectType const& v, Predicate p) const
    {
      if (!p (v))
	throw ParserInvalidMember("Invalid member attribute");
      return (v);
    }

    template<typename It, typename Predicate>
    Parser::ObjectType const& getMember(It const& root,
					char const *s, Predicate p) const
    {
      auto itr = root.FindMember(s);
      if (itr == root.MemberEnd())
	throw ParserMissingMember(std::string("Missing member attribute: ") + s);
      return getMember(itr->value, p);
    }

  public:
    virtual void open(std::string const &string) override;
  };
}


#endif //CPP_INDIE_STUDIO_AJSONPARSER_HPP
