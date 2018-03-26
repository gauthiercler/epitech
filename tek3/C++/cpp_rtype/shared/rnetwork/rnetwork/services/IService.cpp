#include "IService.hpp"

bool operator==(const rnetwork::services::IService &a, const rnetwork::services::IService &b)
{
    return a.name() == b.name();
}