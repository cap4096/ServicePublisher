//
// Created by malo on 2015-06-18.
//

#ifndef SERVICEPUBLISHER_DNSRESOLVER_H
#define SERVICEPUBLISHER_DNSRESOLVER_H
#include "HostAddress.h"
#include <vector>
#include <string>

class DnsResolver
{
    static std::vector< std::shared_ptr<HostAddress> > resolve(const std::string& node, const std::string& service);
};


#endif //SERVICEPUBLISHER_DNSRESOLVER_H

