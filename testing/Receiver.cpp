#include <iostream>
#include "Receiver.h"
#include "networking/Socket.h"
#include "networking/Packet.h"


void Receiver::execute() {
    const uint16 port = 44888;
    Socket socket {};

    if(!socket.Open(port)) {
        std::cout << "Receiver cannot open socket" << std::endl;
    }

    std::cout << "Receiver started and listening.." << std::endl;

    BinaryDecoder decoder(MAX_PACKET_SIZE);

    while(true) {
        Address sender {};
        uint32 receivedBytes = socket.Receive(sender, decoder.GetBuffer(), decoder.GetBufferSize());

        if(receivedBytes > 0) {
            Opcode opcode {};
            decoder.Read(opcode);
            decoder.Reset();

            switch(opcode) {
                case NONE:
                case TOGGLE_GOD_MODE: {
                    ToggleGodmodePacket godmodePacket {};
                    godmodePacket.Deserialize(decoder);

                    std::cout << "Opcode: " << godmodePacket.opcode << " for player with ID: " << godmodePacket.playerId << std::endl;
                }

                case CHAT_MESSAGE: {
                    std::cout << "Chat Message Packet" << std::endl;
                }
            }
        }
    }
}
