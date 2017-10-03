/*
** OptionHandler.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/OptionHandler.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 26 11:05:44 2017 Anas Buyumad
** Last update Mon Jun 26 11:05:44 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_OPTIONHANDLER_HPP
#define PSU_2016_ZAPPY_OPTIONHANDLER_HPP

#include <iostream>
#include "boost/algorithm/string/replace.hpp"
#include "boost/program_options.hpp"

class OptionHandler {

public:

  OptionHandler(int argumentCount, const char *argumentValues[]);
  ~OptionHandler();

  const std::string	&getTeamName(void) const;
  const std::string	&getPort(void) const;
  const std::string	&getHostName(void) const;
  const std::string	&getProgramName(void) const;
  bool			isConform(void) const;

  void			displayHelpMessage(void);
  void			dumpConfiguration(void) const;

  void			setSpotsRemaining(unsigned long nb);
  void			setMapSize(std::pair<unsigned int, unsigned int>);

  unsigned long		getSpotsRemaining() const;
  const std::pair<unsigned int, unsigned int>	&getMapSize() const;

private:

  boost::program_options::options_description	_descriptor;
  boost::program_options::variables_map		_retriever;

  bool			_conform;

  std::string		_team;
  std::string		_port;
  std::string		_host;
  unsigned long		_spotsRemaining;
  std::pair<unsigned int, unsigned int>	_mapSize;
  std::string		_programName;

};


#endif //PSU_2016_ZAPPY_OPTIONHANDLER_HPP
