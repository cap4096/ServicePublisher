//
// Created by malo on 2015-06-17.
//

#ifndef SERVICEANNOUNCER_HOSTADDRESS_H
#define SERVICEANNOUNCER_HOSTADDRESS_H
#include <cstdint>
#include <vector>

extern "C" struct addrinfo;
extern "C" struct sockaddr;


enum class ProtocolFamily : int
{
    UNSPEC = 0,         // Unspecified.
    LOCAL = 1,          // Local to host (pipes and file-domain).
    UNIX = LOCAL,		// POSIX name for PF_LOCAL.
    FILE = LOCAL,       // Another non-standard name for PF_LOCAL.
    INET = 2           // IP protocol family.
    INET6 = 10
};


enum class AddressFamily : int
{
    UNSPEC = ProtocolFamily::UNSPEC,
    LOCAL = ProtocolFamily::LOCAL,
    UNIX = ProtocolFamily::UNIX,
    FILE = ProtocolFamily::FILE,
    INET = ProtocolFamily::INET,
    INET6 = ProtocolFamily::INET6
};




class HostAddress
{
public:
    static std::vector<HostAddress> fromAddrInfo(const struct addrinfo& addrInfo);
    static std::vector<HostAddress> fromAddrInfo(const struct addrinfo* addrInfo);

    HostAddress(const HostAddress& rhs) = default;
    HostAddress(const addrinfo* addrInfo);

    int getProtocolFamily() const { return m_protocolFamily; }
    int getAddressFamily() const  { return m_addressFamily;}
    int getSocketType() const     { return m_socketType; }


    std::string toString() const;

private:
    std::uint32_t m_sockBuffer[16];
    int m_protocolFamily = 0;
    int m_addressFamily = 0;
    int m_socketType = 0;
};


#endif //SERVICEANNOUNCER_HOSTADDRESS_H

