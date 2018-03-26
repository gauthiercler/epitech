//
// Created by ventinc on 1/9/18.
//

#include <iostream>
#include "Engine.hpp"

int main() {
    rtypeserver::Engine engine;

	rnetwork::init();
	try {
		engine.start(rnetwork::Endpoint("0.0.0.0", 4242));
	} catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	rnetwork::clean();
    return 0;
}