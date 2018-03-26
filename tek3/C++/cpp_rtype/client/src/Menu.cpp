
#include <SFML/Graphics/RenderWindow.hpp>
#include <client/ImGui/imgui-SFML.h>
#include <client/ImGui/imgui.h>
#include <SFML/Window/Event.hpp>
#include "Menu.hpp"

rtype::Menu::Menu(sf::RenderWindow &window) : AContext(window), _handler(std::ref(_machine.requestedState)) {

	_machine.start();
	ImGui::SFML::Init(_window);
	window.resetGLStates();
}

void rtype::Menu::run(sf::Time &time) {
	sf::Event event;
	sf::Color bgColor;

	while (_window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::Closed) {
			_window.close();
		}
	}

	ImGui::SFML::Update(_window, time);

	bool open = true;
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("", &open, ImVec2(_window.getSize().x, _window.getSize().y), 0.9f, ImGuiWindowFlags_NoResize
													 | ImGuiWindowFlags_NoCollapse
													 | ImGuiWindowFlags_NoMove
													 | ImGuiWindowFlags_NoBringToFrontOnFocus
													 | ImGuiWindowFlags_NoTitleBar
				 									 | ImGuiWindowFlags_NoScrollbar);
	ImGui::SetWindowFontScale(5);

	_machine.process_event(EventStartComputation());
	_handler.getStateHandler(_machine.activeState).draw();
	if (_machine.activeState == rtype::menu::StateType::EXIT)
		_window.close();

	ImGui::End();

	_window.clear(bgColor);
	ImGui::SFML::Render(_window);
	_window.display();
}

rtype::Menu::~Menu() {
	_machine.stop();
	ImGui::SFML::Shutdown();
}
