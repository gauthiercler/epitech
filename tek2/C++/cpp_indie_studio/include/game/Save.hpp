/*
** Save.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/game/Save.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Jun 12 15:36:36 2017 Vincent DUSAUTOIR
** Last update Mon Jun 12 15:36:36 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_SAVE_HPP
#define CPP_INDIE_STUDIO_SAVE_HPP

#include <string>

namespace	indie {

  class			Save{
    std::string		_name = ".bombsave";

  public:
    Save();
    ~Save();

    bool		isAvailable();
    void		load();
  };

}

#endif //CPP_INDIE_STUDIO_SAVE_HPP
