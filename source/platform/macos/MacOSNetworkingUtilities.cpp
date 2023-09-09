#include <regex>
#include "networking/NetworkingUtilities.h"
#include <arpa/inet.h>


bool NetworkingUtilities::IsValidIPAddress(std::string& ipAddress) {
    const std::regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");

    if (regex_match(ipAddress, ipv4)) { return true; }
    else { return false; }
}


uint32 NetworkingUtilities::StringToIPAddress(std::string& stringIPAddress) {
    struct in_addr addr {};
    inet_pton(AF_INET, stringIPAddress.c_str(), &addr);

    return ntohl(addr.s_addr);
}


std::string NetworkingUtilities::ResolveDomainName(std::string& name) {
    //TODO Complete ResolveDomainName for MacOS
    return "";
}