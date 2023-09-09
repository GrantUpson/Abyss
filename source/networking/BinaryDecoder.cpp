#include "BinaryDecoder.h"
#include "utility/Logger.h"


void BinaryDecoder::Read(void* data, uint32 byteCount) {
    uint32 nextOffset = bufferOffset + byteCount;
    std::memcpy(data, (buffer + bufferOffset), byteCount);
    bufferOffset = nextOffset;
}


void BinaryDecoder::Reset() {
    bufferOffset = 0;
}


char* BinaryDecoder::GetBuffer() {
    return buffer;
}


uint32 BinaryDecoder::GetBufferSize() const {
    return bufferSize;
}


uint32 BinaryDecoder::GetRemainingDataSize() const {
    return bufferSize - bufferOffset;
}
