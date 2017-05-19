#ifndef CPP_GKRELLM_SCREEN_HPP
#define CPP_GKRELLM_SCREEN_HPP

#include	<ncurses.h>
#include	<termios.h>
#include	<sys/ioctl.h>
#include	<cstring>
#include	<errno.h>
#include	<term.h>
#include	<Graphics/IMonitorDisplay.hpp>


class Screen {

  typedef void (Screen::*handle)();

public:

  Screen(const std::vector<IMonitorModule *> &modules);
  ~Screen();

  bool			setupTerminal();
  bool			setupNonBlockingIO();
  bool			resetTerminal();
  bool			buildSequences();
  bool			buildWindows();
  bool			buildOutline(WINDOW *window);
  bool			drawModuleBar(const std::vector<IMonitorModule *> &modules);

  void			handleSequence(std::string sequence, const std::vector<IMonitorModule *> &registeredModules);
  void			handleLeft(const std::vector<IMonitorModule *> &registeredModules);
  void			handleRight(const std::vector<IMonitorModule *> &registeredModules);
  size_t		getHModuleIndex() const;
  WINDOW		*getModuleDataScreen() const;

private:

  WINDOW		*MainScreen;
  WINDOW		*ModuleBar;
  WINDOW		*ModuleData;

  struct termios	BackupTerm;
  struct termios	EngineTerm;
  IMonitorModule	*CurrentModule;
  size_t		ModuleIndex;
  size_t		HModuleIndex;
  std::map<char *, handle>	keyMap;
  std::string		keyMapString[2];
  char			*tmpleft;
};


#endif //CPP_GKRELLM_SCREEN_HPP
