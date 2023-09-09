#include "BinaryEncoder.h"
#include "utility/Logger.h"
#include <iostream>


void BinaryEncoder::Write(const void *data, uint32 byteCount) {
    uint32 nextOffset = bufferOffset + byteCount;

    if(nextOffset > bufferSize) {
        ResizeBuffer(std::max(bufferSize * 2, nextOffset));
    }

    std::cout << "Size of write: " << byteCount << std::endl;
    std::memcpy(buffer + bufferOffset, data, byteCount);
    bufferOffset = nextOffset;
}


void BinaryEncoder::Reset() {
    bufferOffset = 0;
}


const char* BinaryEncoder::GetBuffer() const {
    return buffer;
}


uint32 BinaryEncoder::GetPayloadSize() const {
    return bufferOffset;
}


void BinaryEncoder::ResizeBuffer(uint32 newSize) {
    char* temp = static_cast<char*>(std::realloc(buffer, newSize));

    if(temp) {
        buffer = temp;
        bufferSize = newSize;
    } else {
        Logger::Log("Error: Out of memory when attempting to resize the buffer inside Binary Encoder");
    }
}
