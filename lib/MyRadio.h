#ifndef MYRADIO_H
#define MYRADIO_H

#include "../../RadioLib/src/RadioLib.h"
#include "../../RadioLib/src/modules/SX127x/SX1278.h"

class MyRadio {
public:
    MyRadio();
    bool begin();      // Inicializa el radio
    bool receive();    // Intenta recibir un paquete y muestra RSSI

private:
    SX1278 radio;
};

#endif

