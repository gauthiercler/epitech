//
// Created by valentin on 22/02/18.
//

#ifndef CPP_ZIA_MESSAGEDATA_HPP
#define CPP_ZIA_MESSAGEDATA_HPP

#include <http.h>

namespace zia::shared {

    struct MessageData {
	std::string 			host;
	std::string 			uri;
	zia::api::http::Method 		method {zia::api::http::Method::unknown};
	zia::api::http::Version 	version {zia::api::http::Version::unknown};
	std::map<std::string,
	std::vector<std::string>>	headers;
	std::string			msg;
	std::string 			raw;
    };

}

#endif //CPP_ZIA_MESSAGEDATA_HPP
