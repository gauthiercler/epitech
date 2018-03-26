#pragma once

#include "net.h"
#include <map>
#include <string>

namespace zia::api {
    namespace http {
        using Status = int;
        namespace common_status {
            enum {
                unknown,
                continue_                       = 100,
                switching_protocols             = 101,
                ok                              = 200,
                created                         = 201,
                accepted                        = 202,
                nonauthoritative_information    = 203,
                no_content                      = 204,
                reset_content                   = 205,
                partial_content                 = 206,
                multiple_choices                = 300,
                moved_permanently               = 301,
                found                           = 302,
                see_other                       = 303,
                not_modified                    = 304,
                use_proxy                       = 305,
                temporary_redirect              = 307,
                bad_request                     = 400,
                unauthorized                    = 401,
                payment_required                = 402,
                forbidden                       = 403,
                not_found                       = 404,
                method_not_allowed              = 405,
                not_acceptable                  = 406,
                proxy_authentication_required   = 407,
                request_timeout                 = 408,
                conflict                        = 409,
                gone                            = 410,
                length_required                 = 411,
                precondition_failed             = 412,
                request_entity_too_large        = 413,
                request_uri_too_large           = 414,
                unsupported_media_type          = 415,
                requested_range_not_satisfiable = 416,
                expectation_failed              = 417,
                im_a_teapot                     = 418,
                internal_server_error           = 500,
                not_implemented                 = 501,
                bad_gateway                     = 502,
                service_unavailable             = 503,
                gateway_timeout                 = 504,
                http_version_not_supported      = 505
            };
        }

        enum class Version {
            unknown, http_0_9, http_1_0, http_1_1, http_2_0
        };

        enum class Method {
            unknown, options, get, head, post, put, delete_, trace, connect
        };
    }

    /**
    * Represent a request.
    */
    struct HttpRequest {
        http::Version                      version;
        std::map<std::string, std::string> headers;
        Net::Raw                           body;

        http::Method method;
        std::string  uri;
    };

    /**
    * Represent a response.
    */
    struct HttpResponse {
        http::Version                      version;
        std::map<std::string, std::string> headers;
        Net::Raw                           body;

        http::Status status;
        std::string  reason;
    };

    /**
    * Represents all data concerning a request and its response during pipeline processing.
    */
    struct HttpDuplex {
        NetInfo      info;
        Net::Raw     raw_req;
        Net::Raw     raw_resp;
        HttpRequest  req;
        HttpResponse resp;
    };
}
