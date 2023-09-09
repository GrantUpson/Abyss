#pragma once

#include "utility/Utility.h"
#include "utility/Logger.h"


class BinaryDecoder {
public:
    explicit BinaryDecoder(uint32 size) : bufferSize(size), bufferOffset(0) {
        char* temp = static_cast<char*>(std::malloc(size));

        if(temp) {
            buffer = temp;
        } else {
            Logger::Log("Critical Error: Out of memory when attempting to create the buffer inside Binary Decoder");
        }
    }

    ~BinaryDecoder() { std::free(buffer); };

    // TODO Decoder currently only handles primitive types
    void Read(void* data, uint32 byteCount);

    template<typename T>
    void Read(T& data) {
        Read(&data, sizeof(data));
    }

    void Reset();
    char* GetBuffer();
    uint32 GetBufferSize() const;
    uint32 GetRemainingDataSize() const;

private:
    char* buffer;
    uint32 bufferSize;
    uint32 bufferOffset;
};


