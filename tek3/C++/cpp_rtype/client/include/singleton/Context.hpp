#ifndef CPP_RTYPE_CONTEXTSTATE_HPP
# define CPP_RTYPE_CONTEXTSTATE_HPP

#include "singleton/Singleton.hpp"

namespace rtype {

	enum class ContextState {
		MENU,
		GAME
	};

	class Context : public Singleton<Context> {
		friend class Singleton<Context>;

	public:
		ContextState state = ContextState::MENU;
		~Context() {}
	private:
		Context() {}
	};
}

#endif /* !CPP_RTYPE_CONTEXTSTATE_HPP*/
