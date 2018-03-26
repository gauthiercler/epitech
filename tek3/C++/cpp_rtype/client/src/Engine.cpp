//
// Created by ventinc on 1/16/18.
//

#include <Game.hpp>
#include <rnetwork/tasks/ExecTask.hpp>
#include <Menu.hpp>
#include <client/include/singleton/NetworkManager.hpp>
#include <rnetwork/tasks/DelayedTask.hpp>
#include <SFML/Audio/Music.hpp>
#include "client/include/Engine.hpp"


void rtype::Engine::run() {
	auto io_service = std::make_shared<rnetwork::async::IOService>();

    io_service->forceInfinite();
	sf::Thread thread([&]() {
		io_service->run();
        std::cout << "Out of tasks" << std::endl;
	});

	thread.launch();

	Singleton<NetworkManager>::get().setIOService(io_service);

	sf::Music music;

	music.openFromFile("./client/assets/music.wav");
	music.setLoop(true);
	music.setPitch(1.25);
	music.play();

	_window.get().setActive(true);
	sf::Context ctx;

	rtype::Game game(_window.get());
	rtype::Menu menu(_window.get());

	sf::Clock clock;

	while (_window.get().isOpen()) {
		auto time = clock.restart();
		if (Singleton<Context>::get().state == ContextState::MENU)
			menu.run(time);
		else
			game.run(time);
	}
	io_service->stop();
}
