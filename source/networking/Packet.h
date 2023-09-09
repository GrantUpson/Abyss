#pragma once

#include "utility/Utility.h"
#include "Opcodes.h"
#include "BinaryEncoder.h"
#include "BinaryDecoder.h"


const uint32 PROTOCOL_ID = 4114558895;
const uint32 MAX_PACKET_SIZE = 520;

struct Packet {
    Opcode opcode {};
};


struct ToggleGodmodePacket : public Packet {
    uint16 playerId {};

    void Serialize(BinaryEncoder& encoder);
    void Deserialize(BinaryDecoder& decoder);
};


struct ChatMessagePacket : public Packet {
    char* message[64] {};

    void Serialize(BinaryEncoder& encoder);
    void Deserialize(BinaryDecoder& decoder);
};



