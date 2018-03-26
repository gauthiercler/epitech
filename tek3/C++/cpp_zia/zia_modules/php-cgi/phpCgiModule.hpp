#ifndef CPP_ZIA_PHPCGIMODULE_HPP
#define CPP_ZIA_PHPCGIMODULE_HPP

#include <pp/module.hpp>
#include <Config.hpp>

namespace zia::modules::php {
  class PhpCgiModule : public zia::apipp::Module
  {
  private:
      std::string _cgiPath{};
      std::string _webPath{};

  public:
      PhpCgiModule() = default;
      PhpCgiModule(const PhpCgiModule &phpCgiModule) = default;
      virtual ~PhpCgiModule() = default;

      bool config(const zia::api::Conf &conf) override;
      bool isValid() const;

      bool perform() override;

      PhpCgiModule &operator=(const PhpCgiModule &phpCgiModule) = default;

  private:
      void updateResponse(const zia::api::HttpResponse &response);
      std::string getRequestFile() const;
      std::string getQuery() const;
      void handlePostData(std::unordered_map<std::string, std::string> &env, const zia::apipp::RequestPtr &request);
      void exportHeaders(std::unordered_map<std::string, std::string> &env, const zia::apipp::RequestPtr &request) const;
  };
}

extern "C" MODULE_API zia::api::Module *create();


#endif //CPP_ZIA_PHPCGIMODULE_HPP
