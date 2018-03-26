//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_CORE_HPP
#define CPP_RTYPE_CORE_HPP

#include "ConfigManager.hpp"
#include "ModuleManager.hpp"
#include "ModuleLoader.hpp"

namespace zia::server {

    using Args = char **;

    class Core {

	ConfigManager	_configManager;
	ModuleManager	_moduleManager;
	ModuleLoader	_moduleLoader;

	void initPipeline();
	void initConfigPath();
	void initConfigModule();
	bool configFile(const std::string &filename);
        void processRequest(zia::api::Net::Raw raw, zia::api::NetInfo netInfo); // Api fault :'(

    public:

	Core();
	~Core() = default;

	bool config(Args args);
	bool config(const std::string &filename);
	void defaultConfig();
	void run();

    };

}

#endif //CPP_RTYPE_CORE_HPP
