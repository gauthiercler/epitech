//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_CONFIGMANAGER_HPP
#define CPP_RTYPE_CONFIGMANAGER_HPP

#include <string>
#include <pp/conf.hpp>
#include <fstream>
#include "ModuleManager.hpp"
#include "BetterConf.hpp"
#include "JSONParser.hpp"

namespace zia::server {

    constexpr char DefaultConfigFile[] = "zia.conf";

    class ConfigManager {

	std::string 				_configFileName {DefaultConfigFile};
	std::ifstream				_file;
	BetterConf				_conf;

    public:

	bool isAlive() const;

	bool setConfigFileName(const std::string &name);
	bool loadConfiguration();
	void loadDefaultConfig();

	BetterConf &getConfiguration();

    };

}


#endif //CPP_RTYPE_CONFIGMANAGER_HPP
