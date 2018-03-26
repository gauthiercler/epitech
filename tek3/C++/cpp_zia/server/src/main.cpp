//
// main.cpp for Zia in /home/valentin/Rendu/Tek3/C++/cpp_zia
// 
// Made by Valentin Montagne
// Login   <valentin.montagne@epitech.eu>
// 
// Started on  Tue Feb  6 13:01:53 2018 
// Last update Tue Feb  6 13:02:13 2018 
//

#include <iostream>
#include "BetterConf.hpp"
#include "Core.hpp"

void	printDefaultConfig() {
    std::cerr << "[WARNING] Couldn't load any custom configuration" << std::endl;
    std::cout << "[INFO][CONFIG] PORT : " << zia::server::DEFAULT_CONFIG_PORT << std::endl;
    std::cout << "[INFO][CONFIG] SSL_PORT : " << zia::server::DEFAULT_CONFIG_SSL_PORT << std::endl;
#ifdef WIN32
    std::cout << "[INFO][CONFIG] NETWORK LIBRARY : " << zia::server::DEFAULT_CONFIG_NETWORK_WINDOWS << std::endl;
#else
    std::cout << "[INFO][CONFIG] NETWORK LIBRARY : " << zia::server::DEFAULT_CONFIG_NETWORK_UNIX << std::endl;
#endif
    std::cout << "[INFO][CONFIG] MODULES : SSL & PHPCGI" << std::endl;
    std::cout << "[INFO][CONFIG] PATHS : " << zia::server::DEFAULT_CONFIG_PATH << std::endl;
}

bool	checkOptions(zia::server::Core &core, int ac, char **av) {
    core.defaultConfig();
    if (ac > 1 && core.config(av)) {
	std::cout << "[INFO] Setting custom config file : " << av[1] << std::endl;
    }
    else {
	std::cout << "[INFO] Default config file used : "
		  << zia::server::DefaultConfigFile << std::endl;
	if (!core.config(zia::server::DefaultConfigFile)) {
	    printDefaultConfig();
	}
    }
    return (true);
}

int	main(int ac, char **av) {
    zia::server::Core core;

    if (!checkOptions(core, ac, av))
	return (1);
    try {
	core.run();
    } catch (std::exception &e) {
	std::cerr << "[ERROR] " << e.what() << std::endl;
	return (1);
    }
    return (0);
}
