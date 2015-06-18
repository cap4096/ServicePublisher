//
// Created by malo on 2015-06-18.
//

#include "DnsResolver.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

std::vector<HostAddress> DnsResolver::resolve(const std::string& node, const std::string& service)
{
    struct addrinfo* res = nullptr;

    if(getaddrinfo(node.c_str(), service.c_str(), nullptr, &res)==0)
    {
        return std::vector<HostAddress>();
    }

    auto result = HostAddress::fromAddrInfo(res);
    freeaddrinfo(res);

    return result;
}
