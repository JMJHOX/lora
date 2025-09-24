#include <iostream>
#include "Radio.h"

int main() {
    Radio myRadio;

    if (!myRadio.begin()) {
        std::cout << "Error inicializando el radio!" << std::endl;
        return 1;
    }
    std::cout << "Radio iniciado correctamente." << std::endl;

    while (true) {
        if (myRadio.receive()) {
            int16_t rssi = myRadio.getRSSI();
            std::cout << "Paquete recibido! RSSI: " << rssi << " dBm" << std::endl;
        }
    }

    return 0;
}

