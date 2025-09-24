#ifndef RADIO_H
#define RADIO_H

#include "../../RadioLib/src/RadioLib.h"
#include "../../RadioLib/src/modules/SX127x/SX1278.h"

class Radio {
public:
    Radio();
    bool begin();      // Inicializa el radio
    bool receive();    // Intenta recibir un paquete y muestra RSSI

private:
    SX1278 radio;
};

#endif

