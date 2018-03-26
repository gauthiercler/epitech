#include <algorithm>
#include "NoByte.hpp"

std::vector<std::byte> noByte::toByte(const std::string &str)
{
    zia::api::Net::Raw useless;

    std::for_each(str.begin(), str.end(), [&](const char &c) {
        useless.emplace_back((std::byte)c);
    });

    return useless;
}

std::string noByte::toString(const std::vector<std::byte> &useless)
{
    std::string str;

    std::for_each(useless.begin(), useless.end(), [&](const std::byte &c) {
        str += (char)c;
    });

    return str;
}
