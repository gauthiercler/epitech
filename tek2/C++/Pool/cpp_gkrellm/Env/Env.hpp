/*
** Env.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Env/Env.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 21 23:32:14 2017 Antoine FORET
** Last update Sat Jan 21 23:32:14 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_ENV_HPP
#define CPP_GKRELLM_ENV_HPP

# include			<string>
# include			<map>

class Env {

public:
  static std::map<std::string, std::string>	env;
  static void setEnv(char ** const env);

};


#endif //CPP_GKRELLM_ENV_HPP
