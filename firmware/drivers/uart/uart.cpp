#include "uart.hpp"

// Hardware specific implementation
// For now this is a stub used for template validation

void Drivers::Uart::init() {
    // Initialize UART hardware here
}

void Drivers::Uart::writeByte(uint8_t c) {

    (void)c;

    while (1) {
        // Wait until transmit data register is empty
    }

    // Write the byte to the transmit data register
}

