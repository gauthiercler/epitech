/*
** Config.hpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Config/Config.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 11:54:46 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 11:54:46 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_GKRELLM_CONFIG_HPP_HPP
#define CPP_GKRELLM_CONFIG_HPP_HPP

# include <string>

#ifndef BG_COLOR
# define BG_COLOR (50)
#endif

#ifndef MODULE_COLOR
# define MODULE_COLOR (55)
#endif

#ifndef COLOR_BLUE
# define COLOR_BLUE (55)
#endif

#ifndef COLOR_GREEN
# define COLOR_GREEN (56)
#endif

#ifndef COLOR_RED
# define COLOR_RED (57)
#endif

#ifndef	COLOR_YELLOW
# define COLOR_YELLOW (58)
#endif

#ifndef COLOR_GREEN_BG
# define COLOR_GREEN_BG (60)
#endif

class Config
{

public:
  enum				GraphicMode { GRAPHICS, TERM };

  const static unsigned  int	width = 1000;
  const static unsigned int	height = 700;
  const static unsigned int	moduleHeight = 635;
  const static std::string	name;
  const static std::string	fontPath;
  const static std::string	settingPath;
  const static std::string	checkedPath;
  const static std::string	crossedPath;
  const static std::string	userPath;
  const static std::string	linuxPath;
  const static std::string	datetimePath;
  const static std::string	flyPath1;
  const static std::string	flyPath2;
  const static std::string	termModeFlag;
};

#endif //CPP_GKRELLM_CONFIG_HPP_HPP
