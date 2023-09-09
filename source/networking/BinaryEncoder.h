#pragma once

#include "utility/Utility.h"


class BinaryEncoder {
public:
    BinaryEncoder() : buffer(nullptr), bufferSize(0), bufferOffset(0) { ResizeBuffer(32); };
    ~BinaryEncoder() { std::free(buffer); };

    //TODO Currently only handles primitive types
    void Write(const void* data, uint32 byteCount);

    template<typename T>
    void Write(T data) {
        Write(&data, sizeof(data));
    }

    void Reset();
    const char* GetBuffer() const;
    uint32 GetPayloadSize() const;

private:
    char* buffer;
    uint32 bufferSize;
    uint32 bufferOffset;

    void ResizeBuffer(uint32 newSize);
};


