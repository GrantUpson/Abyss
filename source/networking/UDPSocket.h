#pragma once

#include "utility/Utility.h"
#include "SocketAddress.h"
#include "Packet.h"


class Socket {
public:
    Socket() = default;
    ~Socket();

    bool Open(uint16 port);
    void Close() const;

    bool Send(const SocketAddress& destination, const void* data, uint32 bufferSize) const;
    uint32 Receive(SocketAddress& sender, void* data, uint32 bufferSize) const;

private:
    int handle;
};