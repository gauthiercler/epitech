#ifndef CPP_RTYPE_EXITHANDLER_HPP
# define CPP_RTYPE_EXITHANDLER_HPP

#include <imgui.h>
#include "MenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {
		class ExitHandler : public MenuHandler {
		public:
			explicit ExitHandler(StateType &requestedState) : MenuHandler(requestedState) {}
			virtual ~ExitHandler() = default;
			void draw() override {}
      };
    }
  }
}

#endif /* !CPP_RTYPE_EXITHANDLER_HPP*/
