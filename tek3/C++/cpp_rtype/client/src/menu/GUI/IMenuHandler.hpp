#ifndef CPP_RTYPE_IGUI_HPP
# define CPP_RTYPE_IGUI_HPP

#include "State.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {

      class IMenuHandler {

      public:
	virtual void draw() = 0;

	virtual ~IMenuHandler() = default;
      };

    }
  }
}

#endif /* !CPP_RTYPE_IGUI_HPP*/
