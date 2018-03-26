#ifndef CPP_RTYPE_MUSIC_HPP
#define CPP_RTYPE_MUSIC_HPP

#include <SFML/Audio/Music.hpp>
#include "Asset.hpp"

namespace rtype {
  namespace asset {
	class Music : public Asset {
	public:
	  explicit Music(const std::string &name);

	  virtual bool load(const std::string &name);
	  sf::Music &get();

	private:
	  sf::Music music;
	};
  }
}

#endif /* CPP_RTYPE_MUSIC_HPP */
