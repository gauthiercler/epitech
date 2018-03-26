//
// Created by valentin on 08/02/18.
//

#ifndef CPP_RTYPE_MODULELOADER_HPP
#define CPP_RTYPE_MODULELOADER_HPP

#include <iostream>
#include "ModuleManager.hpp"
#include "DLLoader/DLLoaderFactory.hpp"
#include "DLLoader/DLInstanceLoader.hpp"
#include "DLLoader/FileSystem.hpp"

namespace zia::server {

  class ModuleLoader {

    using Lib = std::unique_ptr<zia::module::DLInstanceLoader<char *>>;
    using Libs = std::vector<Lib>;

    ModuleManager		&_manager;
    std::vector<std::string> 	_paths;
    Libs 			_libs;

    const std::string getFilePath(const std::string &filename, const std::string &path);
    void fillManager(Lib &lib, bool net = false);
    void fillManagerWithModule(zia::api::Module *(*f)());
    void fillManagerWithNetwork(zia::api::Net *(*f)());
    bool loadModuleFromFile(fs::FileIterator &file, const std::string &path, bool net = false);
    bool loadModuleFromFolder(fs::FolderDescriptor &folder, const std::string &path, const std::string &name, bool net = false);

  public:

    ModuleLoader(ModuleManager &manager);
    ModuleLoader(ModuleManager &manager, const std::vector<std::string> &paths);
    ~ModuleLoader();

    void loadModule(const std::string &name);
    bool loadNetworkModule(const std::string &name);
    void loadModules(const std::vector<std::string> &names);

    void setPath(const std::vector<std::string> &paths);

  };

}


#endif //CPP_RTYPE_MODULELOADER_HPP
