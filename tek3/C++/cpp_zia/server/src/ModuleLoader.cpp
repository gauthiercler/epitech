//
// Created by valentin on 08/02/18.
//

#include "ModuleLoader.hpp"

bool zia::server::ModuleLoader::loadModuleFromFile(fs::FileIterator &file, const std::string &path, bool net) {
    const std::string &filePath = getFilePath(file.name(), path);

    auto loader = module::make::newFunctionLoader<char *>(filePath);
    if (!loader->isLoaded()) {
	std::cerr << "[WARNING] " << filePath << " failed to load" << std::endl;
	return (false);
    }
    else
	std::cout << "[INFO] Module " << file.name() << " loaded" << std::endl;
    fillManager(loader, net);
    _libs.push_back(std::move(loader));
    return (true);
}

bool zia::server::ModuleLoader::loadModuleFromFolder(zia::fs::FolderDescriptor &folder, const std::string &path, const std::string &name, bool net) {
    while (folder.hasNext()) {
	auto file = folder.next();
	if (file.isFile() && file.name() == name && loadModuleFromFile(file, path, net))
	    return (true);
    }
    return (false);
}

zia::server::ModuleLoader::ModuleLoader(zia::server::ModuleManager &manager)
    : _manager(manager)
{}

zia::server::ModuleLoader::ModuleLoader(zia::server::ModuleManager &manager,
					const std::vector<std::string> &paths)
    : _manager(manager), _paths(paths)
{}

void zia::server::ModuleLoader::loadModule(const std::string &name) {
    bool found = false;

    for (auto &path : _paths) {
	fs::FolderDescriptor folder(path.c_str());

	if (!folder) {
	    std::cerr << "[WARNING] Invalid Path : " << path << " it will be skipped" << std::endl;
	    continue;
	}
	if (loadModuleFromFolder(folder, path, name)) {
	    std::cout << "[INFO] Finding module " << name << " in folder " << path << std::endl;
	    found = true;
	    break;
	}
    }
    if (!found)
	std::cerr << "[WARNING] Error couldn't find the module " << name << std::endl;
}

void zia::server::ModuleLoader::loadModules(const std::vector<std::string> &names) {
    for (const auto &n : names)
	loadModule(n);
}

const std::string
zia::server::ModuleLoader::getFilePath(const std::string &filename,
				       const std::string &path) {
    std::string filePath = path;

    filePath.append("/");
    filePath.append(filename);
    return (filePath);
}

void
zia::server::ModuleLoader::fillManager(zia::server::ModuleLoader::Lib &lib, bool net) {
    if (!net)
	fillManagerWithModule(lib->template loadFunction<zia::api::Module *(*)()>("create"));
    else
	fillManagerWithNetwork(lib->template loadFunction<zia::api::Net *(*)()>("create"));
}

zia::server::ModuleLoader::~ModuleLoader() {
    _libs.clear();
}

void zia::server::ModuleLoader::setPath(const std::vector<std::string> &paths) {
    _paths = paths;
}

bool zia::server::ModuleLoader::loadNetworkModule(const std::string &name) {
    for (auto &path : _paths) {
	if (path.empty())
	    continue;
	fs::FolderDescriptor folder(path.c_str());

	if (!folder) {
	    std::cerr << "[WARNING] Invalid Path : " << path << " it will be skipped" << std::endl;
	    continue;
	}
	if (loadModuleFromFolder(folder, path, name, true)) {
	    std::cout << "[INFO] Finding module " << name << " in folder " << path << std::endl;
	    return (true);
	}
    }
    std::cerr << "[WARNING] Error couldn't find the module " << name << std::endl;
    return (false);
}

void
zia::server::ModuleLoader::fillManagerWithModule(zia::api::Module *(*f)()) {
    if (f != nullptr) {
	auto module = f();

	if (module != nullptr)
	    _manager.addModule(module);
	else
	    std::cerr << "[WARNING] Invalid module" << std::endl;
    }
    else
	std::cerr << "[WARNING] Couldn't load the create function from the module" << std::endl;
}

void zia::server::ModuleLoader::fillManagerWithNetwork(zia::api::Net *(*f)()) {
    if (f != nullptr) {
	auto net = f();

	if (net != nullptr)
	    _manager.setNetwork(net);
	else
	    std::cerr << "[WARNING] Invalid network" << std::endl;
    }
    else
	std::cerr << "[WARNING] Couldn't load the create function from the network" << std::endl;
}
