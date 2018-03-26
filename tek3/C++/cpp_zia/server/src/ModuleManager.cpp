//
// Created by valentin on 06/02/18.
//

#include <BetterConf.hpp>
#include "../include/ModuleManager.hpp"

zia::server::ModuleID zia::server::ModuleManager::addModule(zia::api::Module *module) {
  _modules.emplace_back(module);
  return (_modules.size() - 1);
}

void
zia::server::ModuleManager::removeModule(const zia::api::Module &module) {
  _modules.erase(std::find(_modules.begin(), _modules.end(), &module));
}

void zia::server::ModuleManager::removeModule(ModuleID id) {
  _modules.erase(_modules.begin() + id);
}

void zia::server::ModuleManager::clear() {
  _modules.clear();
}

zia::api::Module &
zia::server::ModuleManager::getModule(zia::server::ModuleID id) {
  return (*_modules[id]);
}

zia::api::Net *zia::server::ModuleManager::getNetwork() {
  return (_network);
}

void zia::server::ModuleManager::setNetwork(zia::api::Net *net) {
  _network = net;
}

void zia::server::ModuleManager::configAll(zia::server::BetterConf &conf) {
  _network->config(conf.getBasicConf());
  configModules(conf);
}

void zia::server::ModuleManager::execModules(zia::api::HttpDuplex &http) {
  for (const auto &m : _modules)
    if (!m->exec(http))
        break;
}

void zia::server::ModuleManager::configModules(zia::server::BetterConf &conf) {
  for (const auto &module: _modules)
    module->config(conf.getBasicConf());
}