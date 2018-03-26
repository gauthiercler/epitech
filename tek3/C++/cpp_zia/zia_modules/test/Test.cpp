//
// Created by valentin on 08/02/18.
//

#include "Test.hpp"

extern "C" zia::api::Module *zia::modules::create() {
  static Test test;

  return (&test);
}