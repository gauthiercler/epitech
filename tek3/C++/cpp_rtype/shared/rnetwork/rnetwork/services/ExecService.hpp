#ifndef CPP_RTYPE_EXECSERVICE_HPP
#define CPP_RTYPE_EXECSERVICE_HPP

#include "IService.hpp"
#include "config/Export.hpp"

namespace rnetwork
{
    namespace services
    {
        class RNETWORK_API ExecService : public rnetwork::services::IService
        {
        public:
            static ExecService& Instance();

        private:
            static ExecService _instance;

        private:
            std::string _name;

        public:
            ExecService();
            ExecService(const ExecService &execService) = delete;
            virtual ~ExecService() = default;

            void update() override;
            const std::string &name() const override;

            ExecService &operator=(const ExecService &execService) = delete;
        };
    }
}


#endif //CPP_RTYPE_EXECSERVICE_HPP
