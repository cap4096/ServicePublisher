#ifndef SERVICEANNOUNCER_HOSTADDRESS_H
#define SERVICEANNOUNCER_HOSTADDRESS_H
#include <cstdint>
#include <vector>
#include <string>

extern "C" struct addrinfo;

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

