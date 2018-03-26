//
// Created by valentin on 06/02/18.
//

#ifndef CPP_RTYPE_JSONPARSER_HPP
#define CPP_RTYPE_JSONPARSER_HPP

#include <nlohmann/json.hpp>
#include <conf.h>

namespace zia::server {

    using JSON = nlohmann::json;

    class JSONParser {

	JSONParser() = default;
	~JSONParser() = default;

    public:

	JSON parseFromFile(std::ifstream &file);
	JSON parseFromStr(const std::string &data);
	zia::api::ConfArray translate(const JSON &json);
	zia::api::ConfObject translateToObject(const JSON &json);

	static JSONParser &Instance();

    };

}

#endif //CPP_RTYPE_JSONPARSER_HPP
