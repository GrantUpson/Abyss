#pragma once

#include "utility/Utility.h"



class Address {
public:
    Address() = default;
    Address(uint8 a, uint8 b, uint8 c, uint8 d, uint16 port);
    Address(uint32 address, uint16 port) : address(address), port(port) {};

    uint32 GetAddress() const;
    uint8 GetA() const;
    uint8 GetB() const;
    uint8 GetC() const;
    uint8 GetD() const;
    uint16 GetPort() const;

private:
    uint32 address;
    uint16 port;
};



