#ifndef CPP_RTYPE_MENU_HPP
# define CPP_RTYPE_MENU_HPP

#include "client/src/menu/GUI/Handler.hpp"
#include "client/src/menu/FSM/FSM.hpp"
#include "AContext.hpp"

namespace rtype {
	class Menu : public AContext {
	public:
		explicit Menu(sf::RenderWindow &window);

		~Menu();

		void run(sf::Time &time) override;

	private:
		menu::FSM::machine _machine;
		menu::GUI::Handler _handler;
	};
}

#endif /* !CPP_RTYPE_MENU_HPP*/
