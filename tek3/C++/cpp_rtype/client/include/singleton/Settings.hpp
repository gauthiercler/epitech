#ifndef CPP_RTYPE_SETTINGS_HPP
# define CPP_RTYPE_SETTINGS_HPP

#include <cstddef>
#include <RtypeInput.hpp>
#include <unordered_map>
#include <util.hpp>
#include "Singleton.hpp"

namespace rtype {
	class Settings : public Singleton<Settings> {
		friend class Singleton<Settings>;

	private:
		Settings() :
			_musicVolume(100),
			_effectsVolume(100),
			_inputs(sf::Keyboard::Up,
					sf::Keyboard::Down,
					sf::Keyboard::Left,
					sf::Keyboard::Right,
					sf::Keyboard::Space,
					sf::Keyboard::K) {}

		int _musicVolume;
		int _effectsVolume;
		ct::RtypeInput _inputs;
		std::unordered_map<sf::Keyboard::Key, std::string, util::EnumClassHash> _keys {
			{sf::Keyboard::A, "A"},
			{sf::Keyboard::B, "B"},
			{sf::Keyboard::C, "C"},
			{sf::Keyboard::D, "D"},
			{sf::Keyboard::E, "E"},
			{sf::Keyboard::F, "F"},
			{sf::Keyboard::G, "G"},
			{sf::Keyboard::H, "H"},
			{sf::Keyboard::I, "I"},
			{sf::Keyboard::J, "J"},
			{sf::Keyboard::K, "K"},
			{sf::Keyboard::L, "L"},
			{sf::Keyboard::M, "M"},
			{sf::Keyboard::N, "N"},
			{sf::Keyboard::O, "O"},
			{sf::Keyboard::P, "P"},
			{sf::Keyboard::Q, "Q"},
			{sf::Keyboard::R, "R"},
			{sf::Keyboard::S, "S"},
			{sf::Keyboard::T, "T"},
			{sf::Keyboard::U, "U"},
			{sf::Keyboard::V, "V"},
			{sf::Keyboard::W, "W"},
			{sf::Keyboard::X, "X"},
			{sf::Keyboard::Y, "Y"},
			{sf::Keyboard::Z, "Z"},
			{sf::Keyboard::Num0, "0"},
			{sf::Keyboard::Num1, "1"},
			{sf::Keyboard::Num2, "2"},
			{sf::Keyboard::Num3, "3"},
			{sf::Keyboard::Num4, "4"},
			{sf::Keyboard::Num5, "5"},
			{sf::Keyboard::Num6, "6"},
			{sf::Keyboard::Num7, "7"},
			{sf::Keyboard::Num8, "8"},
			{sf::Keyboard::Num9, "9"},
			{sf::Keyboard::Escape, "ESCAPE"},
			{sf::Keyboard::LControl, "LCONTROL"},
			{sf::Keyboard::LShift, "LSHIFT"},
			{sf::Keyboard::LAlt, "LALT"},
			{sf::Keyboard::LSystem, "LSYSTEM"},
			{sf::Keyboard::RControl, "RCONTROL"},
			{sf::Keyboard::RShift, "RSHIFT"},
			{sf::Keyboard::RAlt, "RALT"},
			{sf::Keyboard::RSystem, "RSYSTEM"},
			{sf::Keyboard::Menu, "MENU"},
			{sf::Keyboard::LBracket, "LBRACKET"},
			{sf::Keyboard::RBracket, "RBRACKET"},
			{sf::Keyboard::SemiColon, "SEMICOLON"},
			{sf::Keyboard::Comma, "COMMA"},
			{sf::Keyboard::Period, "PERIOD"},
			{sf::Keyboard::Quote, "QUOTE"},
			{sf::Keyboard::Slash, "SLASH"},
			{sf::Keyboard::BackSlash, "BACKSLASH"},
			{sf::Keyboard::Tilde, "TILDE"},
			{sf::Keyboard::Equal, "EQUAL"},
			{sf::Keyboard::Dash, "DASH"},
			{sf::Keyboard::Space, "SPACE"},
			{sf::Keyboard::Return, "RETURN"},
			{sf::Keyboard::BackSpace, "BACKSPACE"},
			{sf::Keyboard::Tab, "TAB"},
			{sf::Keyboard::PageUp, "PAGEUP"},
			{sf::Keyboard::PageDown, "PAGEDOWN"},
			{sf::Keyboard::End, "END"},
			{sf::Keyboard::Home, "HOME"},
			{sf::Keyboard::Insert, "INSERT"},
			{sf::Keyboard::Delete, "DELETE"},
			{sf::Keyboard::Add, "ADD"},
			{sf::Keyboard::Subtract, "SUBTRACT"},
			{sf::Keyboard::Multiply, "MULTIPLY"},
			{sf::Keyboard::Divide, "DIVIDE"},
			{sf::Keyboard::Left, "LEFT"},
			{sf::Keyboard::Right, "RIGHT"},
			{sf::Keyboard::Up, "UP"},
			{sf::Keyboard::Down, "DOWN"},
			{sf::Keyboard::F1, "F1"},
			{sf::Keyboard::F2, "F2"},
			{sf::Keyboard::F3, "F3"},
			{sf::Keyboard::F4, "F4"},
			{sf::Keyboard::F5, "F5"},
			{sf::Keyboard::F6, "F6"},
			{sf::Keyboard::F7, "F7"},
			{sf::Keyboard::F8, "F8"},
			{sf::Keyboard::F9, "F9"},
			{sf::Keyboard::F10, "F10"},
			{sf::Keyboard::F11, "F11"},
			{sf::Keyboard::F12, "F12"},
			{sf::Keyboard::F13, "F13"},
			{sf::Keyboard::F14, "F14"},
			{sf::Keyboard::F15, "F15"}
		};

	public:
		~Settings() override = default;
		void setMusicVolume(int volume);
	void setEffectsVolume(int volume);
		void setKeyboard(const std::string &up, const std::string &down, const std::string &left, const std::string &right, const std::string &fire, const std::string &charge);
		const ct::RtypeInput &getKeyboard();
		sf::Keyboard::Key getKeyboardKey(const std::string &key);
		const std::string getKeyboardString(sf::Keyboard::Key key);
		int getMusicVolume() const { return _musicVolume; }
		int getEffectsVolume() const { return _effectsVolume; }

	};
}

#endif /* !CPP_RTYPE_SETTINGS_HPP*/
