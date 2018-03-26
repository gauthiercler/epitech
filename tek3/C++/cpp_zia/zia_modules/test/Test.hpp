#ifndef ENEMY_TEST_HPP
#define ENEMY_TEST_HPP

#include <pp/module.hpp>
#include "Config.hpp"

namespace zia::modules {

  class MODULE_API Test : public zia::apipp::Module {

  public:
    ~Test() override = default;

    bool perform() override {
      this->response->useStandardData();

      this->response
	->setStatus(200, "OK")
	->addHeader("Set-Cookie", "test")
	->addHeader("Set-Cookie", "toto")
	->setStandardData("test");

      return true;
    }

  };

  extern "C" MODULE_API zia::api::Module *create();

}

#endif //ENEMY_TEST_HPP
