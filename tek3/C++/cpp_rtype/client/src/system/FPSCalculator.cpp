//
// Created by ventinc on 1/12/18.
//

#include <sstream>
#include <iomanip>
#include "system/FPSCalculator.hpp"
#include "components/Position.hpp"
#include "components/Text.hpp"
#include "components/FPS.hpp"
#include "Manager.hpp"

rtype::FPSCalculator::FPSCalculator() {
	this->setRequiredComponents({ ecs::componentType<ct::Text>(), ecs::componentType<ct::FPS>() });
}

void rtype::FPSCalculator::process(ecs::Manager &mgr, float elapsedTime) {

	auto fps = 1.f / elapsedTime;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << fps;

	for (auto &&entity : this->entities) {
		auto &text = mgr.getEntityComponent<ct::Text>(entity);
		text.content = stream.str();
	}
}
