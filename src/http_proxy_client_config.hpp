/*
 *    http_proxy_client_config.hpp:
 *
 *    Copyright (C) 2013-2015 limhiaoing <blog.poxiao.me> All Rights Reserved.
 *
 */

#ifndef AZURE_HTTP_PROXY_CLIENT_CONFIG_HPP
#define AZURE_HTTP_PROXY_CLIENT_CONFIG_HPP

#include <cassert>
#include <map>
#include <stdexcept>
#include <string>

#include <boost/any.hpp>

namespace azure_proxy {

class http_proxy_client_config {
    std::map<std::string, boost::any> config_map;
private:
    template<typename T>
    T get_config_value(const std::string& key) const {
        assert(!this->config_map.empty());
        auto iter = this->config_map.find(key);
        if (iter == this->config_map.end()) {
            throw std::invalid_argument("invalid argument");
        }
        return boost::any_cast<T>(iter->second);
    }
    http_proxy_client_config();
    bool load_config(const std::string& config_data);
public:
    bool load_config();
    const std::string& get_proxy_server_address() const;
    unsigned short get_proxy_server_port() const;
    const std::string& get_bind_address() const;
    unsigned short get_listen_port() const;
    const std::string& get_rsa_public_key() const;
    const std::string& get_cipher() const;
    unsigned int get_timeout() const;
    unsigned int get_workers() const;

    static http_proxy_client_config& get_instance();
};

} // namespace azure_proxy

#endif
