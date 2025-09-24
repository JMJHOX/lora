#include "MyRadio.h"
#include <iostream>

MyRadio::MyRadio() : radio(nullptr) {}

bool MyRadio::begin() {
    int state = radio.begin(433.0, 125.0, 5, 7, 0x12, 17, true);
    if(state != RADIOLIB_ERR_NONE){
        std::cerr << "Error inicializando radio: " << state << std::endl;
        return false;
    }
    std::cout << "Radio inicializado correctamente en 433 MHz." << std::endl;
    return true;
}

bool MyRadio::receive() {
    uint8_t buffer[256];
    int16_t state = radio.receive(buffer, sizeof(buffer));
    if(state == RADIOLIB_ERR_NONE){
        std::cout << "Paquete recibido! RSSI: " << radio.getRSSI() << " dBm" << std::endl;
        return true;
    }
    return false;
}

