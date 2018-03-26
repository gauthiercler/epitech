//
// Created by valentin on 06/02/18.
//

#include "../include/ConfigManager.hpp"
#include "../include/JSONParser.hpp"

bool zia::server::ConfigManager::setConfigFileName(const std::string &name) {
    _configFileName = name;
    _file = std::ifstream(name);
    return (_file.is_open());
}

bool zia::server::ConfigManager::loadConfiguration() {
    auto json = JSONParser::Instance().parseFromFile(_file);

    for (JSON::iterator it = json.begin(); it != json.end(); ++it) {
	try {
	    if (it.value().is_string())
		_conf.addValue(it.key(), it.value());
	    else if (it.value().is_array())
		_conf.addValueArry(it.key(), JSONParser::Instance().translate(
		    it.value()));
	    else
		_conf.addValueObject(it.key(),
				     JSONParser::Instance().translateToObject(
					 it.value()));
	} catch (std::exception &e) {
	    std::cerr << "[WARNING] " << it.key() << " is badly formated, try to fix : " << it.value() << std::endl;
	    std::cerr << "[WARNING] End the custom configuration" << std::endl;
	}
    }
    return (!json.empty());
}

bool zia::server::ConfigManager::isAlive() const {
    return (_file.is_open());
}

zia::server::BetterConf &
zia::server::ConfigManager::getConfiguration() {
    return (_conf);
}

void zia::server::ConfigManager::loadDefaultConfig() {
    zia::api::ConfObject object;

    _conf.addValue(CONFIG_PORT, DEFAULT_CONFIG_PORT);
    _conf.addValue(CONFIG_SSL_PORT, DEFAULT_CONFIG_SSL_PORT);
#ifdef WIN32
    _conf.addValue(CONFIG_NETWORK, DEFAULT_CONFIG_NETWORK_WINDOWS);
#else
    _conf.addValue(CONFIG_NETWORK, DEFAULT_CONFIG_NETWORK_UNIX);
#endif
    //TODO Set default modules
    _conf.addValue(CONFIG_MODULE, DEFAULT_CONFIG_MODULE);
    _conf.addValue(CONFIG_PATH, DEFAULT_CONFIG_PATH);
    _conf.addValue(CONFIG_NB_WORKERS, DEFAULT_CONFIG_NB_WORKERS);
    _conf.addValue(CONFIG_CERT, DEFAULT_CONFIG_CERT);
    _conf.addValue(CONFIG_KEY, DEFAULT_CONFIG_KEY);
    object[CONFIG_PHPCGI_WEBPATH].v = DEFAULT_CONFIG_PHPCGI_WEBPATH;
    object[CONFIG_PHPCGI_CGIPATH].v = DEFAULT_CONFIG_PHPCGI_CGIPATH;
    object[CONFIG_NB_WORKERS].v = DEFAULT_CONFIG_NB_WORKERS;
    _conf.addValueObject(CONFIG_PHPCGI, object);
}
