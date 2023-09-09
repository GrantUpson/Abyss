#include "Packet.h"


void ToggleGodmodePacket::Serialize(BinaryEncoder &encoder) {
    encoder.Write(opcode);
    encoder.Write(playerId);
}


void ToggleGodmodePacket::Deserialize(BinaryDecoder &decoder) {
    decoder.Read(opcode);
    decoder.Read(playerId);
}


void ChatMessagePacket::Serialize(BinaryEncoder &encoder) {
    encoder.Write(opcode);
    encoder.Write(message);
}


void ChatMessagePacket::Deserialize(BinaryDecoder &decoder) {
    decoder.Read(opcode);
    decoder.Read(message);
}


