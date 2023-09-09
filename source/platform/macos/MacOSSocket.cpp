#include "networking/Socket.h"
#include "utility/Logger.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>


bool Socket::Open(uint16 port) {
    handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(handle <= 0) {
        //Logger::Log("Failed to open a socket on port " + std::to_string(port));
        std::cout << "Failed to open a socket on port " + std::to_string(port) << std::endl;
        return false;
    }

    sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(handle, (const sockaddr*)&address, sizeof(sockaddr_in)) < 0) {
        //Logger::Log("Failed to bind a UDP socket on port " + std::to_string(port));
        std::cout << "Failed to bind a UDP socket on port " + std::to_string(port) << std::endl;
        return false;
    }

    if(fcntl(handle, F_SETFL, O_NONBLOCK, 1) == -1) {
        //Logger::Log("Failed to set socket non-blocking");
        std::cout << "Failed to set UDP socket non-blocking " << std::endl;
        return false;
    }

    return true;
}


void Socket::Close() const {
    close(handle);
}


bool Socket::Send(const Address& destination, const void* data, uint32 bufferSize) const {
    sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(destination.GetAddress());
    address.sin_port = htons(destination.GetPort());

    size_t sentBytes = sendto(handle, data, bufferSize, 0, (sockaddr*)&address, sizeof(sockaddr_in));

    if(sentBytes != bufferSize) {
        Logger::Log("Failed to send a packet to " + std::to_string(destination.GetAddress()));
        return false;
    } else {
        return true;
    }
}


// TODO Determine if sender information is required for anything.
uint32 Socket::Receive(Address& sender, void* data, uint32 bufferSize) const {
    sockaddr_in from {};
    socklen_t fromLength = sizeof(from);

    uint32 bytes = recvfrom(handle, data, bufferSize, 0, (sockaddr*)&from, &fromLength);
    uint32 fromAddress = ntohl(from.sin_addr.s_addr);
    uint16 fromPort = ntohs(from.sin_port);

    if(bytes == -1) {
        bytes = 0;
    }

    return bytes;
}


Socket::~Socket() {
    Close(); 
}