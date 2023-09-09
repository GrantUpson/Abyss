#include "Address.h"


Address::Address(uint8 a, uint8 b, uint8 c, uint8 d, uint16 port) {
    this->address = (a << 24) | (b << 16) | (c << 8) | d;
    this->port = port;
}


uint32 Address::GetAddress() const {
    return address;
}


uint8 Address::GetA() const {
    return (address >> 8) & 0xFF;
}


uint8 Address::GetB() const {
    return (address >> 16) & 0xFF;
}


uint8 Address::GetC() const {
    return (address >> 24) & 0xFF;
}


uint8 Address::GetD() const {
    return (address) & 0xFF;
}


uint16 Address::GetPort() const {
    return port;
}
