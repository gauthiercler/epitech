#include <sstream>
#include <iostream>
#include "Env.hpp"

std::map<std::string, std::string>Env::env;

void Env::setEnv(char ** const env) {
  unsigned int index = 0;
  std::string key;
  std::string value;

  while (env[index] != NULL)
  {
    std::istringstream stream(env[index]);
    std::getline(stream, key, '=');
    std::getline(stream, value);
    Env::env[key] = value;
    index++;
  }
}
