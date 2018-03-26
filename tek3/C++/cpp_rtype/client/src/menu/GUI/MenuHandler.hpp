#ifndef CPP_RTYPE_MENUHANDLER_HPP
# define CPP_RTYPE_MENUHANDLER_HPP

#include "IMenuHandler.hpp"

namespace rtype {
  namespace menu {
    namespace GUI {
		class MenuHandler : public IMenuHandler {
		public:
			explicit MenuHandler(StateType &requestedState) : _requestedState(requestedState) {}
			virtual ~MenuHandler() = default;
			virtual void draw() = 0;
		protected:
			StateType &_requestedState;
		};
    }
  }
}

#endif /* !CPP_RTYPE_MENUHANDLER_HPP*/
