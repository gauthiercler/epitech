//
// Created by ventinc on 1/9/18.
//

#include <iostream>
#include <rnetwork/rnetwork.hpp>
#include <client/include/singleton/Singleton.hpp>
#include <client/include/singleton/Settings.hpp>
#include "Engine.hpp"

int main() {
  	rnetwork::init();
	rtype::Engine engine;

  	//try {
    	engine.run();
// 	}
  //	catch (std::exception const& e)
 	//{
   	//	std::cout << "Error: " << e.what() << std::endl;
  	//}
  	rnetwork::clean();
    return 0;
}
