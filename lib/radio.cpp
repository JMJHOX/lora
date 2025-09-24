#include "Radio.h"
#include <iostream>

Radio::Radio() : radio(nullptr) {} // Constructor vacío con puntero nulo

bool Radio::begin() {
    // Configuración típica para 433 MHz: BW=125 kHz, CR=5, SF=7, SyncWord=0x12, Power=17 dBm, CRC=true
    int state = radio.begin(433.0, 125.0, 5, 7, 0x12, 17, true);
    if(state != RADIOLIB_ERR_NONE){
        std::cerr << "Error inicializando radio: " << state << std::endl;
        return false;
    }
    std::cout << "Radio inicializado correctamente en 433 MHz." << std::endl;
    return true;
}

bool Radio::receive() {
    uint8_t buffer[256];
    int16_t state = radio.receive(buffer, sizeof(buffer)); // timeout opcional
    if(state == RADIOLIB_ERR_NONE){
        std::cout << "Paquete recibido! RSSI: " << radio.getRSSI() << " dBm" << std::endl;
        return true;
    }
    return false;
}

