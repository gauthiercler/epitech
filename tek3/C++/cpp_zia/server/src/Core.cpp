//
// Created by valentin on 06/02/18.
//

#include <iostream>
#include <nobyte/NoByte.hpp>
#include <shared/ResponseSerializer.hpp>
#include "../include/Core.hpp"
#include "shared/RequestBuilder.hpp"

zia::server::Core::Core()
    : _moduleManager(), _moduleLoader(_moduleManager)
{}

bool zia::server::Core::config(zia::server::Args args) {
    return (configFile(args[1]));
}

bool zia::server::Core::config(const std::string &filename) {
    return (configFile(filename));
}

bool zia::server::Core::configFile(const std::string &filename) {
    if (!_configManager.setConfigFileName(filename)) {
	std::cerr << "[WARNING] No config file : " << filename << std::endl;
	return (false);
    }
    return (_configManager.loadConfiguration());
}

void zia::server::Core::defaultConfig() {
    _configManager.loadDefaultConfig();
}

void zia::server::Core::run() {
    initPipeline();
    std::cout << "[INFO] Server launching.." << std::endl;
    _moduleManager.getNetwork()->run(std::bind(&zia::server::Core::processRequest, this, std::placeholders::_1, std::placeholders::_2));
}

void zia::server::Core::initPipeline() {
    std::cout << "[INFO] Server loading modules..." << std::endl;
    initConfigPath();
    initConfigModule();
    std::cout << "[INFO] Server setting Configuration on all modules" << std::endl;
    _moduleManager.configAll(_configManager.getConfiguration());
}

void zia::server::Core::initConfigPath() {
    try {
	const auto &paths = _configManager.getConfiguration().getArray(CONFIG_PATH);
	_moduleLoader.setPath(paths);
    } catch (std::exception &e) {
	const auto &path = _configManager.getConfiguration().getValue<std::string>(
	    CONFIG_PATH);
	const std::vector<std::string> paths = {path, ""};
	_moduleLoader.setPath(paths);
    }
}

void zia::server::Core::initConfigModule() {
    if (!_moduleLoader.loadNetworkModule(_configManager.getConfiguration().getValue<std::string>(CONFIG_NETWORK)))
	throw std::runtime_error("Critical Error: Couldn't load the network module");
    try {
	const auto modules = _configManager.getConfiguration().getArray(CONFIG_MODULE);
        _moduleLoader.loadModules(modules);
    } catch (std::exception &e) {
	const auto &module = _configManager.getConfiguration().getValue<std::string>(CONFIG_MODULE);
	_moduleLoader.loadModule(module);
    }
}

void zia::server::Core::processRequest(zia::api::Net::Raw raw, zia::api::NetInfo netInfo) {
    zia::api::HttpDuplex duplex;
    zia::shared::RequestBuilder requestBuilder;
    zia::modules::net::ResponseSerializer responseSerializer;

    requestBuilder.fill(noByte::toString(raw));
    requestBuilder.parse();
    duplex.info = netInfo;
    duplex.raw_req = raw;
    duplex.req = requestBuilder.build().toBasicHttpRequest();
    duplex.resp.version = duplex.req.version;
    std::clog << "[LOG][CORE] " << netInfo.ip.str << " request " << duplex.req.uri << std::endl;
    _moduleManager.execModules(duplex);
    duplex.raw_resp = responseSerializer.serialize(duplex.resp);
    _moduleManager.getNetwork()->send(netInfo.sock, duplex.raw_resp);
}
