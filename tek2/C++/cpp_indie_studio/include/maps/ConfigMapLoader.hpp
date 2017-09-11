/*
** ConfigMapLoader.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/ConfigMapLoader.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 07:00:52 2017 Anthony LECLERC
** Last update ven. juin 16 07:00:52 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_CONFIGMAPLOADER_HPP
# define CPP_INDIE_STUDIO_CONFIGMAPLOADER_HPP

#include	<irrlicht/path.h>
#include	<vector>
#include	"AJsonParser.hpp"

namespace indie {
  class ConfigMapLoader : public AJsonParser {
  private:
    irr::io::path _folder;
    std::vector<irr::io::path> _filesPath;
  public:
    ConfigMapLoader();

    virtual ~ConfigMapLoader();

    virtual void clear() override;

    virtual void load(std::string const &string) override;

    virtual void save(std::string const &string) override;

    std::vector<irr::io::path> const& getMapFiles() const;
    irr::io::path const& getMapsDirectory() const;
  };
}

#endif //CPP_INDIE_STUDIO_CONFIGMAPLOADER_HPP
