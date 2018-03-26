#ifndef CPP_ZIA_NOBYTE_HPP
#define CPP_ZIA_NOBYTE_HPP

#include <string>
#include "net.h"

namespace noByte {
  std::vector<std::byte> toByte(const std::string &str);
  std::string toString(const std::vector<std::byte> &useless);
}

#endif //CPP_ZIA_NOBYTE_HPP
