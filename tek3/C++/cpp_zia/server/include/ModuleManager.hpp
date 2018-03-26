//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_MODULEMANAGER_HPP
#define CPP_RTYPE_MODULEMANAGER_HPP

#include <vector>
#include <pp/module.hpp>
#include "BetterConf.hpp"

namespace zia::server
{

  using ModuleID = size_t;

  class ModuleManager {

    std::vector<zia::api::Module *> _modules;
    zia::api::Net *_network;

  public:

    ModuleManager()
    : _network(nullptr)
    {}
    ~ModuleManager() = default;

    ModuleID addModule(zia::api::Module *module);
    void removeModule(const zia::api::Module &module);
    void removeModule(ModuleID id);
    void clear();

    zia::api::Net *getNetwork();
    void setNetwork(zia::api::Net *net);

    zia::api::Module &getModule(ModuleID id);
    void execModules(zia::api::HttpDuplex &http);
    void configModules(BetterConf &conf);
    void configAll(BetterConf &conf);

  };

}


#endif //CPP_RTYPE_MODULEMANAGER_HPP
