#ifndef CPP_ZIA_EXECUTER_HPP
#define CPP_ZIA_EXECUTER_HPP

#include <streambuf>
#include <unordered_map>
#include <sstream>
#include <map>

namespace zia::modules::php {
  class Executer {

  private:
      int _inputFds[2]{};
      int _ouptutFds[2]{};
      pid_t _pid;
      std::stringstream _result;

  public:
      Executer() = default;
      Executer(const Executer &executer) = delete;
      virtual ~Executer() = default;

      std::stringstream &run(const std::string &cmd, const std::unordered_map<std::string, std::string> &env, const std::string &data);

      Executer &operator=(const Executer &executer) = delete;

  private:
      void openFds();
      void startCmd(const std::string &cmd, const std::unordered_map<std::string, std::string> &env);
      void execCmd(const std::string &cmd, const std::unordered_map<std::string, std::string> &env);
      void closeHost();
      void waitCmd() const;
      void receiveData();
      void sendData(const std::string &data) const;
      char **generateEnv(const std::unordered_map<std::string, std::string> &env) const;
  };
}

#endif //CPP_ZIA_EXECUTER_HPP
