#include "Radio.h"
#include <iostream>

Radio::Radio() : radio() {}  // Constructor vacío, pins se configuran en begin()

bool Radio::begin(double freq) {
    int state = radio.begin(freq, 125.0, 5, 7, 0x12, 17, true);
    if(state != RADIOLIB_ERR_NONE) {
        std::cerr << "Error iniciando radio: " << state << std::endl;
        return false;
    }
    return true;
}

bool Radio::receive() {
    uint8_t buffer[256];
    int16_t state = radio.receive(buffer, sizeof(buffer));
    if(state == RADIOLIB_ERR_NONE) {
        std::cout << "Paquete recibido! RSSI: " << radio.getRSSI() << " dBm" << std::endl;
        return true;
    }
    return false;
}

