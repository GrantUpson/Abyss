#pragma once

#include <string>
#include <utility/Utility.h>


// Currently only supports IPV4
class NetworkingUtilities {
public:
    static bool IsValidIPAddress(std::string& ipAddress);
    static uint32 StringToIPAddress(std::string& stringIPAddress);
    static std::string ResolveDomainName(std::string& name);
};



