//
// Created by valentin on 09/02/18.
//

#ifndef CPP_ZIA_BETTERCONF_HPP
#define CPP_ZIA_BETTERCONF_HPP

#include <conf.h>

namespace zia::server {

    constexpr char CONFIG_PORT[] = "port";
    constexpr char CONFIG_SSL_PORT[] = "ssl_port";
    constexpr char CONFIG_NETWORK[] = "network_module";
    constexpr char CONFIG_MODULE[] = "module";
    constexpr char CONFIG_PATH[] = "modules_path";
    constexpr char CONFIG_NB_WORKERS[] = "nb_workers";
    constexpr char CONFIG_CERT[] = "cert_path";
    constexpr char CONFIG_KEY[] = "key_path";
    constexpr char CONFIG_PHPCGI[] = "php_cgi";
    constexpr char CONFIG_PHPCGI_WEBPATH[] = "web_path";
    constexpr char CONFIG_PHPCGI_CGIPATH[] = "cgi_path";

    constexpr char DEFAULT_CONFIG_PORT[] = "80";
    constexpr char DEFAULT_CONFIG_SSL_PORT[] = "443";
    constexpr char DEFAULT_CONFIG_NETWORK_UNIX[] = "libnet.so";
    constexpr char DEFAULT_CONFIG_NETWORK_WINDOWS[] = "net.dll";
    //TODO ADD REAL DEFAULT MODULES
    constexpr char DEFAULT_CONFIG_MODULE[] = "";
    constexpr char DEFAULT_CONFIG_PATH[] = ".";
    constexpr char DEFAULT_CONFIG_NB_WORKERS[] = "5";
    constexpr char DEFAULT_CONFIG_CERT[] = "./keys/cert.pem";
    constexpr char DEFAULT_CONFIG_KEY[] = "./key/key.pem";
    constexpr char DEFAULT_CONFIG_PHPCGI_WEBPATH[] = "/var/www/html";
    constexpr char DEFAULT_CONFIG_PHPCGI_CGIPATH[] = "/usr/bin/php-cgi";

    using ConfValue = std::variant<std::monostate, zia::api::ConfObject, zia::api::ConfArray, std::string, long long, double, bool>;

    class BetterConf {

	zia::api::Conf _conf;

    public:

	BetterConf() = default;
	~BetterConf() = default;

	template <typename T>
	T getValue(const std::string &key) {
	    return (std::get<T>(_conf[key].v));
	}

	const std::vector<std::string> getArray(const std::string &key) {
	    const auto &arr = std::get<zia::api::ConfArray>(_conf[key].v);
	    std::vector<std::string> array;

	    for (const auto &item: arr)
		array.push_back(std::get<std::string>(item.v));
	    return (std::move(array));
	}

	ConfValue &get(const std::string &key) {
	    return (_conf[key].v);
	}

	void insert(const std::string &key, const ConfValue &value) {
	    _conf.insert({key, {value}});
	}

	const zia::api::Conf &getBasicConf() const {
	    return (_conf);
	}

	void addValue(const std::string &key, const std::string &value) {
	    insert(key, ConfValue());
	    _conf[key].v = static_cast<std::string>(value);
	}

	void addValueArry(const std::string &key, const zia::api::ConfArray &arr) {
	    insert(key, ConfValue());
	    _conf[key].v = arr;
	}

	void addValueObject(const std::string &key, const zia::api::ConfObject &obj) {
	    insert(key, ConfValue());
	    _conf[key].v = obj;
	}

    };
}

#endif //CPP_ZIA_BETTERCONF_HPP
