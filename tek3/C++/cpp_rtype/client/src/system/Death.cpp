//
// Created by ventinc on 1/17/18.
//

#include <algorithm>
#include <iostream>
#include "client/include/system/Death.hpp"
#include "component/types/ComponentIdGenerator.hpp"
#include "Dead.hpp"
#include "Manager.hpp"

rtype::Death::Death() {
	this->setRequiredComponents({ecs::componentType<ct::Dead>()});
}

void rtype::Death::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto entity = this->entities.begin(); entity != this->entities.end();) {
		mgr.unregisterEntityExpect(*entity, this->getRequiredComponents(), true);
		entity = this->entities.erase(entity);
	}
}
