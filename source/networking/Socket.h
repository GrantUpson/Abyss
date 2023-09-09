#pragma once

#include "utility/Utility.h"
#include "Address.h"
#include "Packet.h"


class Socket {
public:
    Socket() = default;
    ~Socket();

    bool Open(uint16 port);
    void Close() const;

    bool Send(const Address& destination, const void* data, uint32 bufferSize) const;
    uint32 Receive(Address& sender, void* data, uint32 bufferSize) const;

private:
    int handle;
};