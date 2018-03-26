
#include <client/include/asset/Music.hpp>

rtype::asset::Music::Music(std::string const &name) :
	Asset(name) {

}

bool rtype::asset::Music::load(const std::string &name) {
	return music.openFromFile(name);
}

sf::Music &rtype::asset::Music::get() {
	return music;
}
