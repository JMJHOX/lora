#include "MyRadio.h"
#include <iostream>



bool MyRadio::begin() {


    // Inicialización segura: 433 MHz, SF7, BW 125 kHz
    int state = radio.begin(433.0, 125.0, 5, 7, 0x12, 17, true);
    if(state != RADIOLIB_ERR_NONE){
        std::cerr << "Error inicializando radio: " << state << std::endl;
        return false;
    }

    std::cout << "Radio inicializado correctamente en 433 MHz." << std::endl;
    return true;
}

bool MyRadio::receive() {
    uint8_t buffer[64]; // Buffer seguro
    int16_t state = radio.receive(buffer, sizeof(buffer));

    if(state == RADIOLIB_ERR_NONE){
        std::cout << "Paquete recibido! RSSI: " << radio.getRSSI() << " dBm" << std::endl;
        return true;
    } else if(state != RADIOLIB_ERR_RX_TIMEOUT) {
        std::cerr << "Error recibiendo paquete: " << state << std::endl;
    }

    return false;
}
