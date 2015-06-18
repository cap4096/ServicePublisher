//
// Created by malo on 2015-06-17.
//
#include "HostAddress.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

std::vector<HostAddress> HostAddress::fromAddrInfo(const struct addrinfo& addrInfo)
{
    return fromAddrInfo(&addrInfo);
}

std::vector<HostAddress> HostAddress::fromAddrInfo(const struct addrinfo* addrInfo)
{
    std::vector<HostAddress> result;

    while(addrInfo)
    {
        result.push_back( HostAddress( addrInfo ) );
        addrInfo = addrInfo->ai_next;
    }

    return result;
}

HostAddress::HostAddress(const addrinfo* addrInfo)
{
    if(addrInfo)
    {
        m_addressFamily = addrInfo->ai_family;
        m_protocolFamily = addrInfo->ai_protocol;
        m_socketType = addrInfo->ai_socktype;

        size_t sz = 0;

        switch(m_addressFamily)
        {
            case AF_INET:
                sz = sizeof(sockaddr_in);
                break;

            case AF_INET6:
                sz = sizeof(sockaddr_in6);
                break;

            default:
                break;
        }
        memset(&m_sockBuffer, 0, sz);
        memcpy(&m_sockBuffer, addrInfo->ai_addr, sz );
    }
}

std::string HostAddress::toString() const
{
    char buffer[128];
    std::string result;

    switch(m_addressFamily)
    {
        case AF_INET:
            result = std::string(
                    inet_ntop(AF_INET,
                              ((struct sockaddr_in*)&m_sockBuffer))->sin_addr, buffer, sizeof(buffer));
            break;

        case AF_INET6:
            result = std::string(
                    inet_ntop(AF_INET6,
                              ((struct sockaddr_in6*)&m_sockBuffer))->sin6_addr, buffer, sizeof(buffer));
            break;

        default:
            result = std::string("Unknown address type");
    }

    return result;
}
