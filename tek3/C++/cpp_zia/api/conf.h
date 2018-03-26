#pragma once

#include <map>
#include <string>
#include <variant>
#include <vector>

namespace zia::api {
    struct ConfValue;
    using ConfObject = std::map<std::string, ConfValue>;
    using ConfArray = std::vector<ConfValue>;

    /**
    * Represents a configuration value.
    */
    struct ConfValue {
        std::variant<std::monostate, ConfObject, ConfArray, std::string, long long, double, bool> v;
    };

    /**
    * Configuration (format influenced by JSON).
    * Configuration must contain:
    *  - "modules": a list of modules name e.g. "cgibin", "gzip", "logger" (extension will be appended, will be prefixed by "lib" on linux)
    *  - "modules_path": a list of paths to look for modules e.g. ".", "modules"
    */
    using Conf = ConfObject;
}
