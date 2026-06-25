#pragma once

#include <cstdint>
#include <cstddef>

namespace Drivers
{
    class Uart
    {
    public:
        void init();

        bool isTxReady() const;
        bool isRxReady() const;

        void writeByte(uint8_t byte);
        void write(const uint8_t* data, std::size_t length);

        uint8_t readByte();
        
    private:
    };
}