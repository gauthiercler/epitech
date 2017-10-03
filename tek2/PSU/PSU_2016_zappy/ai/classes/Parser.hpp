/*
** Parser.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Parser.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:25:49 2017 Gauthier Cler
** Last update Mon Jun 19 21:25:49 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_PARSER_HPP
#define PSU_2016_ZAPPY_PARSER_HPP

#include				<map>
#include 				<vector>
#include				<list>
#include				<functional>
#include				<memory>
#include				<boost/regex.hpp>
#include				<boost/algorithm/string.hpp>
#include 				"Response.hpp"
#include                                "AResponse.hpp"
#include                                "Inventory.hpp"
#include				"Broadcast.hpp"

namespace 				ai {


  struct				Cell
  {

  public:

    unsigned int			player;
    unsigned int			eggs;
    ai::Inventory			content;


    Cell()
      : player(0), eggs(0)
    {}

    Cell(const Cell &other) :
      player(other.player),
      eggs(other.eggs),
      content(other.content) {
    }

    Cell	&operator=(const Cell &other) {
      player = other.player;
      eggs = other.eggs;
      content = other.content;
      return *this;
    }

  };

  class 				Parser {

    using 				Dictionnary = std::list<std::pair<const std::string, std::function<void(Cell &cell, unsigned int nb)>>>;

    const std::string 			_uselessChar = " \t";
    Dictionnary				_dic;

    /**
     * @brief Check if the character is a useless one (Skip)
     * @param character
     * @return bool
     */

    bool				isUseless(const char character);

    /**
     * Adding a Cell on the view
     * @param view
     * @param in
     * @param comaPos
     */

    bool				addCell(std::vector<ai::Cell> &view, std::string &in, size_t comaPos);

    /**
     * @brief Fill cell of all objects
     * @param str
     * @param cell
     */

    bool				fillCell(std::string str, Cell &cell, char delim);

    /**
     * @brief Transform string to add an object in the Cell struct
     * @param str
     * @param cell
     */

    bool				strToCell(std::string str, Cell &cell, unsigned int nb);

    bool				splitInventoryInfo(std::string str, Cell &cell);






  private:

    std::map<ai::ResponseType, boost::regex>	_syntaxRegexes;
    std::map<ai::ResponseType, std::string>	_serverCommands;

  public:

    Parser();
    ~Parser();

    bool		responseSyntaxMatches(const std::string &response, ResponseType type);

    std::unique_ptr<Response<unsigned int>>		processConnectResponse(const std::string &input);
    std::unique_ptr<Response<std::vector<ai::Cell>>>	processLookResponse(const std::string &input);
    std::unique_ptr<Response<Inventory>>		processInventoryResponse(const std::string &input);
    std::unique_ptr<Response<bool>>			processBooleanResponse(const std::string &input, ResponseType type);
    std::unique_ptr<Response<bool>>			processIncantationResponse(const std::string &input, ResponseType type);
    std::unique_ptr<Response<Broadcast>>		processBroadcastResponse(const std::string &input);

    std::map<ai::ResponseType, std::string>		&getServerCommands(void);

    /**
     * @brief Clean a string
     * @param string
     */

    void		epurStr(std::string &string);

  };

}

inline std::ostream	&operator<<(std::ostream &os, const ai::Cell &cell) {
  os << "[Cell]" << std::endl
    <<	"Player : " << cell.player << std::endl
    <<	"Eggs : " << cell.eggs << std::endl
     << cell.content;
  return (os);
}

#endif //PSU_2016_ZAPPY_PARSER_HPP
