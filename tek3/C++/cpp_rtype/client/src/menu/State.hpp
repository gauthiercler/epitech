#ifndef CPP_RTYPE_STATE_HPP
# define CPP_RTYPE_STATE_HPP

#include "singleton/Context.hpp"

namespace rtype {

  namespace menu {

    enum class StateType {
      NONE,
      MAIN_MENU,
      OPTIONS,
      CREDITS,
      EXIT,
      PLAY,
      SINGLEPLAYER,
      MULTIPLAYER,
      MULTIPLAYER_LOBBIES_LIST,
      MULTIPLAYER_LOBBY,
      START
    };

    struct State {
    private:
      StateType type;
    public:
      StateType getType() const { return type; }

      State() = default;

      explicit State(StateType type) : type(type) {}
    };

  }
}

#endif /* !CPP_RTYPE_STATE_HPP*/
