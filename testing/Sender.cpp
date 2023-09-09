#include "Sender.h"
#include "utility/Utility.h"
#include "networking/Socket.h"
#include "networking/Packet.h"
#include "networking/BinaryEncoder.h"
#include <iostream>


void Sender::execute() {
    const uint16 port = 44888;

    Socket socket {};

    if(!socket.Open(port)) {
        std::cout << "Sender cannot open socket" << std::endl;
    }

    ToggleGodmodePacket packet;
    packet.opcode = Opcode::TOGGLE_GOD_MODE;
    packet.playerId = 2;

    BinaryEncoder encoder;

    packet.Serialize(encoder);

    std::cout << "Buffer: " << encoder.GetBuffer() << std::endl;
    socket.Send(Address(120, 148, 206, 219, port), encoder.GetBuffer(), encoder.GetPayloadSize());
}
