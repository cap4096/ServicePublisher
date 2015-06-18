//
// Created by malo on 2015-06-18.
//

#include "DnsResolver.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

std::vector <std::shared_ptr<HostAddress>> DnsResolver::resolve(const std::string& node, const std::string& service)
{
    struct addrinfo* res = nullptr;
    std::vector <std::shared_ptr<HostAddress>> result;

    if(getaddrinfo(node.c_str(), service.c_str(), nullptr, &res)==0)
    {
       for (auto current = res; current != nullptr; current = current->ai_addr)
       {
            result.push_back(HostAddress(current));
       }
    }

    freeaddrinfo(res);

    return result;
}
